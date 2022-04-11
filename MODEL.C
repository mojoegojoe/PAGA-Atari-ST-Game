/*
Name:       Soren Bradley, Joe Spurway
Email:      sbrad910@mtroyal.ca
Course:     COMP 2659-001
Semester:   Winter 2022
Instructor: Paul Pospisil

Project: Puals Astro Golf Adventure (Paga)

File: MODEL.C

Purpose: Contains the model of the game and its smaller parts
*/
#include "MODEL.H"

const int invert_angle_matrix[12][2] = {
        {6,  6},  /**angle 0, side hit inverse NA , top/bottom 6**/
        {5,  11}, /**angle 1, side hit inverse 5 , top/bottom 11**/
        {4,  10}, /**angle 2, side hit inverse 4 , top/bottom 10**/
        {9,  9},  /**angle 3, side hit inverse 9 , top/bottom NA**/
        {2,  8},  /**angle 4, side hit inverse 2 , top/bottom 8**/
        {1,  7},  /**angle 5, side hit inverse 1 , top/bottom 7**/
        {0,  0},  /**angle 6, side hit inverse NA , top/bottom 6**/
        {11, 5}, /**angle 7, side hit inverse 5 , top/bottom 10**/
        {10, 4}, /**angle 8, side hit inverse 4 , top/bottom 11**/
        {3,  3},  /**angle 9, side hit inverse 3 , top/bottom NA**/
        {8,  2},  /**angle 10, side hit inverse 2 , top/bottom 7**/
        {7,  1}   /**angle 11, side hit inverse 1 , top/bottom 8**/
};
const int moveX[12] = {0, 2, 3, 2, 3, 2, 0, -2, -3, -2, -3, -2};
const int moveY[12] = {-2, -3, -2, 0, 2, 3, 2, 3, 2, 0, -2, -3};

/**
 * setBallAngle
 * sets a ball struct angle to a new angle
 * @param ball Ball struct
 * @param new_angle new angle
 */
void setBallAngle(Ball *ball, int new_angle) {
    ball->angle = new_angle;
}

/**
 *  setBallVelocity
 * @param ball
 * @param new_velocity
 */
void setBallVelocity(Ball *ball, int new_velocity) {
    ball->velocity = new_velocity;
}

/**
 *
 * @param ball
 * @param power
 */
void setBallPower(Ball *ball, int power) {
    ball->power_level = power;
}

/**
 *
 * @param power_bar
 */
void resetPowerBarIndicators(PowerBarBox *power_bar) {
    int i;
    for (i = 0; i < 10; i++) {
        power_bar->bar_indicators[i].on = OFF;
    }
}

/**
 *
 * @param power_bar
 */
void turnOnPowerBarIndicators(PowerBarBox *power_bar) {
    int i;
    for (i = 0; i < power_bar->power_precentage.percent; i++) {
        power_bar->bar_indicators[i].on = ON;
    }
}

/**
 *
 *
 * @param power_bar
 */
void turnOffPowerBarIndicators(PowerBarBox *power_bar) {
    int i;
    for (i = 9; i >= power_bar->power_precentage.percent; i--) {
        power_bar->bar_indicators[i].on = OFF;
    }
}

/**
 * setPowerBarBoxLevel
 * sets the power bar box level
 * @param power_bar
 * @param power_level
 */
void setPowerBarBoxLevel(PowerBarBox *power_bar, int power_level) {
    power_bar->power_precentage.percent = power_level;
}

/**
 * increasePowerBarBoxLevel
 * increase the powerbarbox percent by one
 * @param power_bar
 */
void increasePowerBarBoxLevel(PowerBarBox *power_bar) {
    power_bar->power_precentage.percent += 1;
}

/**
 * decreasePowerBarBoxLevel
 * decreases the powerbarbox percent by one
 * @param power_bar
 */
void decreasePowerBarBoxLevel(PowerBarBox *power_bar) {
    power_bar->power_precentage.percent -= 1;
}

/**
 * increaseShots
 * increases the number of shots by a given value
 * @param shotbox
 * @param shots
 */
void increaseShots(ShotBox *shotbox, int shots) {
    shotbox->shots = shots;
}

/**
 * increaseScore
 * increases score by given value
 * @param total_score
 * @param score
 */
void increaseScore(TotalScoreBox *total_score, int score) {
    total_score->score = score;
}

/**
 * setPlayer
 * sets player number for player
 * @param player_box
 * @param player_num
 */
void setPlayer(PlayerBox *player_box, int player_num) {
    player_box->player = player_num;
}

/**
 * setPar
 * sets the par of the map
 * @param par_box
 * @param par
 */
void setPar(ParBox *par_box, int par) {
    par_box->par_num = par;
}

/**
 * setHit
 * sets the hole to hit status
 * @param hole
 * @param is_hit
 */
void setHit(Hole *hole, int is_hit) {
    hole->hit = is_hit;
}

/**
 *
 * @brief decreaseBallVelocity
 *     Decrease the balls velocity by a defined value
 *
 *
 * @param ball
 * @param value
 */
void decreaseBallVelocity(Ball *ball, int value) {
    int temp_v = ball->velocity;
    temp_v = temp_v - value;
    if (temp_v <= 0) {
        ball->velocity = 0;
    } else {
        ball->velocity = temp_v;
    }
}

/**
 * @brief increaseBallVelocity
 *
 * @param ball current ball object
 * @param value to decrease by
 */
void increaseBallVelocity(Ball *ball, int value) {
    int temp_v = ball->velocity;
    temp_v = temp_v - value;
    if (temp_v >= 100) {
        ball->velocity = 100;
    } else {
        ball->velocity = temp_v;
    }
}

/**
 * @brief Set the position of the Ball object
 *
 * @param ball
 * @param x
 * @param y
 */
void setBallPos(Ball *ball, int x, int y) {
    ball->posX = x;
    ball->posY = y;
}

/**
 * @brief Move the position of the Ball object
 *
 * @param ball
 */
void moveBall(Ball *ball) {
    ball->last_posX = ball->posX;
    ball->last_posY = ball->posY;
    ball->posX += moveX[ball->angle];
    ball->posY += moveY[ball->angle];
    ball->ball_direct_box.posX = ball->posX - BALL_DIRECTION_PTR_OFFSET;
    ball->ball_direct_box.posY = ball->posY - BALL_DIRECTION_PTR_OFFSET;
}

/**
 * ballMoving
 * Sets ball to moving
 * @param ball
 */
void ballMoving(Ball *ball) {
    ball->moving = 1;
}

/**
 * ballStop
 * sets ball to stop moving
 * @param ball
 */
void ballStop(Ball *ball) {
    ball->moving = BALL_STOPPED;
}

/**
 * @brief Set the Tile object
 *
 * @param grid pointer to the full grid of tiles
 * @param x
 * @param y
 * @param obj_code tile code
 */
void setTile(TileGrid *grid, int x, int y, UINT8 obj_code) {
    int girdPosX = (x >> SHIFT_FOR_WORD_SIZE);
    int girdPosY = (y >> SHIFT_FOR_WORD_SIZE);
    (grid->tile_grid[girdPosX][girdPosY]).obj_code = obj_code;
    (grid->tile_grid[girdPosX][girdPosY]).posX = x;
    (grid->tile_grid[girdPosX][girdPosY]).posY = y;
}

/**
 * @brief checkTile returns the current tile code at [x,y]
 *
 * @param grid
 * @param x
 * @param y
 * @return int
 */
int checkTile(TileGrid *grid, int x, int y) {
    int posX = (x >> SHIFT_FOR_WORD_SIZE);
    int posY = (y >> SHIFT_FOR_WORD_SIZE);
    UINT8 code;
    code = (grid->tile_grid[posY][posX]).obj_code;
    return code;
}

/**
 * @brief ballWallAngleCollision checks to see if a ball object has an impact
 *              with any wall object within the tile grid
 *
 * @param ball
 * @param grid
 * @return int
 */
void ballWallAngleCollision(Ball *ball, TileGrid *grid) {
    if (ball->collision_loc == BALL_TOP_SIDE_COLLISION &&
        (ball->angle > BALL_TOP_MAX_ANGLE || ball->angle < BALL_TOP_MIN_ANGLE))
    { /** check top **/
        ball->angle = invert_angle_matrix[ball->angle][0];
    }
    else if (ball->collision_loc == BALL_RIGHT_SIDE_COLLISION && (ball->angle >= BALL_RIGHT_MIN_ANGLE && ball->angle <= BALL_RIGHT_MAX_ANGLE))
    { /** check right **/
        ball->angle = invert_angle_matrix[ball->angle][1];
    }
    else if (ball->collision_loc == BALL_BOTTOM_SIDE_COLLISION && (ball->angle <= BALL_BOTTOM_MAX_ANGLE && ball->angle >= BALL_RIGHT_MIN_ANGLE))
    { /** check bottom **/
        ball->angle = invert_angle_matrix[ball->angle][0];
    }
    else if (ball->collision_loc == BALL_LEFT_SIDE_COLLISION && (ball->angle >= BALL_LEFT_MIN_ANGLE && ball->angle <= BALL_LEFT_MAX_ANGLE))
    { /** check left **/
        ball->angle = invert_angle_matrix[ball->angle][1];
    }
}

/**
 *
 * @param ball
 * @param grid
 * @return
 */
int checkTopBallPos(Ball *ball, TileGrid *grid) {
    int obj_code = checkTile(grid, ball->posX + BALL_MID_POS_OFFSET, ball->posY);
    return obj_code;
}

/**
 *
 * @param ball
 * @param grid
 * @return
 */
int checkRightBallPos(Ball *ball, TileGrid *grid) {
    int obj_code = checkTile(grid, ball->posX + BALL_FAR_POS_OFFSET, ball->posY + BALL_MID_POS_OFFSET);
    return obj_code;
}

/**
 *
 * @param ball
 * @param grid
 * @return
 */
int checkLeftBallPos(Ball *ball, TileGrid *grid) {
    int obj_code = checkTile(grid, ball->posX, ball->posY + BALL_MID_POS_OFFSET);
    return obj_code;
}

/**
 *
 * @param ball
 * @param grid
 * @return
 */
int checkBottomBallPos(Ball *ball, TileGrid *grid) {
    int obj_code = checkTile(grid, ball->posX + BALL_MID_POS_OFFSET, ball->posY + BALL_FAR_POS_OFFSET);
    return obj_code;
}

/**
 *
 * @param ball
 * @param grid
 */
void checkForHighPriCollision(Ball *ball, TileGrid *grid) {
    ball->collision_type = 0; /** 0 defualt, a portion of the ball will always collide with a ground object **/
    ball->collision_loc = 0;  /** 0 defualt, 1 top side, 2 right side, 3 bottom side, 4 left side **/
    if (ball->collision_type < checkTopBallPos(ball, grid)) {
        if (checkTopBallPos(ball, grid) != HOLE && checkTopBallPos(ball, grid) != PORTAL) {
            if (checkTopBallPos(ball, grid) == checkLeftBallPos(ball, grid)) {
                ball->collision_loc = BALL_LEFT;
                ball->posX = ball->last_posX;
                ball->posY += JUMP_BALL;
            } else if (checkTopBallPos(ball, grid) == checkRightBallPos(ball, grid)) {
                ball->collision_loc = 2;
                ball->posX = ball->last_posX;
                ball->posY += JUMP_BALL;
            } else {
                ball->collision_loc = BALL_TOP;
            }
        }
        ball->collision_type = checkTopBallPos(ball, grid);
    }
    if (ball->collision_type < checkBottomBallPos(ball, grid)) {
        if (checkBottomBallPos(ball, grid) != HOLE && checkBottomBallPos(ball, grid) != PORTAL) {
            if (checkBottomBallPos(ball, grid) == checkLeftBallPos(ball, grid)) {
                ball->collision_loc = BALL_LEFT;
                ball->posX = ball->last_posX;
                ball->posY -= JUMP_BALL;
            } else if (checkBottomBallPos(ball, grid) == checkRightBallPos(ball, grid)) {
                ball->collision_loc = BALL_RIGHT;
                ball->posX = ball->last_posX;
                ball->posY -= JUMP_BALL + 1;
            } else {
                ball->collision_loc = BALL_BOTTOM;
            }
        }
        ball->collision_type = checkBottomBallPos(ball, grid);
    }
    if (ball->collision_type < checkRightBallPos(ball, grid)) {
        ball->collision_loc = BALL_RIGHT;
        ball->collision_type = checkRightBallPos(ball, grid);
    }

    if (ball->collision_type < checkLeftBallPos(ball, grid)) {
        ball->collision_loc = BALL_LEFT;
        ball->collision_type = checkLeftBallPos(ball, grid);
    }
}

