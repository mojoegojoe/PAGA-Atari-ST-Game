/*
Name:       Soren Bradley, Joe Spurway
Email:      sbrad910@mtroyal.ca
Course:     COMP 2659-001
Semester:   Winter 2022
Instructor: Paul Pospisil

Project: Puals Astro Golf Adventure (Paga)

File: DEFINES.H

Purpose: Holds the defines the cross over modules to reduce repetition
*/
#ifndef DEFINES_H
#define DEFINES_H

#define MAPBOX_X                0
#define MAPBOX_Y                0
#define MAPSTART_X              32
#define MAPSTART_Y              48

#define BALLSTART_X             32
#define BALLSTART_Y             48
#define BALLANGLE_START         3
#define BALLPOWER_START         0
#define BALLVELOCITY_START      0
#define BALLDECVELOCITY_START   2
#define BALLMOVING_START        0
#define BALL_HEIGHT             8

#define MAPHOLE_X               48
#define MAPHOLE_Y               304
#define MAPHOLE_HIT             0
#define MAPHOLE_FRIC            3
#define MAPHOLE_C_X             48
#define MAPHOLE_C_Y             304

#define PORTAL_ONE              0
#define PORTAL_TWO              1

#define PORTAL_1_X              40
#define PORTAL_1_Y              96
#define PORTAL_1_FRIC           1
#define PORTAL_2_X              40 
#define PORTAL_2_Y              200
#define PORTAL_2_FRIC           1


#define STAT_X                  0
#define STAT_Y                  368
#define STARTINGPOWER           0
#define POWERBARBOX_X           0   
#define POWERBARBOX_Y           368

#define POWER_BAR_IND_OFF       0
#define POWER_BAR_IND_ON        1

#define POWER_BAR_IND_X_1       48
#define POWER_BAR_IND_X_2       64
#define POWER_BAR_IND_X_3       80
#define POWER_BAR_IND_X_4       96
#define POWER_BAR_IND_X_5       112
#define POWER_BAR_IND_X_6       128
#define POWER_BAR_IND_X_7       144
#define POWER_BAR_IND_X_8       160
#define POWER_BAR_IND_X_9       176
#define POWER_BAR_IND_X_10      192

#define POWERTEXT_X             0
#define POWERTEXT_Y             373
#define POWERBAR_X              65
#define POWERBAR_Y              368
#define POWERPERC_X             220
#define POWERPERC_Y             373

#define PLAYERBOX_X             64
#define PLAYERBOX_Y             384
#define TOTALSCOREBOX_X         481
#define TOTALSCOREBOX_Y         384
#define HOLENUMBERBOX_X         321
#define HOLENUMBERBOX_Y         384
#define PARBOX_X                321
#define PARBOX_Y                368
#define SHOTBOX_X               481
#define SHOTBOX_Y               368
#define MAPNUMBER_X             321
#define MAPNUMBER_Y             384

#define HOLE_HIT                1
#define HOLE_NOT_HIT             0


#define STARTINGSCORE           0

#define STARTINGMAP             1

#define SCREENWIDTH_UINT8       8

#define TILE_GROUND             0
#define TILE_PORTAL             1
#define TILE_WALL               2
#define TILE_HOLE               3

#define GROUND             0
#define PORTAL             1
#define WALL               2
#define HOLE               3

#define OFF 0
#define ON 1

#define GAME_OVER -1
#define STAGING 0
#define MOVING 1

#define SHIFT_BY_WORD           16
#define SHIFT_BY_BYTE           8

#define SHIFT_FOR_LONGWORD_SIZE     5
#define SHIFT_FOR_WORD_SIZE          4
#define SHIFT_FOR_BYTE_SIZE           3

#define SCREEN_BYTES 80
#define SCREEN_WORDS 40

#define SCREEN_LONGS 20
#endif
