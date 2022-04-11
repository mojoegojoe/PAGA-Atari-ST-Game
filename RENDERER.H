/*
Name:       Soren Bradley, Joe Spurway
Email:      sbrad910@mtroyal.ca
Course:     COMP 2659-001
Semester:   Winter 2022
Instructor: Paul Pospisil

Project: Puals Astro Golf Adventure (Paga)

File: RENDERER.H

*/
#ifndef RENDERER_H
#define RENDERER_H

#include "TYPES.H"
#include "DEFINES.H"
#include "BITMAPS.H"
#include "RASTER.H"
#include "MODEL.H"
#include "SCREEN.H"
#include "MOUSE.H"

#define POWER_INDICATOR_HEIGHT 16
#define CLEAR_BITMAP_16 16
#define FONT_HEIGHT 8
#define BITMAP_SIZE_16 16
#define WALL_HEIGHT 16
#define PORTAL_HEIGHT 16
#define GROUND_HEIGHT 16
#define HOLE_HEIGHT 16
#define DIRECTION_POINTER_HEIGHT 16
#define POWER_BAR_IND_ON 1


#define PORTAL_DEACTIVATED 0
#define TEXT_NUMBER_SIZE 8
#define TEXT_NUMBER_OFFSET_BY_ONE 16
#define TEXT_NUMBER_OFFSET_BY_TWO 24

#define NORTH_ARROW 0
#define NORTH_NORTH_EAST_ARROW 1
#define NORTH_EAST_EAST_ARROW 2
#define EAST_ARROW 3
#define SOUTH_NORTH_EAST_ARROW 4
#define SOUTH_SOUTH_EAST_ARROW 5
#define SOUTH_ARROW 6
#define SOUTH_SOUTH_WEST_ARROW 7
#define SOUTH_WEST_WEST_ARROW 8
#define WEST_ARROW 9
#define WEST_SOUTH_WEST_ARROW 10
#define WEST_NORTH_NORTH_ARROW 11

#define END_SCREEN_TEXT_SCORE_X_POS 390
#define END_SCREEN_TEXT_SCORE_Y_POS 280
#define END_SCREEN_MSD_OFFSET 50
#define END_SCREEN_LSD_OFFSET 58

#define END_SCREEN_NO_HOLE_MSG_POSX 356
#define END_SCREEN_HOLE_MSG_POSX 348
#define END_SCREEN_MSG_POSY 300

void renderPlayerBox(UINT8 *, PlayerBox *);
void renderTotalScoreNumber(UINT8 *, TotalScoreBox *);
void renderTotalScoreBox(UINT8 *,  TotalScoreBox *);
void renderMapNumberBox(UINT8 *, MapNumberBox *);
void renderParBox(UINT8 *, ParBox *);
void renderShotsNumber(UINT8 *, ShotBox *);
void renderShotBox(UINT8 *, ShotBox *);
void renderPowerText(UINT8 *, PowerText *);
void renderPowerBarIndicator(UINT16 *, PowerBarIndicator *);
void renderPowerPercentage(UINT8 *, PowerPercentage *);
void renderPowerBarBox(UINT16 *, PowerBarBox *);
void renderStatBox(UINT16 *, StatBox *);
void renderBallDirectionPointer(UINT32 *, BallDirectionPointer *, int);
void renderBall(UINT8 *,  Ball *);
void renderPortal(UINT16 *, Portal *);
void renderHole(UINT16 *,  Hole *);
void renderTile(UINT16 *,  Tile *);
void renderTileGrid(UINT16 *,  TileGrid *);
void renderMapBox(UINT16 *,  MapBox *);
void renderScreen(UINT16 *,  Model *);
void updateBallDetails(UINT8*,  Model*);
void updateStagingDetails(UINT8*, Model*);
void updateScreen(UINT16 *,  Model *);
void clearScreen(UINT32*);
void renderStatic(UINT16*,  Model*);
void renderMouse(UINT8*, Mouse*);
void renderSplashScreen(UINT32*);
void renderEndScreen(UINT32*, EndScreen *);
#endif
