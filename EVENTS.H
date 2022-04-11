/*
Name:       Soren Bradley, Joe Spurway
Email:      sbrad910@mtroyal.ca
Course:     COMP 2659-001
Semester:   Winter 2022
Instructor: Paul Pospisil

Project: Puals Astro Golf Adventure (Paga)

File: EVENTS.H

*/
#ifndef EVENTS_H
#define EVENTS_H


#include "MODEL.H"
#include "MOUSE.H"
#include "DEFINES.H"

#define ANGLE_RANGE 11
#define MAX_POWER 10

#define PORTAL_HEIGHT 16
#define PORTAL_WIDTH 16

#define HOLE_HEIGHT 16
#define HOLE_WIDTH 16

#define BALL_WIDTH 8
#define BALL_HEIGHT 8

#define GROUND_CODE 0
#define PORTAL_CODE 1
#define WALL_CODE 2
#define HOLE_CODE 3

#define GROUND_FRICTION 2
#define HOLE_FRICTION 3
#define PORTAL_FRICTION 1
/* Async  */

/* Sync  */
void event_ball_rotate_toRight(Ball*);
void event_ball_rotate_toLeft(Ball*);
void event_ball_power_Up(Ball*);
void event_ball_power_Down(Ball*);

/* Condition based */
int check_collision(int, int , int , 
                    int , int , int ,
                    int , int );
int is_portal_collision( Ball *ball, Portal *portal);
int is_hole_collision( Ball *ball,  Hole *hole);
int is_mouse_start_collision(Mouse*, StartBox *);
int is_mouse_retry_collision(Mouse*, RetryBox *);
int is_mouse_quit_collision(Mouse*, QuitBox *);
int check_tile_collision( Ball*,  TileGrid*);
void event_ground_pass( Ball*,  MapBox*);
void event_portal_hit(Ball*, MapBox*);
void event_wall_hit(Ball*,  MapBox*);
void event_hole_hit( Ball*,  MapBox*);
void event_update_ball_power( Model*);
void event_ball_collides( Model*);
void event_ball_moving( Model*);
void event_shot( Model*);
void event_power_Up(Model*);
void event_power_Down( Model*);
void event_ball_stops( Model *);
void event_reset_ball(Model *, int, int);
#endif