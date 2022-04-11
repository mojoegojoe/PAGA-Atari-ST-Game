/*
Name:       Soren Bradley, Joe Spurway
Email:      sbrad910@mtroyal.ca
Course:     COMP 2659-001
Semester:   Winter 2022
Instructor: Paul Pospisil

Project: Puals Astro Golf Adventure (Paga)

File: MODEL.H
*/
#ifndef MODEL_H
#define MODEL_H
#include "TYPES.H"
#include "DEFINES.H"
/** 
    Data Structures:
        Screen - holds both the map and stat boxes
        StatBox - displays the players statistics including power bar level
            TotalScoreBox - HoleNumberBox - ParBox - ShotBox
            PowerBarBox - displays the visual representation of the power level
            PowerBox - one segment of power within the power bar
        MapBox - holds all objects that make up the map
            Ball - player ball
                DirectionPointerBox - contatiner box for all possible arrows
                    BallDirectionPointer - pointing arrow in direction of travel
            Hole - end goal for players ball
            Portal - transporting tile 
            Ground - base tile state with standard friction
            TileGrid - whole gird of possible tile possitions on map
            Wall - edge of the holes play space

    Functions:
        setAngle - sets the angle of the players ball
        setVelocity - sets velocity of the players ball
        setPower - sets the power of the players ball
        increaseShots - increases number of shots played this hole
        increaseScore - increases the total score 
        setPlayer - sets the players id number
        setPar - sets the par of the current course
        setHit - hole set if hit by ball
        decreaseBallVelocity - reduce the velocity of the ball
        increaseBallVelocity - increase the velocity of the ball
        setBallPos - sets the position for the ball object
        ballMoving - defines when the ball is still in motion
        setTile - sets the type of tile
        getTileObject - returns pointer to a tile
        checkTile - checks the object code of the tile
        ballAngleInvert - invertes the balls position 
**/

#define TILE_GRID_HEIGHT 23
#define TILE_GRID_WIDTH 40

#define MAX_ANGLE 11

#define MAX_POWER_PERCENT 10
#define BALL_STOPPED 0

#define BALL_DIRECTION_PTR_OFFSET 4

#define BALL_TOP_MAX_ANGLE 9
#define BALL_TOP_MIN_ANGLE 3

#define BALL_RIGHT_MAX_ANGLE 6
#define BALL_RIGHT_MIN_ANGLE 0

#define BALL_BOTTOM_MAX_ANGLE 9
#define BALL_BOTTOM_MIN_ANGLE 3

#define BALL_LEFT_MAX_ANGLE 12
#define BALL_LEFT_MIN_ANGLE 6

#define BALL_TOP_SIDE_COLLISION 1
#define BALL_RIGHT_SIDE_COLLISION 2
#define BALL_BOTTOM_SIDE_COLLISION 3
#define BALL_LEFT_SIDE_COLLISION 4

#define BALL_TOP 1
#define BALL_RIGHT 2
#define BALL_BOTTOM 3
#define BALL_LEFT 4

#define JUMP_BALL 4

#define BALL_MID_POS_OFFSET 3
#define BALL_FAR_POS_OFFSET 7
typedef struct  {              /** type definition for player box object    **/
    int posX, posY;             /** position coordinates                     **/
    int player;                 /** player ID 1 / 2                          **/
}PlayerBox;
typedef struct  {          /** type definition for total score object   **/
    int posX, posY;             /** position coordinates                     **/
    int score;                  /** Course current score: 0 - 450            **/ 
}TotalScoreBox;
typedef struct  {                 /** type defintion for par of current hole   **/
    int posX, posY;             /** position coordinates                     **/
    int par_num;                /** course current par: 1 - 7                **/
} ParBox;
typedef struct  {                /** type definiton for shots current hole    **/
    int posX, posY;             /** position coordinates                     **/
    int shots;                  /** course number of shots: 1 - 50           **/
}ShotBox;

typedef struct {            /** type defintion for the current map number**/
    int posX, posY;             /** position coordinates                     **/
    int map_num;                /** current course number                    **/
}MapNumberBox;
typedef struct  {              /** type definition for the text for power   **/
    int posX, posY;             /** position coordinates                     **/
}PowerText;
typedef struct  {
    int posX, posY;
    int on; 
}PowerBarIndicator ;
typedef struct  {        /** type definition for the power percentage **/
    int posX, posY;             /** position coordinates                     **/
    int percent;                /** current percent of power number          **/
} PowerPercentage;
typedef struct  {            /** type definition for Power bar object     **/
    int posX, posY;             /** position coordinates                     **/
     PowerText power_text;/** power text object                        **/
     PowerBarIndicator bar_indicators[10]; /** power box object           **/
     PowerPercentage power_precentage; /** power percentage object     **/
}PowerBarBox;

typedef struct  {                /** type def statistic contatiner object     **/
    int posX, posY;             /** position coordinates                     **/
     PowerBarBox power_bar_box;  /** power bar contatiner object       **/
     TotalScoreBox total_score_box; /** total score object             **/
     MapNumberBox map_number_box;   /** course number object           **/
     ParBox par_box;      /** par of current course object             **/
     ShotBox shot_box;    /** shots used on current course object      **/
     PlayerBox player_box; /** player ID object [1/2]                  **/
}StatBox;


typedef struct  { /** type defintion for the Ball object     **/
    int posX, posY;
    /** angle accessed from the ball object int angle;  max value 12, min 0 **/
}BallDirectionPointer;

typedef struct  {                   /** type defintion for the Ball object     **/
    int posX, posY;             /** position coordinates                   **/
    int last_posX, last_posY; 
    int angle;                  /** current postion of angle: 0 - 11       **/
    
    int power_level;            /** current power level:      10 - 100     **/
    int velocity;               /** current velocity:        -10 - 10      **/
    int collision_loc;            /**   **/
    int collision_type;
    int moving;                /** states if the ball is currently in motion **/
    BallDirectionPointer ball_direct_box;
}Ball;

typedef struct {                  /** type defintion for the Portal object     **/
    int posX, posY;                /** position coordinates                   **/
    int friction; /** modifier of velocity acting on the ball when passing    **/
    struct Portal *connected_portal; /** second connected portal with diff x/y **/
    int active;
} Portal;


typedef struct  {               /** type defintion for a surface type object        **/
    int posX, posY;         /** position coordinates                            **/
    int center_posX, center_posY; /** center position coordinates               **/
    int hit;               /** when hit flag: std false                        **/
    int friction;           /** dramatic friction coefiecent to allow for over shot**/
}Hole;

typedef struct {                   /** type defintion for a single tile object      **/
    int posX, posY;         /** pointer to tile surface                      **/
                                /**          with respective obj_code:           **/
                                /** | ground | portal | wall | hole |            **/
    UINT8 obj_code;             /** |    0   |   1    |   2  |  3   |            **/

}Tile;

typedef struct {                /** type definition for the course tile grid obj **/
    Tile tile_grid[TILE_GRID_HEIGHT][TILE_GRID_WIDTH]; /** array of all tiles on the course         **/
}TileGrid;

typedef struct  {                 /** type defintion for whole course map obj**/
    int posX, posY;             /** position coordinates                   **/
    int start_posX, start_posY; /** Ball obj start position coordinates    **/
    Ball ball;           /** Maps Ball Object                       **/
    Hole hole;           /** Maps Hole Object                       **/
    Portal portals[2];   /** Maps connected portals                 **/
    TileGrid playSpace;  /** Maps course layout grid                **/
}MapBox;

typedef struct _Model {                 /** type definition for Screen object     **/
    MapBox map_box;      /** course map box container object       **/
    StatBox stat_box;    /** players stat box container object     **/
    int state;
}Model;
typedef struct _StartBox {
    int posX,posY;
    int pressed;
    int width;
    int height;
}StartBox;

typedef struct _RetryBox {
    int posX,posY;
    int pressed;
    int width;
    int height;
}RetryBox;

typedef struct _QuitBox {
    int posX,posY;
    int pressed;
    int width;
    int height;
}QuitBox;

typedef struct _StartScreen {
    int active;
    StartBox start;
    QuitBox quit;
}StartScreen;

typedef struct _EndScreen {
    int active;
    int final_score;
    int is_hole_hit;
    RetryBox retry;
    QuitBox  quit;
}EndScreen;

extern const int invert_angle_matrix[12][2];
void setBallAngle(Ball*, int);
void setBallVelocity( Ball*, int);
void setBallPower( Ball*, int);

void resetPowerBarIndicators( PowerBarBox*);
void turnOnPowerBarIndicators( PowerBarBox*);
void turnOffPowerBarIndicators( PowerBarBox*);
void setPowerBarBoxLevel( PowerBarBox*, int);
void increasePowerBarBoxLevel( PowerBarBox*);
void decreasePowerBarBoxLevel( PowerBarBox*);

void increaseShots( ShotBox*, int);
void increaseScore( TotalScoreBox*, int);
void setPlayer( PlayerBox*, int);
void setPar( ParBox*, int);
void setHit( Hole*, int);
void decreaseBallVelocity( Ball*, int);
void increaseBallVelocity( Ball*, int);
void setBallPos( Ball* , int, int);

void moveBall( Ball*);
void ballMoving( Ball*);
void ballStop( Ball*);
void setTile( TileGrid*, int , int , UINT8);

int checkTile( TileGrid*, int, int);
void ballAngleInvert( Ball *);
void invertBallAngleHorizontal( Ball*);
void invertBallAngleVertical( Ball*);
void ballWallAngleCollision(Ball*, TileGrid*);
int checkTopBallPos(Ball*, TileGrid*);
int checkRightBallPos(Ball*,  TileGrid*);
int checkLeftBallPos( Ball*,  TileGrid*);
int checkBottomBallPos(Ball*,  TileGrid*);
void checkForHighPriCollision( Ball*, TileGrid*);

#endif
