/*
Name:       Soren Bradley, Joe Spurway
Email:      sbrad910@mtroyal.ca
Course:     COMP 2659-001
Semester:   Winter 2022
Instructor: Paul Pospisil

Project: Puals Astro Golf Adventure (Paga)

File: PAGA.H

*/
#ifndef PAGA_H
#define PAGA_H

#include "TYPES.H"
#include "DEFINES.H"
#include "MODEL.H"
#include "INPUT.H"
#include "MODEL.H"
#include "EVENTS.H"
#include "RENDERER.H"
#include "ISR.H"
#include "IKBD.H"
#include "VIDEO.H"
#include <string.h>

/**#include "EFFECTS.H"
#include "MUSIC.H"**/

#define WPRESS 0x11
#define SPRESS 0x1F
#define APRESS 0x1E
#define DPRESS 0x20
#define RETRY 0x13

#define LEFT_CLICK 0xFA
#define LMB_RMB_CLICK 0xFB

#define SPACE 0x39
#define QUIT 0x10


#define TIMER 0x462

#define FALSE 0
#define TRUE 1

#define MAX_SHOTS 50

#define ACTIVATE 1
#define NOT_ACTIVE 0

#define NOT_PRESSED 0
#define PRESSED 1

#define START_OPTION_POSX 150
#define START_OPTION_POSY 335
#define START_OPTION_WIDTH 150
#define START_OPTION_HEIGHT 65

#define RETRY_OPTION_POSX 150
#define RETRY_OPTION_POSY 335
#define RETRY_OPTION_WIDTH 150
#define RETRY_OPTION_HEIGHT 65

#define QUIT_OPTION_POSX 350
#define QUIT_OPTION_POSY 335
#define QUIT_OPTION_WIDTH 150
#define QUIT_OPTION_HEIGHT 65

#define HOLE_NOT_HIT 0

#define SYNC_START_SCREEN 0
#define SYNC_GAME 1
#define SYNC_END_SCREEN 2



extern UINT8 sync_mode;
extern UINT8 renderRequest;
extern UINT8 secondaryBuffer[32256];
extern UINT8 thirdBuffer[32000];
extern struct _Model model;
extern struct _StartScreen start;
extern struct _EndScreen end;

void start_game_menu(UINT32 *bfrPtrs[]);
void game(UINT32 *bfrPtrs[]);
void end_game_menu(UINT32 *bfrPtrs[]);
void handle_start_menu_async();
void handle_game_async();
void handle_end_menu_async();
void handle_sync();



#endif