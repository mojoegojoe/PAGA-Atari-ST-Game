/*
Name:       Soren Bradley, Joe Spurway
Email:      sbrad910@mtroyal.ca
Course:     COMP 2659-001
Semester:   Winter 2022
Instructor: Paul Pospisil

Project: Puals Astro Golf Adventure (Paga)

File: PAGA.C

Purpose: THE GAME and the best one ever, don't worry about the sound, we made it so only dogs can hear it.
*/
#include "PAGA.H"

UINT8 sync_mode = SYNC_START_SCREEN;
UINT8 renderRequest = FALSE;
UINT8 secondaryBuffer[32256];
UINT8 thirdBuffer[32000];

struct _Model model =
        {
                {
                        MAPBOX_X, MAPBOX_Y, MAPSTART_X, MAPSTART_Y,
                        {
                                BALLSTART_X, BALLSTART_Y, BALLSTART_X, BALLSTART_Y, BALLANGLE_START, BALLPOWER_START,
                                BALLVELOCITY_START, 0, 0, BALLMOVING_START, {BALLSTART_X - 4, BALLSTART_Y - 4}
                        },
                        {
                                MAPHOLE_X, MAPHOLE_Y, MAPHOLE_C_X, MAPHOLE_C_Y, MAPHOLE_HIT, MAPHOLE_FRIC
                        },
                        {
                                {PORTAL_1_X, PORTAL_1_Y, PORTAL_1_FRIC,},
                                {PORTAL_2_X, PORTAL_2_Y, PORTAL_2_FRIC,}
                        },
                        {
                                {
                                        {{0, 0, TILE_WALL}, {16, 0, TILE_WALL}, {32, 0, TILE_WALL}, {48, 0, TILE_WALL},
                                         {64, 0, TILE_WALL}, {80, 0, TILE_WALL}, {96, 0, TILE_WALL},
                                         {112, 0, TILE_WALL}, {128, 0, TILE_WALL}, {144, 0, TILE_WALL},
                                         {160, 0, TILE_WALL}, {176, 0, TILE_WALL}, {192, 0, TILE_WALL},
                                         {208, 0, TILE_WALL}, {224, 0, TILE_WALL}, {240, 0, TILE_WALL},
                                         {256, 0, TILE_WALL}, {272, 0, TILE_WALL}, {288, 0, TILE_WALL},
                                         {304, 0, TILE_WALL}, {320, 0, TILE_WALL}, {336, 0, TILE_WALL},
                                         {352, 0, TILE_WALL}, {368, 0, TILE_WALL}, {384, 0, TILE_WALL},
                                         {400, 0, TILE_WALL}, {416, 0, TILE_WALL}, {432, 0, TILE_WALL},
                                         {448, 0, TILE_WALL}, {464, 0, TILE_WALL}, {480, 0, TILE_WALL},
                                         {496, 0, TILE_WALL}, {512, 0, TILE_WALL}, {528, 0, TILE_WALL},
                                         {544, 0, TILE_WALL}, {560, 0, TILE_WALL}, {576, 0, TILE_WALL},
                                         {592, 0, TILE_WALL}, {608, 0, TILE_WALL}, {624, 0, TILE_WALL}},
                                        {{0, 16, TILE_WALL}, {16, 16, TILE_GROUND}, {32, 16, TILE_GROUND},
                                         {48, 16, TILE_GROUND}, {64, 16, TILE_GROUND}, {80, 16, TILE_GROUND},
                                         {96, 16, TILE_GROUND}, {112, 16, TILE_GROUND}, {128, 16, TILE_GROUND},
                                         {144, 16, TILE_GROUND}, {160, 16, TILE_GROUND}, {176, 16, TILE_GROUND},
                                         {192, 16, TILE_GROUND}, {208, 16, TILE_GROUND}, {224, 16, TILE_GROUND},
                                         {240, 16, TILE_GROUND}, {256, 16, TILE_GROUND}, {272, 16, TILE_GROUND},
                                         {288, 16, TILE_GROUND}, {304, 16, TILE_GROUND}, {320, 16, TILE_GROUND},
                                         {336, 16, TILE_GROUND}, {352, 16, TILE_GROUND}, {368, 16, TILE_GROUND},
                                         {384, 16, TILE_GROUND}, {400, 16, TILE_GROUND}, {416, 16, TILE_GROUND},
                                         {432, 16, TILE_GROUND}, {448, 16, TILE_GROUND}, {464, 16, TILE_WALL},
                                         {480, 16, TILE_GROUND}, {496, 16, TILE_GROUND}, {512, 16, TILE_GROUND},
                                         {528, 16, TILE_GROUND}, {544, 16, TILE_GROUND}, {560, 16, TILE_GROUND},
                                         {576, 16, TILE_GROUND}, {592, 16, TILE_GROUND}, {608, 16, TILE_GROUND},
                                         {624, 16, TILE_WALL}},
                                        {{0, 32, TILE_WALL}, {16, 32, TILE_GROUND}, {32, 32, TILE_GROUND},
                                         {48, 32, TILE_GROUND}, {64, 32, TILE_GROUND}, {80, 32, TILE_GROUND},
                                         {96, 32, TILE_GROUND}, {112, 32, TILE_GROUND}, {128, 32, TILE_GROUND},
                                         {144, 32, TILE_GROUND}, {160, 32, TILE_GROUND}, {176, 32, TILE_GROUND},
                                         {192, 32, TILE_GROUND}, {208, 32, TILE_GROUND}, {224, 32, TILE_GROUND},
                                         {240, 32, TILE_GROUND}, {256, 32, TILE_GROUND}, {272, 32, TILE_GROUND},
                                         {288, 32, TILE_GROUND}, {304, 32, TILE_GROUND}, {320, 32, TILE_GROUND},
                                         {336, 32, TILE_GROUND}, {352, 32, TILE_GROUND}, {368, 32, TILE_GROUND},
                                         {384, 32, TILE_GROUND}, {400, 32, TILE_GROUND}, {416, 32, TILE_GROUND},
                                         {432, 32, TILE_GROUND}, {448, 32, TILE_GROUND}, {464, 32, TILE_WALL},
                                         {480, 32, TILE_GROUND}, {496, 32, TILE_GROUND}, {512, 32, TILE_GROUND},
                                         {528, 32, TILE_GROUND}, {544, 32, TILE_GROUND}, {560, 32, TILE_GROUND},
                                         {576, 32, TILE_GROUND}, {592, 32, TILE_GROUND}, {608, 32, TILE_GROUND},
                                         {624, 32, TILE_WALL}},
                                        {{0, 48, TILE_WALL}, {16, 48, TILE_GROUND}, {32, 48, TILE_GROUND},
                                         {48, 48, TILE_GROUND}, {64, 48, TILE_GROUND}, {80, 48, TILE_GROUND},
                                         {96, 48, TILE_GROUND}, {112, 48, TILE_GROUND}, {128, 48, TILE_GROUND},
                                         {144, 48, TILE_GROUND}, {160, 48, TILE_GROUND}, {176, 48, TILE_GROUND},
                                         {192, 48, TILE_GROUND}, {208, 48, TILE_GROUND}, {224, 48, TILE_GROUND},
                                         {240, 48, TILE_GROUND}, {256, 48, TILE_GROUND}, {272, 48, TILE_GROUND},
                                         {288, 48, TILE_GROUND}, {304, 48, TILE_GROUND}, {320, 48, TILE_GROUND},
                                         {336, 48, TILE_GROUND}, {352, 48, TILE_GROUND}, {368, 48, TILE_GROUND},
                                         {384, 48, TILE_GROUND}, {400, 48, TILE_GROUND}, {416, 48, TILE_GROUND},
                                         {432, 48, TILE_GROUND}, {448, 48, TILE_GROUND}, {464, 48, TILE_GROUND},
                                         {480, 48, TILE_GROUND}, {496, 48, TILE_GROUND}, {512, 48, TILE_GROUND},
                                         {528, 48, TILE_GROUND}, {544, 48, TILE_GROUND}, {560, 48, TILE_GROUND},
                                         {576, 48, TILE_GROUND}, {592, 48, TILE_GROUND}, {608, 48, TILE_GROUND},
                                         {624, 48, TILE_WALL}},
                                        {{0, 64, TILE_WALL}, {16, 64, TILE_WALL}, {32, 64, TILE_WALL},
                                         {48, 64, TILE_WALL}, {64, 64, TILE_WALL}, {80, 64, TILE_WALL},
                                         {96, 64, TILE_WALL}, {112, 64, TILE_WALL}, {128, 64, TILE_WALL},
                                         {144, 64, TILE_WALL}, {160, 64, TILE_WALL}, {176, 64, TILE_WALL},
                                         {192, 64, TILE_WALL}, {208, 64, TILE_WALL}, {224, 64, TILE_GROUND},
                                         {240, 64, TILE_GROUND}, {256, 64, TILE_GROUND}, {272, 64, TILE_GROUND},
                                         {288, 64, TILE_GROUND}, {304, 64, TILE_GROUND}, {320, 64, TILE_GROUND},
                                         {336, 64, TILE_GROUND}, {352, 64, TILE_WALL}, {368, 64, TILE_GROUND},
                                         {384, 64, TILE_GROUND}, {400, 64, TILE_GROUND}, {416, 64, TILE_GROUND},
                                         {432, 64, TILE_GROUND}, {448, 64, TILE_GROUND}, {464, 64, TILE_GROUND},
                                         {480, 64, TILE_GROUND}, {496, 64, TILE_GROUND}, {512, 64, TILE_GROUND},
                                         {528, 64, TILE_GROUND}, {544, 64, TILE_GROUND}, {560, 64, TILE_GROUND},
                                         {576, 64, TILE_GROUND}, {592, 64, TILE_GROUND}, {608, 64, TILE_GROUND},
                                         {624, 64, TILE_WALL}},
                                        {{0, 80, TILE_WALL}, {16, 80, TILE_GROUND}, {32, 80, TILE_GROUND},
                                         {48, 80, TILE_GROUND}, {64, 80, TILE_GROUND}, {80, 80, TILE_GROUND},
                                         {96, 80, TILE_GROUND}, {112, 80, TILE_GROUND}, {128, 80, TILE_GROUND},
                                         {144, 80, TILE_GROUND}, {160, 80, TILE_GROUND}, {176, 80, TILE_GROUND},
                                         {192, 80, TILE_GROUND}, {208, 80, TILE_GROUND}, {224, 80, TILE_GROUND},
                                         {240, 80, TILE_GROUND}, {256, 80, TILE_GROUND}, {272, 80, TILE_GROUND},
                                         {288, 80, TILE_GROUND}, {304, 80, TILE_GROUND}, {320, 80, TILE_GROUND},
                                         {336, 80, TILE_GROUND}, {352, 80, TILE_WALL}, {368, 80, TILE_GROUND},
                                         {384, 80, TILE_GROUND}, {400, 80, TILE_GROUND}, {416, 80, TILE_GROUND},
                                         {432, 80, TILE_GROUND}, {448, 80, TILE_GROUND}, {464, 80, TILE_GROUND},
                                         {480, 80, TILE_GROUND}, {496, 80, TILE_GROUND}, {512, 80, TILE_GROUND},
                                         {528, 80, TILE_GROUND}, {544, 80, TILE_GROUND}, {560, 80, TILE_GROUND},
                                         {576, 80, TILE_GROUND}, {592, 80, TILE_GROUND}, {608, 80, TILE_GROUND},
                                         {624, 80, TILE_WALL}},
                                        {{0, 96, TILE_WALL}, {16, 96, TILE_GROUND}, {32, 96, TILE_PORTAL},
                                         {48, 96, TILE_GROUND}, {64, 96, TILE_GROUND}, {80, 96, TILE_GROUND},
                                         {96, 96, TILE_GROUND}, {112, 96, TILE_GROUND}, {128, 96, TILE_GROUND},
                                         {144, 96, TILE_GROUND}, {160, 96, TILE_GROUND}, {176, 96, TILE_GROUND},
                                         {192, 96, TILE_GROUND}, {208, 96, TILE_GROUND}, {224, 96, TILE_GROUND},
                                         {240, 96, TILE_GROUND}, {256, 96, TILE_GROUND}, {272, 96, TILE_GROUND},
                                         {288, 96, TILE_GROUND}, {304, 96, TILE_GROUND}, {320, 96, TILE_GROUND},
                                         {336, 96, TILE_GROUND}, {352, 96, TILE_WALL}, {368, 96, TILE_GROUND},
                                         {384, 96, TILE_GROUND}, {400, 96, TILE_GROUND}, {416, 96, TILE_GROUND},
                                         {432, 96, TILE_GROUND}, {448, 96, TILE_GROUND}, {464, 96, TILE_WALL},
                                         {480, 96, TILE_GROUND}, {496, 96, TILE_GROUND}, {512, 96, TILE_GROUND},
                                         {528, 96, TILE_GROUND}, {544, 96, TILE_GROUND}, {560, 96, TILE_GROUND},
                                         {576, 96, TILE_GROUND}, {592, 96, TILE_GROUND}, {608, 96, TILE_GROUND},
                                         {624, 96, TILE_WALL}},
                                        {{0, 112, TILE_WALL}, {16, 112, TILE_GROUND}, {32, 112, TILE_GROUND},
                                         {48, 112, TILE_GROUND}, {64, 112, TILE_GROUND}, {80, 112, TILE_GROUND},
                                         {96, 112, TILE_GROUND}, {112, 112, TILE_GROUND}, {128, 112, TILE_GROUND},
                                         {144, 112, TILE_GROUND}, {160, 112, TILE_GROUND}, {176, 112, TILE_GROUND},
                                         {192, 112, TILE_GROUND}, {208, 112, TILE_GROUND}, {224, 112, TILE_GROUND},
                                         {240, 112, TILE_GROUND}, {256, 112, TILE_GROUND}, {272, 112, TILE_GROUND},
                                         {288, 112, TILE_GROUND}, {304, 112, TILE_GROUND}, {320, 112, TILE_GROUND},
                                         {336, 112, TILE_GROUND}, {352, 112, TILE_WALL}, {368, 112, TILE_GROUND},
                                         {384, 112, TILE_GROUND}, {400, 112, TILE_GROUND}, {416, 112, TILE_GROUND},
                                         {432, 112, TILE_GROUND}, {448, 112, TILE_GROUND}, {464, 112, TILE_WALL},
                                         {480, 112, TILE_GROUND}, {496, 112, TILE_GROUND}, {512, 112, TILE_GROUND},
                                         {528, 112, TILE_GROUND}, {544, 112, TILE_GROUND}, {560, 112, TILE_GROUND},
                                         {576, 112, TILE_GROUND}, {592, 112, TILE_GROUND}, {608, 112, TILE_GROUND},
                                         {624, 112, TILE_WALL}},
                                        {{0, 128, TILE_WALL}, {16, 128, TILE_WALL}, {32, 128, TILE_WALL},
                                         {48, 128, TILE_WALL}, {64, 128, TILE_WALL}, {80, 128, TILE_WALL},
                                         {96, 128, TILE_WALL}, {112, 128, TILE_WALL}, {128, 128, TILE_WALL},
                                         {144, 128, TILE_WALL}, {160, 128, TILE_WALL}, {176, 128, TILE_WALL},
                                         {192, 128, TILE_WALL}, {208, 128, TILE_WALL}, {224, 128, TILE_WALL},
                                         {240, 128, TILE_WALL}, {256, 128, TILE_WALL}, {272, 128, TILE_WALL},
                                         {288, 128, TILE_WALL}, {304, 128, TILE_WALL}, {320, 128, TILE_WALL},
                                         {336, 128, TILE_WALL}, {352, 128, TILE_WALL}, {368, 128, TILE_WALL},
                                         {384, 128, TILE_WALL}, {400, 128, TILE_WALL}, {416, 128, TILE_WALL},
                                         {432, 128, TILE_WALL}, {448, 128, TILE_WALL}, {464, 128, TILE_WALL},
                                         {480, 128, TILE_GROUND}, {496, 128, TILE_GROUND}, {512, 128, TILE_GROUND},
                                         {528, 128, TILE_GROUND}, {544, 128, TILE_GROUND}, {560, 128, TILE_GROUND},
                                         {576, 128, TILE_GROUND}, {592, 128, TILE_WALL}, {608, 128, TILE_WALL},
                                         {624, 128, TILE_WALL}},
                                        {{0, 144, TILE_WALL}, {16, 144, TILE_GROUND}, {32, 144, TILE_GROUND},
                                         {48, 144, TILE_GROUND}, {64, 144, TILE_GROUND}, {80, 144, TILE_GROUND},
                                         {96, 144, TILE_GROUND}, {112, 144, TILE_GROUND}, {128, 144, TILE_GROUND},
                                         {144, 144, TILE_GROUND}, {160, 144, TILE_WALL}, {176, 144, TILE_GROUND},
                                         {192, 144, TILE_GROUND}, {208, 144, TILE_GROUND}, {224, 144, TILE_GROUND},
                                         {240, 144, TILE_GROUND}, {256, 144, TILE_GROUND}, {272, 144, TILE_GROUND},
                                         {288, 144, TILE_GROUND}, {304, 144, TILE_GROUND}, {320, 144, TILE_GROUND},
                                         {336, 144, TILE_GROUND}, {352, 144, TILE_GROUND}, {368, 144, TILE_GROUND},
                                         {384, 144, TILE_GROUND}, {400, 144, TILE_GROUND}, {416, 144, TILE_GROUND},
                                         {432, 144, TILE_GROUND}, {448, 144, TILE_GROUND}, {464, 144, TILE_WALL},
                                         {480, 144, TILE_GROUND}, {496, 144, TILE_GROUND}, {512, 144, TILE_GROUND},
                                         {528, 144, TILE_GROUND}, {544, 144, TILE_GROUND}, {560, 144, TILE_GROUND},
                                         {576, 144, TILE_GROUND}, {592, 144, TILE_GROUND}, {608, 144, TILE_GROUND},
                                         {624, 144, TILE_WALL}},
                                        {{0, 160, TILE_WALL}, {16, 160, TILE_GROUND}, {32, 160, TILE_GROUND},
                                         {48, 160, TILE_GROUND}, {64, 160, TILE_GROUND}, {80, 160, TILE_GROUND},
                                         {96, 160, TILE_GROUND}, {112, 160, TILE_GROUND}, {128, 160, TILE_GROUND},
                                         {144, 160, TILE_GROUND}, {160, 160, TILE_WALL}, {176, 160, TILE_GROUND},
                                         {192, 160, TILE_GROUND}, {208, 160, TILE_GROUND}, {224, 160, TILE_GROUND},
                                         {240, 160, TILE_GROUND}, {256, 160, TILE_GROUND}, {272, 160, TILE_GROUND},
                                         {288, 160, TILE_GROUND}, {304, 160, TILE_GROUND}, {320, 160, TILE_GROUND},
                                         {336, 160, TILE_GROUND}, {352, 160, TILE_GROUND}, {368, 160, TILE_GROUND},
                                         {384, 160, TILE_GROUND}, {400, 160, TILE_GROUND}, {416, 160, TILE_GROUND},
                                         {432, 160, TILE_GROUND}, {448, 160, TILE_GROUND}, {464, 160, TILE_WALL},
                                         {480, 160, TILE_GROUND}, {496, 160, TILE_GROUND}, {512, 160, TILE_GROUND},
                                         {528, 160, TILE_GROUND}, {544, 160, TILE_GROUND}, {560, 160, TILE_GROUND},
                                         {576, 160, TILE_GROUND}, {592, 160, TILE_GROUND}, {608, 160, TILE_GROUND},
                                         {624, 160, TILE_WALL}},
                                        {{0, 176, TILE_WALL}, {16, 176, TILE_GROUND}, {32, 176, TILE_GROUND},
                                         {48, 176, TILE_GROUND}, {64, 176, TILE_GROUND}, {80, 176, TILE_GROUND},
                                         {96, 176, TILE_GROUND}, {112, 176, TILE_GROUND}, {128, 176, TILE_GROUND},
                                         {144, 176, TILE_GROUND}, {160, 176, TILE_WALL}, {176, 176, TILE_GROUND},
                                         {192, 176, TILE_GROUND}, {208, 176, TILE_GROUND}, {224, 176, TILE_GROUND},
                                         {240, 176, TILE_GROUND}, {256, 176, TILE_GROUND}, {272, 176, TILE_GROUND},
                                         {288, 176, TILE_GROUND}, {304, 176, TILE_GROUND}, {320, 176, TILE_GROUND},
                                         {336, 176, TILE_GROUND}, {352, 176, TILE_GROUND}, {368, 176, TILE_GROUND},
                                         {384, 176, TILE_GROUND}, {400, 176, TILE_GROUND}, {416, 176, TILE_GROUND},
                                         {432, 176, TILE_GROUND}, {448, 176, TILE_GROUND}, {464, 176, TILE_WALL},
                                         {480, 176, TILE_GROUND}, {496, 176, TILE_GROUND}, {512, 176, TILE_GROUND},
                                         {528, 176, TILE_GROUND}, {544, 176, TILE_GROUND}, {560, 176, TILE_GROUND},
                                         {576, 176, TILE_GROUND}, {592, 176, TILE_GROUND}, {608, 176, TILE_GROUND},
                                         {624, 176, TILE_WALL}},
                                        {{0, 192, TILE_WALL}, {16, 192, TILE_GROUND}, {32, 192, TILE_GROUND},
                                         {48, 192, TILE_GROUND}, {64, 192, TILE_GROUND}, {80, 192, TILE_WALL},
                                         {96, 192, TILE_GROUND}, {112, 192, TILE_GROUND}, {128, 192, TILE_GROUND},
                                         {144, 192, TILE_GROUND}, {160, 192, TILE_GROUND}, {176, 192, TILE_GROUND},
                                         {192, 192, TILE_GROUND}, {208, 192, TILE_GROUND}, {224, 192, TILE_GROUND},
                                         {240, 192, TILE_GROUND}, {256, 192, TILE_GROUND}, {272, 192, TILE_GROUND},
                                         {288, 192, TILE_GROUND}, {304, 192, TILE_GROUND}, {320, 192, TILE_GROUND},
                                         {336, 192, TILE_GROUND}, {352, 192, TILE_GROUND}, {368, 192, TILE_GROUND},
                                         {384, 192, TILE_GROUND}, {400, 192, TILE_GROUND}, {416, 192, TILE_GROUND},
                                         {432, 192, TILE_GROUND}, {448, 192, TILE_GROUND}, {464, 192, TILE_WALL},
                                         {480, 192, TILE_WALL}, {496, 192, TILE_WALL}, {512, 192, TILE_WALL},
                                         {528, 192, TILE_GROUND}, {544, 192, TILE_GROUND}, {560, 192, TILE_GROUND},
                                         {576, 192, TILE_GROUND}, {592, 192, TILE_GROUND}, {608, 192, TILE_GROUND},
                                         {624, 192, TILE_WALL}},
                                        {{0, 208, TILE_WALL}, {16, 208, TILE_GROUND}, {32, 208, TILE_PORTAL},
                                         {48, 208, TILE_GROUND}, {64, 208, TILE_GROUND}, {80, 208, TILE_WALL},
                                         {96, 208, TILE_GROUND}, {112, 208, TILE_GROUND}, {128, 208, TILE_GROUND},
                                         {144, 208, TILE_GROUND}, {160, 208, TILE_GROUND}, {176, 208, TILE_GROUND},
                                         {192, 208, TILE_GROUND}, {208, 208, TILE_GROUND}, {224, 208, TILE_GROUND},
                                         {240, 208, TILE_WALL}, {256, 208, TILE_GROUND}, {272, 208, TILE_GROUND},
                                         {288, 208, TILE_GROUND}, {304, 208, TILE_GROUND}, {320, 208, TILE_GROUND},
                                         {336, 208, TILE_GROUND}, {352, 208, TILE_GROUND}, {368, 208, TILE_GROUND},
                                         {384, 208, TILE_GROUND}, {400, 208, TILE_GROUND}, {416, 208, TILE_GROUND},
                                         {432, 208, TILE_GROUND}, {448, 208, TILE_GROUND}, {464, 208, TILE_WALL},
                                         {480, 208, TILE_GROUND}, {496, 208, TILE_GROUND}, {512, 208, TILE_GROUND},
                                         {528, 208, TILE_GROUND}, {544, 208, TILE_GROUND}, {560, 208, TILE_GROUND},
                                         {576, 208, TILE_GROUND}, {592, 208, TILE_GROUND}, {608, 208, TILE_GROUND},
                                         {624, 208, TILE_WALL}},
                                        {{0, 224, TILE_WALL}, {16, 224, TILE_GROUND}, {32, 224, TILE_GROUND},
                                         {48, 224, TILE_GROUND}, {64, 224, TILE_GROUND}, {80, 224, TILE_WALL},
                                         {96, 224, TILE_GROUND}, {112, 224, TILE_GROUND}, {128, 224, TILE_GROUND},
                                         {144, 224, TILE_GROUND}, {160, 224, TILE_GROUND}, {176, 224, TILE_GROUND},
                                         {192, 224, TILE_GROUND}, {208, 224, TILE_GROUND}, {224, 224, TILE_GROUND},
                                         {240, 224, TILE_WALL}, {256, 224, TILE_GROUND}, {272, 224, TILE_GROUND},
                                         {288, 224, TILE_GROUND}, {304, 224, TILE_GROUND}, {320, 224, TILE_GROUND},
                                         {336, 224, TILE_GROUND}, {352, 224, TILE_GROUND}, {368, 224, TILE_GROUND},
                                         {384, 224, TILE_GROUND}, {400, 224, TILE_GROUND}, {416, 224, TILE_GROUND},
                                         {432, 224, TILE_GROUND}, {448, 224, TILE_GROUND}, {464, 224, TILE_WALL},
                                         {480, 224, TILE_GROUND}, {496, 224, TILE_GROUND}, {512, 224, TILE_GROUND},
                                         {528, 224, TILE_GROUND}, {544, 224, TILE_GROUND}, {560, 224, TILE_GROUND},
                                         {576, 224, TILE_GROUND}, {592, 224, TILE_GROUND}, {608, 224, TILE_GROUND},
                                         {624, 224, TILE_WALL}},
                                        {{0, 240, TILE_WALL}, {16, 240, TILE_WALL}, {32, 240, TILE_WALL},
                                         {48, 240, TILE_WALL}, {64, 240, TILE_WALL}, {80, 240, TILE_WALL},
                                         {96, 240, TILE_WALL}, {112, 240, TILE_WALL}, {128, 240, TILE_WALL},
                                         {144, 240, TILE_WALL}, {160, 240, TILE_WALL}, {176, 240, TILE_WALL},
                                         {192, 240, TILE_WALL}, {208, 240, TILE_WALL}, {224, 240, TILE_WALL},
                                         {240, 240, TILE_WALL}, {256, 240, TILE_GROUND}, {272, 240, TILE_GROUND},
                                         {288, 240, TILE_GROUND}, {304, 240, TILE_GROUND}, {320, 240, TILE_GROUND},
                                         {336, 240, TILE_GROUND}, {352, 240, TILE_GROUND}, {368, 240, TILE_GROUND},
                                         {384, 240, TILE_WALL}, {400, 240, TILE_GROUND}, {416, 240, TILE_GROUND},
                                         {432, 240, TILE_GROUND}, {448, 240, TILE_GROUND}, {464, 240, TILE_GROUND},
                                         {480, 240, TILE_GROUND}, {496, 240, TILE_GROUND}, {512, 240, TILE_GROUND},
                                         {528, 240, TILE_GROUND}, {544, 240, TILE_GROUND}, {560, 240, TILE_GROUND},
                                         {576, 240, TILE_GROUND}, {592, 240, TILE_GROUND}, {608, 240, TILE_GROUND},
                                         {624, 240, TILE_WALL}},
                                        {{0, 256, TILE_WALL}, {16, 256, TILE_GROUND}, {32, 256, TILE_GROUND},
                                         {48, 256, TILE_GROUND}, {64, 256, TILE_GROUND}, {80, 256, TILE_WALL},
                                         {96, 256, TILE_WALL}, {112, 256, TILE_WALL}, {128, 256, TILE_WALL},
                                         {144, 256, TILE_WALL}, {160, 256, TILE_GROUND}, {176, 256, TILE_GROUND},
                                         {192, 256, TILE_GROUND}, {208, 256, TILE_GROUND}, {224, 256, TILE_GROUND},
                                         {240, 256, TILE_WALL}, {256, 256, TILE_GROUND}, {272, 256, TILE_GROUND},
                                         {288, 256, TILE_GROUND}, {304, 256, TILE_GROUND}, {320, 256, TILE_GROUND},
                                         {336, 256, TILE_GROUND}, {352, 256, TILE_GROUND}, {368, 256, TILE_GROUND},
                                         {384, 256, TILE_WALL}, {400, 256, TILE_GROUND}, {416, 256, TILE_GROUND},
                                         {432, 256, TILE_GROUND}, {448, 256, TILE_GROUND}, {464, 256, TILE_GROUND},
                                         {480, 256, TILE_GROUND}, {496, 256, TILE_GROUND}, {512, 256, TILE_GROUND},
                                         {528, 256, TILE_GROUND}, {544, 256, TILE_GROUND}, {560, 256, TILE_GROUND},
                                         {576, 256, TILE_GROUND}, {592, 256, TILE_GROUND}, {608, 256, TILE_GROUND},
                                         {624, 256, TILE_WALL}},
                                        {{0, 272, TILE_WALL}, {16, 272, TILE_GROUND}, {32, 272, TILE_GROUND},
                                         {48, 272, TILE_GROUND}, {64, 272, TILE_GROUND}, {80, 272, TILE_GROUND},
                                         {96, 272, TILE_GROUND}, {112, 272, TILE_WALL}, {128, 272, TILE_GROUND},
                                         {144, 272, TILE_GROUND}, {160, 272, TILE_GROUND}, {176, 272, TILE_GROUND},
                                         {192, 272, TILE_GROUND}, {208, 272, TILE_GROUND}, {224, 272, TILE_GROUND},
                                         {240, 272, TILE_WALL}, {256, 272, TILE_GROUND}, {272, 272, TILE_GROUND},
                                         {288, 272, TILE_GROUND}, {304, 272, TILE_GROUND}, {320, 272, TILE_GROUND},
                                         {336, 272, TILE_GROUND}, {352, 272, TILE_GROUND}, {368, 272, TILE_GROUND},
                                         {384, 272, TILE_WALL}, {400, 272, TILE_GROUND}, {416, 272, TILE_GROUND},
                                         {432, 272, TILE_GROUND}, {448, 272, TILE_GROUND}, {464, 272, TILE_GROUND},
                                         {480, 272, TILE_GROUND}, {496, 272, TILE_GROUND}, {512, 272, TILE_GROUND},
                                         {528, 272, TILE_GROUND}, {544, 272, TILE_GROUND}, {560, 272, TILE_GROUND},
                                         {576, 272, TILE_GROUND}, {592, 272, TILE_GROUND}, {608, 272, TILE_GROUND},
                                         {624, 272, TILE_WALL}},
                                        {{0, 288, TILE_WALL}, {16, 288, TILE_GROUND}, {32, 288, TILE_GROUND},
                                         {48, 288, TILE_GROUND}, {64, 288, TILE_GROUND}, {80, 288, TILE_GROUND},
                                         {96, 288, TILE_GROUND}, {112, 288, TILE_GROUND}, {128, 288, TILE_GROUND},
                                         {144, 288, TILE_GROUND}, {160, 288, TILE_GROUND}, {176, 288, TILE_GROUND},
                                         {192, 288, TILE_GROUND}, {208, 288, TILE_GROUND}, {224, 288, TILE_GROUND},
                                         {240, 288, TILE_WALL}, {256, 288, TILE_GROUND}, {272, 288, TILE_GROUND},
                                         {288, 288, TILE_GROUND}, {304, 288, TILE_GROUND}, {320, 288, TILE_GROUND},
                                         {336, 288, TILE_GROUND}, {352, 288, TILE_GROUND}, {368, 288, TILE_GROUND},
                                         {384, 288, TILE_WALL}, {400, 288, TILE_WALL}, {416, 288, TILE_WALL},
                                         {432, 288, TILE_WALL}, {448, 288, TILE_WALL}, {464, 288, TILE_WALL},
                                         {480, 288, TILE_WALL}, {496, 288, TILE_WALL}, {512, 288, TILE_WALL},
                                         {528, 288, TILE_WALL}, {544, 288, TILE_GROUND}, {560, 288, TILE_GROUND},
                                         {576, 288, TILE_GROUND}, {592, 288, TILE_GROUND}, {608, 288, TILE_GROUND},
                                         {624, 288, TILE_WALL}},
                                        {{0, 304, TILE_WALL}, {16, 304, TILE_GROUND}, {32, 304, TILE_GROUND},
                                         {48, 304, TILE_HOLE}, {64, 304, TILE_GROUND}, {80, 304, TILE_GROUND},
                                         {96, 304, TILE_GROUND}, {112, 304, TILE_GROUND}, {128, 304, TILE_GROUND},
                                         {144, 304, TILE_GROUND}, {160, 304, TILE_GROUND}, {176, 304, TILE_GROUND},
                                         {192, 304, TILE_GROUND}, {208, 304, TILE_GROUND}, {224, 304, TILE_GROUND},
                                         {240, 304, TILE_GROUND}, {256, 304, TILE_GROUND}, {272, 304, TILE_GROUND},
                                         {288, 304, TILE_GROUND}, {304, 304, TILE_GROUND}, {320, 304, TILE_GROUND},
                                         {336, 304, TILE_GROUND}, {352, 304, TILE_GROUND}, {368, 304, TILE_GROUND},
                                         {384, 304, TILE_WALL}, {400, 304, TILE_GROUND}, {416, 304, TILE_GROUND},
                                         {432, 304, TILE_GROUND}, {448, 304, TILE_GROUND}, {464, 304, TILE_GROUND},
                                         {480, 304, TILE_GROUND}, {496, 304, TILE_GROUND}, {512, 304, TILE_GROUND},
                                         {528, 304, TILE_GROUND}, {544, 304, TILE_GROUND}, {560, 304, TILE_GROUND},
                                         {576, 304, TILE_GROUND}, {592, 304, TILE_GROUND}, {608, 304, TILE_GROUND},
                                         {624, 304, TILE_WALL}},
                                        {{0, 320, TILE_WALL}, {16, 320, TILE_GROUND}, {32, 320, TILE_GROUND},
                                         {48, 320, TILE_GROUND}, {64, 320, TILE_GROUND}, {80, 320, TILE_GROUND},
                                         {96, 320, TILE_GROUND}, {112, 320, TILE_WALL}, {128, 320, TILE_GROUND},
                                         {144, 320, TILE_GROUND}, {160, 320, TILE_GROUND}, {176, 320, TILE_GROUND},
                                         {192, 320, TILE_GROUND}, {208, 320, TILE_GROUND}, {224, 320, TILE_GROUND},
                                         {240, 320, TILE_GROUND}, {256, 320, TILE_GROUND}, {272, 320, TILE_GROUND},
                                         {288, 320, TILE_GROUND}, {304, 320, TILE_GROUND}, {320, 320, TILE_GROUND},
                                         {336, 320, TILE_GROUND}, {352, 320, TILE_GROUND}, {368, 320, TILE_GROUND},
                                         {384, 320, TILE_WALL}, {400, 320, TILE_GROUND}, {416, 320, TILE_GROUND},
                                         {432, 320, TILE_GROUND}, {448, 320, TILE_GROUND}, {464, 320, TILE_GROUND},
                                         {480, 320, TILE_GROUND}, {496, 320, TILE_GROUND}, {512, 320, TILE_GROUND},
                                         {528, 320, TILE_GROUND}, {544, 320, TILE_GROUND}, {560, 320, TILE_GROUND},
                                         {576, 320, TILE_GROUND}, {592, 320, TILE_GROUND}, {608, 320, TILE_GROUND},
                                         {624, 320, TILE_WALL}},
                                        {{0, 336, TILE_WALL}, {16, 336, TILE_GROUND}, {32, 336, TILE_GROUND},
                                         {48, 336, TILE_GROUND}, {64, 336, TILE_GROUND}, {80, 336, TILE_WALL},
                                         {96, 336, TILE_WALL}, {112, 336, TILE_WALL}, {128, 336, TILE_WALL},
                                         {144, 336, TILE_WALL}, {160, 336, TILE_GROUND}, {176, 336, TILE_GROUND},
                                         {192, 336, TILE_GROUND}, {208, 336, TILE_GROUND}, {224, 336, TILE_GROUND},
                                         {240, 336, TILE_GROUND}, {256, 336, TILE_GROUND}, {272, 336, TILE_GROUND},
                                         {288, 336, TILE_GROUND}, {304, 336, TILE_GROUND}, {320, 336, TILE_GROUND},
                                         {336, 336, TILE_GROUND}, {352, 336, TILE_GROUND}, {368, 336, TILE_GROUND},
                                         {384, 336, TILE_WALL}, {400, 336, TILE_GROUND}, {416, 336, TILE_GROUND},
                                         {432, 336, TILE_GROUND}, {448, 336, TILE_GROUND}, {464, 336, TILE_GROUND},
                                         {480, 336, TILE_GROUND}, {496, 336, TILE_GROUND}, {512, 336, TILE_GROUND},
                                         {528, 336, TILE_GROUND}, {544, 336, TILE_GROUND}, {560, 336, TILE_GROUND},
                                         {576, 336, TILE_GROUND}, {592, 336, TILE_GROUND}, {608, 336, TILE_GROUND},
                                         {624, 336, TILE_WALL}},
                                        {{0, 352, TILE_WALL}, {16, 352, TILE_WALL}, {32, 352, TILE_WALL},
                                         {48, 352, TILE_WALL}, {64, 352, TILE_WALL}, {80, 352, TILE_WALL},
                                         {96, 352, TILE_WALL}, {112, 352, TILE_WALL}, {128, 352, TILE_WALL},
                                         {144, 352, TILE_WALL}, {160, 352, TILE_WALL}, {176, 352, TILE_WALL},
                                         {192, 352, TILE_WALL}, {208, 352, TILE_WALL}, {224, 352, TILE_WALL},
                                         {240, 352, TILE_WALL}, {256, 352, TILE_WALL}, {272, 352, TILE_WALL},
                                         {288, 352, TILE_WALL}, {304, 352, TILE_WALL}, {320, 352, TILE_WALL},
                                         {336, 352, TILE_WALL}, {352, 352, TILE_WALL}, {368, 352, TILE_WALL},
                                         {384, 352, TILE_WALL}, {400, 352, TILE_WALL}, {416, 352, TILE_WALL},
                                         {432, 352, TILE_WALL}, {448, 352, TILE_WALL}, {464, 352, TILE_WALL},
                                         {480, 352, TILE_WALL}, {496, 352, TILE_WALL}, {512, 352, TILE_WALL},
                                         {528, 352, TILE_WALL}, {544, 352, TILE_WALL}, {560, 352, TILE_WALL},
                                         {576, 352, TILE_WALL}, {592, 352, TILE_WALL}, {608, 352, TILE_WALL},
                                         {624, 352, TILE_WALL}}

                                }
                        }
                },

                {
                        STAT_X, STAT_Y,
                        {
                                POWERBARBOX_X, POWERBARBOX_Y,
                                {POWERTEXT_X, POWERBAR_Y},
                                {
                                        {POWER_BAR_IND_X_1, POWERBAR_Y, POWER_BAR_IND_OFF},
                                        {POWER_BAR_IND_X_2, POWERBAR_Y, POWER_BAR_IND_OFF},
                                        {POWER_BAR_IND_X_3, POWERBAR_Y, POWER_BAR_IND_OFF},
                                        {POWER_BAR_IND_X_4, POWERBAR_Y, POWER_BAR_IND_OFF},
                                        {POWER_BAR_IND_X_5, POWERBAR_Y, POWER_BAR_IND_OFF},
                                        {POWER_BAR_IND_X_6, POWERBAR_Y, POWER_BAR_IND_OFF},
                                        {POWER_BAR_IND_X_7, POWERBAR_Y, POWER_BAR_IND_OFF},
                                        {POWER_BAR_IND_X_8, POWERBAR_Y, POWER_BAR_IND_OFF},
                                        {POWER_BAR_IND_X_9, POWERBAR_Y, POWER_BAR_IND_OFF},
                                        {POWER_BAR_IND_X_10, POWERBAR_Y, POWER_BAR_IND_OFF}
                                },
                                {POWERPERC_X, POWERPERC_Y, STARTINGPOWER}
                        },
                        {TOTALSCOREBOX_X, TOTALSCOREBOX_Y, STARTINGSCORE},
                        {MAPNUMBER_X, MAPNUMBER_Y, STARTINGMAP},
                        {PARBOX_X, PARBOX_Y, 7},
                        {SHOTBOX_X, SHOTBOX_Y, 0},
                        {PLAYERBOX_X, PLAYERBOX_Y, 1}
                },
                0
        };


struct _StartScreen start = {
        ACTIVATE,
        {START_OPTION_POSX, START_OPTION_POSY, NOT_PRESSED, START_OPTION_WIDTH, START_OPTION_HEIGHT},
        {QUIT_OPTION_POSX, QUIT_OPTION_POSY, NOT_PRESSED, QUIT_OPTION_WIDTH, QUIT_OPTION_HEIGHT}
};
struct _EndScreen end = {
        NOT_ACTIVE,
        0,
        0,
        {RETRY_OPTION_POSX, RETRY_OPTION_POSY, NOT_PRESSED, RETRY_OPTION_WIDTH, RETRY_OPTION_HEIGHT},
        {QUIT_OPTION_POSX, QUIT_OPTION_POSY, NOT_PRESSED, QUIT_OPTION_WIDTH, QUIT_OPTION_HEIGHT}
};

int main() {

    /* MAIN BEGIN */
    Vector origIKBD;
    Vector origVBL;

    UINT32 bBfrAddress;
    UINT32 *bfrPtrs[2];

    bfrPtrs[0] = getVideoBase();
    bBfrAddress = (UINT32) (secondaryBuffer + 256);
    bBfrAddress &= ~(0xFF);
    bfrPtrs[1] = (UINT32 *) bBfrAddress;

    origIKBD = installVector(IKBD_ISR, ikbdisr);
    origVBL = installVector(VBL_ISR, vblisr);

    clearScreen(bfrPtrs[0]);
    setVideoBase(bfrPtrs[0]);
    renderSplashScreen((UINT32 *) thirdBuffer);
    renderSplashScreen(bfrPtrs[0]);

    while (model.state != GAME_OVER && sync_mode != SYNC_END_SCREEN) {
        if (start.active == ACTIVATE) {
            start_game_menu(bfrPtrs);
        }
        if (model.state == STAGING) {
            game(bfrPtrs);
        }
        if (end.active == ACTIVATE) {
            end_game_menu(bfrPtrs);
        }
    }
    clearScreen(bfrPtrs[0]);
    setVideoBase(bfrPtrs[0]);
    installVector(IKBD_ISR, origIKBD); /* reinstalls the original ikbd isr*/
    installVector(VBL_ISR, origVBL); /* uninstalls the new vbl isr, puts the old one back */
    return 0;
}

void start_game_menu(UINT32 *bfrPtrs[]) {
    UINT16 curBuffer = 0;
    clearScreen(bfrPtrs[curBuffer]);
    clearScreen((UINT32 *) thirdBuffer);
    setVideoBase(bfrPtrs[curBuffer]);
    renderSplashScreen((UINT32 *) thirdBuffer);
    renderSplashScreen(bfrPtrs[curBuffer]);
    while (start.active) {
        if (input_available()) {
            handle_start_menu_async();
        }
        if (renderRequest) {
            memcpy(bfrPtrs[curBuffer], thirdBuffer, sizeof(thirdBuffer));
            renderMouse((UINT8 *) bfrPtrs[curBuffer], &mouse);
            setVideoBase(bfrPtrs[curBuffer]);
            curBuffer = 1 - curBuffer;
            renderRequest = FALSE;
        }
    }
}

void game(UINT32 *bfrPtrs[]) {
    UINT16 curBuffer = 0;
    clearScreen(bfrPtrs[0]);
    clearScreen(bfrPtrs[1]);
    clearScreen((UINT32 *) thirdBuffer);
    renderScreen((UINT16 *) bfrPtrs[0], &model);
    renderScreen((UINT16 *) bfrPtrs[1], &model);
    renderStatic((UINT16 *) thirdBuffer, &model);
    while (model.state != GAME_OVER) {
        if (input_available()) {
            handle_game_async();
        }
        if (renderRequest) {
            memcpy(bfrPtrs[curBuffer], thirdBuffer, sizeof(thirdBuffer));
            updateScreen((UINT16 *) bfrPtrs[curBuffer], &model);
            setVideoBase(bfrPtrs[curBuffer]);
            curBuffer = 1 - curBuffer;
            renderRequest = FALSE;
        }
    }
}

void end_game_menu(UINT32 *bfrPtrs[]) {
    UINT16 curBuffer = 0;
    clearScreen(bfrPtrs[curBuffer]);
    clearScreen((UINT32 *) thirdBuffer);
    renderEndScreen((UINT32 *) thirdBuffer, &end);
    renderEndScreen(bfrPtrs[0], &end);
    renderEndScreen(bfrPtrs[1], &end);
    while (end.active == ACTIVATE) {
        if (input_available()) {
            handle_end_menu_async();
        }
        if (renderRequest) {
            memcpy(bfrPtrs[curBuffer], thirdBuffer, sizeof(thirdBuffer));
            renderMouse((UINT8 *) bfrPtrs[curBuffer], &mouse);
            setVideoBase(bfrPtrs[curBuffer]);
            curBuffer = 1 - curBuffer;
            renderRequest = FALSE;
        }
    }
}

void handle_start_menu_async() {
    char input = read_char();
    switch (input) {
        case LMB_RMB_CLICK:
        case LEFT_CLICK:
            if (is_mouse_start_collision(&mouse, &start.start)) {
                start.start.pressed = PRESSED;
            } else if (is_mouse_quit_collision(&mouse, &start.quit)) {
                start.quit.pressed = PRESSED;
            }
            break;
        case SPRESS:
            start.start.pressed = PRESSED;
            break;
        case QUIT:
            start.quit.pressed = PRESSED;
            break;
    };
}

void handle_game_async() {
    char input = read_char();
    if (model.state == STAGING && model.map_box.hole.hit != 1) {
        switch (input) {
            case APRESS:
                event_ball_rotate_toLeft(&model.map_box.ball);
                break;
            case DPRESS:
                event_ball_rotate_toRight(&model.map_box.ball);
                break;
            case WPRESS:
                event_power_Up(&model);
                break;
            case SPRESS:
                event_power_Down(&model);
                break;
            case SPACE:
                event_shot(&model);
                break;
            case QUIT:
                model.state = GAME_OVER;
                break;
        };
    }
}

void handle_end_menu_async() {
    char input = read_char();
    switch (input) {
        case LMB_RMB_CLICK:
        case LEFT_CLICK:
            if (is_mouse_retry_collision(&mouse, &end.retry)) {
                end.retry.pressed = PRESSED;

            } else if (is_mouse_quit_collision(&mouse, &end.quit)) {
                end.quit.pressed = PRESSED;
            }
            break;
        case RETRY:
            end.retry.pressed = PRESSED;
            break;
        case QUIT:
            end.quit.pressed = PRESSED;
            break;
    };
}

void handle_sync() {
    if (!renderRequest) {
        if (sync_mode == SYNC_START_SCREEN) {
            /** intro music **/
            if (start.start.pressed) {
                sync_mode = SYNC_GAME;
                start.active = NOT_ACTIVE;
                end.active = ACTIVATE;
                model.state = STAGING;
                start.start.pressed = NOT_PRESSED;
            } else if (start.quit.pressed) {
                sync_mode = SYNC_END_SCREEN;
                start.active = NOT_ACTIVE;
                end.active = NOT_ACTIVE;
                model.state = GAME_OVER;
                start.quit.pressed = NOT_PRESSED;
            }
        } else if (sync_mode == SYNC_GAME) {
            /** game music **/
            if (model.map_box.hole.hit == TRUE && model.state == MOVING) {
                model.state = GAME_OVER;
                sync_mode = SYNC_END_SCREEN;
                event_ball_stops(&model);
                /**hit_hole();**/
            } else if (model.map_box.ball.moving == MOVING && model.state == MOVING) {
                if (model.stat_box.shot_box.shots < MAX_SHOTS) {
                    event_ball_moving(&model);
                    if (model.map_box.ball.collision_type == GROUND_CODE) {
                        /** Moving sound effect
                        moving();**/
                    } else if (model.map_box.ball.collision_type == PORTAL_CODE) {
                        /** Wall sound effect
                        hit_hole();**/
                    } else if (model.map_box.ball.collision_type == WALL_CODE) {
                        /** Portal sound effect
                        hit_portal();**/
                    }
                } else {
                    model.state = GAME_OVER;
                    sync_mode = SYNC_END_SCREEN;
                    event_ball_stops(&model);
                }
            } else if (model.map_box.ball.moving == 0 && model.state == MOVING) {
                model.state = STAGING;
                event_ball_stops(&model);
            }
            if (model.state == GAME_OVER) {
                sync_mode = SYNC_END_SCREEN;
            }
            end.is_hole_hit = model.map_box.hole.hit;
            end.final_score = model.stat_box.total_score_box.score;
        } else if (sync_mode == SYNC_END_SCREEN) {
            if (end.retry.pressed) {
                event_reset_ball(&model, BALLSTART_X, BALLSTART_Y);
                sync_mode = SYNC_START_SCREEN;
                start.active = ACTIVATE;
                end.active = NOT_ACTIVE;
                model.state = STAGING;
            } else if (end.quit.pressed) {
                end.active = NOT_ACTIVE;
            }
            end.retry.pressed = FALSE;
            end.quit.pressed = NOT_PRESSED;
            /** intro music **/
        }
        renderRequest = TRUE;
    }
}
