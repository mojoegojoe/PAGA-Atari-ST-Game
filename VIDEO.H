/*
Name:       Soren Bradley, Joe Spurway
Email:      sbrad910@mtroyal.ca
Course:     COMP 2659-001
Semester:   Winter 2022
Instructor: Paul Pospisil

Project: Puals Astro Golf Adventure (Paga)

File: VIDEO.H

*/
#ifndef INPUTASM_H
#define INPUTASM_H

#include "types.h"
#include "DEFINES.H"
#include "SUPER.H"

#define HIGH_REGISTER 0x00FF8201
#define MID_REGISTER 0x00FF8203

void setVBAsm(UINT16);
UINT32* getVideoBase();
void setVideoBase(UINT32*);

#endif
