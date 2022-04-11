/*
Name:       Soren Bradley, Joe Spurway
Email:      sbrad910@mtroyal.ca
Course:     COMP 2659-001
Semester:   Winter 2022
Instructor: Paul Pospisil

Project: Puals Astro Golf Adventure (Paga)

File: IKBD.C

Purpose: Handles the IKBD for the game input.

ASIDE: You might wonder, why no auto key repeat?
 This is mostly becuase there are 12 inputs for angle and 10 for power level. We could have done something
 with same a key repeat of 4-5 but it would pull the user away from making fine adjustments and trying
 play with the mechanics of the game and thinking about their movements
*/
#include "IKBD.H"


struct Buffer keyBuffer =
        {
                {0},
                1,
                0,
                0,
        };
struct _Mouse mouse = {
        MOUSE_DEFAULT_X_POS,
        MOUSE_DEFAULT_Y_POS
};

volatile UINT8 *const control = CTRL; /* IKBD control register */
volatile const UINT8 *const status = SR; /*IKBD status register, const because its read only */
volatile const UINT8 *const rdr = RDR; /*IKBD received register, const because its read only */
volatile UINT8 *const ascii_table = ASCII_TABLE_START;
UINT8 fsm_state = 0;

/**
 * read_key()
 *
 * Adapted from Lab6, this function is ment to be called from the ikbd isr, hence why it doesn't take in parameters
 * and relies on global variables.
 *
 * reads from the IKBD received register and converts the scancode into a ascii value then places the value on to the
 * keyBuffer so it can be retrieved by other resources.
 *
 * handles mouse input by using a finite state machine that changes states based off the value of the scan code provided by the
 * IKBD recieved register.
 *
 *  if scan code is a key and state is 0
 *      check if its a mouse packet
 *          is a mouse packet
 *              convert scancode to ascii value
 *          else (is a mouse packet)
 *              convert scancode to ascii value
 *              change state to 1
 *      after place it into the keyBuffer structure
 *  if state is 1 (grab the x position of the mouse)
 *      mouse x position = input
 *      change state to 2
 *  if state is 2 (grab the y position of the mouse)
 *      mouse y position = input
 *      change state to 0 (reset finite state machine)
 *
 */
void read_key() {
    UINT8 interruptStatus = *status;
    UINT8 input;
    UINT32 scancode;
    input = *rdr;
    interruptStatus &= MSB_8;
    if (interruptStatus != SR_ON) {
        while (TRUE);
    } else {
        if (fsm_state == FSM_INIT_STATE) /* if we're not midway through a mouse triplet */
        {
            if (input < MOUSE_GUARD) {
                if ((input & MSB_8) != BREAK) /* could it be a make code key? */
                {
                    scancode = (((UINT32) input) << SHIFT_BY_WORD) | ascii_value(input);
                }
            } else {
                scancode = ((UINT32) input) << SHIFT_BY_WORD;
                fsm_state++;
            }
            keyBuffer.tail += 1;
            keyBuffer.buffer[keyBuffer.tail] = scancode;
            keyBuffer.fill++;
        } else {
            if (fsm_state == FSM_MOUSE_PACKET_X_POS) {
                mouse.posX += (int) ((signed char) input);
                if (mouse.posX > MOUSE_X_BOUNDARY) {
                    mouse.posX = MOUSE_X_BOUNDARY;
                } else if (mouse.posX < MOUSE_BOUNDARY_ZERO) {
                    mouse.posX = MOUSE_BOUNDARY_ZERO;
                }
                fsm_state++;
            } else if (fsm_state >= FSM_MOUSE_PACKET_Y_POS) {
                mouse.posY += (int) ((signed char) input);
                if (mouse.posY > MOUSE_Y_BOUNDARY) {
                    mouse.posY = MOUSE_Y_BOUNDARY;
                } else if (mouse.posY < MOUSE_BOUNDARY_ZERO) {
                    mouse.posY = MOUSE_BOUNDARY_ZERO;
                }
                fsm_state = FSM_INIT_STATE;
            }

        }
    }
}

/**
 * ascii_value retrieves the ascii value of a keymap from the ikbd
 *  Uses the atari internal keytbl address to get the correct value
 * @param keymap value from the ikbd
 * @return the ascii representation of the keymap
 */
UINT8 ascii_value(UINT8 keymap) {
    if (keymap >= ASCII_TABLE_SIZE) {
        return 0;
    } else {
        return (UINT8) *(ascii_table + keymap);
    }
}

/**
 * top_buffer_value, gets the next candidate from the queue
 * @return the value of the keypress in the keyBuffer
 */
UINT32 top_buffer_value() {
    UINT32 ch = keyBuffer.buffer[keyBuffer.head];
    keyBuffer.head += 1;
    keyBuffer.fill--;
    return ch;
}

/**
 * IsEmpty
 * check if there is anything in the keyBuffer
 * @return 0 if keybuffer is empty
 */
UINT8 isEmpty() {
    return (UINT8) !keyBuffer.fill;
}


