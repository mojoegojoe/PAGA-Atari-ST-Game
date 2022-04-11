/*
Name:       Soren Bradley, Joe Spurway
Email:      sbrad910@mtroyal.ca
Course:     COMP 2659-001
Semester:   Winter 2022
Instructor: Paul Pospisil

Project: Puals Astro Golf Adventure (Paga)

File: ISR.C

Purpose: Contaions the functions for installing custom isrs and functions for masking interupts
*/
#include "isr.h"
/**
 *  installVector
 *  Allows the caller to install a custom isr replacing the stock tos
 *  isr's.
 * @param num The number of the vector that with be replaced
 * @param vector The vector address to install
 * @return The vector that was replaced (returned so it can be restored)
 */
Vector installVector(int num, Vector vector)
{
    Vector orig;
    Vector *vectp = (Vector*) ((long) num << 2);
    long oldSsp = on_super(0);
    
    orig = *vectp;
    *vectp = vector;
    
    off_super(oldSsp);
    return orig;
}
/**
 * maskInterrupt
 * changes the ipl mask to a given value
 *
 * Note: Needs to be run in supervisor mode
 *
 * @param mask the value to set the new ipl to (must be between 0-7)
 * @return the old IPL mask is replacing
 */
int maskInterrupt(int mask)
{
    int oldIpl;
    long oldSsp;
    
    oldSsp = on_super(0);
    oldIpl = setipl(mask);
    off_super(oldSsp);
    
    return oldIpl;
}