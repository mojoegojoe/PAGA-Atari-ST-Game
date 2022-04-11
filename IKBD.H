/*
Name:       Soren Bradley, Joe Spurway
Email:      sbrad910@mtroyal.ca
Course:     COMP 2659-001
Semester:   Winter 2022
Instructor: Paul Pospisil

Project: Puals Astro Golf Adventure (Paga)

File: IKBD.H

*/


#ifndef IKBD_H
#define IKBD_H

#include "input.h"
#include "isr.h"
#include "types.h"
#include "DEFINES.H"
#include "MOUSE.H"

#define TRUE 1
#define FALSE 0

#define ASCII_TABLE_SIZE 0x73

#define CTRL 0x00FFFC00    /* IKBD Control register (byte array)*/
#define SR 0x00FFFC00  /* IKBD Status Register (byte array)*/
#define RDR 0x00FFFC02 /* keyboard receive data register */
#define SR_ON 0x80
#define ASCII_TABLE_START 0xFFFE829C
#define MSB_8 0x80 /* MSB of a byte */
#define BREAK 0x80
#define MOUSE_GUARD 0xF8

#define MOUSE_BOUNDARY_ZERO 0
#define MOUSE_X_BOUNDARY 632
#define MOUSE_Y_BOUNDARY 392

#define FSM_INIT_STATE 0
#define FSM_MOUSE_PACKET_X_POS 1
#define FSM_MOUSE_PACKET_Y_POS 2

struct Buffer
{
    UINT32 buffer[256];
    UINT8 head;
    UINT8 tail;
    UINT16 fill;
};

extern struct Buffer keyBuffer;
extern struct _Mouse mouse;

extern UINT8 fsm_state;

/* function prototypes */


void read_key();
UINT8 ascii_value(UINT8 keymap);
void enqueue(UINT32 value);
UINT32 top_buffer_value();
UINT8 isEmpty();


#endif

