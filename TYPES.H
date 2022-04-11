/*
Name:       Soren Bradley, Joe Spurway
Email:      sbrad910@mtroyal.ca
Course:     COMP 2659-001
Semester:   Winter 2022
Instructor: Paul Pospisil

Project: Puals Astro Golf Adventure (Paga)

File: TYPES.H

Purpose: Generic file holding the type definitions for our game
*/
#ifndef TYPES_H
#define TYPES_H

#define BITMAP_SIZE_32 32
#define BITMAP_SIZE_16 16
#define BITMAP_SIZE_8 8

#define SCREEN_HEIGHT 400
#define SCREEN_WIDTH 640

typedef unsigned char UINT8;
typedef unsigned int  UINT16;
typedef unsigned long UINT32;

typedef unsigned short bearing;
typedef unsigned short bool;

/* wont work for higer order due to operations */
/* typedef double UINT64; */
/* typedef long double UINT128;*/

#endif
