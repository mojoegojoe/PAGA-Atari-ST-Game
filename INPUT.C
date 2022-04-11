/*
Name:       Soren Bradley, Joe Spurway
Email:      sbrad910@mtroyal.ca
Course:     COMP 2659-001
Semester:   Winter 2022
Instructor: Paul Pospisil

Project: Puals Astro Golf Adventure (Paga)

File: INPUT.C

Purpose: High level wrapper for the IKBD handling that ensures that interfacing with the IKBD is clean
*/
#include "INPUT.H"

/**
 * input_available
 * Checks if the key buffer has any input from the ikbd
 * @return 0 if no input
 */
UINT8 input_available() {
    UINT8 inputPending;
    int oldIpl;
    oldIpl = maskInterrupt(7);
    inputPending = !isEmpty();
    maskInterrupt(oldIpl);
    return inputPending;
}

/**
 *  read_char()
 *  Gets the charactor from the keybuffer.
 *  It should be noted that this function should only be used after checking
 *  if the keyBuffer has a value to return.
 * @return the first available ascii charactor in the keyBuffer Queue
 */
UINT8 read_char() {
    UINT8 keymap;
    int oldIpl;
    oldIpl = maskInterrupt(7);
    keymap = top_buffer_value() >> SHIFT_BY_WORD;
    maskInterrupt(oldIpl);
    return keymap;
}



