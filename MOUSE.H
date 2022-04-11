/*
Name:       Soren Bradley, Joe Spurway
Email:      sbrad910@mtroyal.ca
Course:     COMP 2659-001
Semester:   Winter 2022
Instructor: Paul Pospisil

Project: Puals Astro Golf Adventure (Paga)

File: MOUSE.H

Purpose: Contains the model for the mouse, it is seperate from the model.h becuase IKBD needs it but including all of model in IKBD seemed like overkill
*/
#ifndef MOUSE_H_
#define MOUSE_H_

#define MOUSE_DEFAULT_X_POS 320
#define MOUSE_DEFAULT_Y_POS 300

typedef struct _Mouse {
    int posX, posY;
} Mouse;

#endif

