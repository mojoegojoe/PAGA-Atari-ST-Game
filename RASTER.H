/*
Name:       Soren Bradley, Joe Spurway
Email:      sbrad910@mtroyal.ca
Course:     COMP 2659-001
Semester:   Winter 2022
Instructor: Paul Pospisil

Project: Puals Astro Golf Adventure (Paga)

File: RASTER.H

*/
#ifndef RASTER_H
#define RASTER_H

#include "types.h"
#include "DEFINES.H"
#include "RAST_ASM.h"



/**clear:
    _screen - full screen 
    _mapbox - mapbox only screen
    _statbox- statbox only screen
**/

void clean_screen(UINT32*);
void print_screen(UINT8*, UINT32*);

void plot_bitmap_8(UINT8*, int, int, UINT8*, UINT16);
void clear_bitmap_8(UINT8*, int, int, UINT16);
void plot_bitmap_16(UINT16*, int, int, UINT16*, UINT16);
void plot_bitmap_16_unsafe(UINT16*, int, int, UINT16*, UINT16);
void plot_bitmap_32(UINT32*, int, int, UINT32*, UINT16);

/*
game:
    _ball - plots the ball bitmap object at a defined x/y postion
    _wall - plots the wall object between two x/y postions 
    etc.
*/
void plot_text(UINT8 *, int, int, const UINT8 **, UINT8);
void plot_number(UINT8 *, int, int, const UINT8 **, UINT8);

#endif
