/*
Name:       Soren Bradley, Joe Spurway
Email:      sbrad910@mtroyal.ca
Course:     COMP 2659-001
Semester:   Winter 2022
Instructor: Paul Pospisil

Project: Puals Astro Golf Adventure (Paga)

File: ISR.H

*/
#ifndef ISR_H
#define ISR_H

#include "ISR_ASM.H"
#include "SUPER.H"

#define VBL_ISR 28
#define IKBD_ISR 70 /* IKBD ISR is located at vector 70 */

typedef void (*Vector) (); /* a vector is a function start address */

Vector installVector(int, Vector);
int maskInterrupt(int);

#endif