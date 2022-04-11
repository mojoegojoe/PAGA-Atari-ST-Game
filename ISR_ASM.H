/*
Name:       Soren Bradley, Joe Spurway
Email:      sbrad910@mtroyal.ca
Course:     COMP 2659-001
Semester:   Winter 2022
Instructor: Paul Pospisil

Project: Puals Astro Golf Adventure (Paga)

File: ISR_ASM.C

Purpose: Wrapper for ISR_ASM.S assembly file
*/
#ifndef ISRASM_H
#define ISRASM_H

void vblisr();
void ikbdisr();
int setipl(int); /* must be called from supervisor mode */

#endif
