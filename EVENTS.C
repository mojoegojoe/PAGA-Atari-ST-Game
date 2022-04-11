/*
Name:       Soren Bradley, Joe Spurway
Email:      sbrad910@mtroyal.ca
Course:     COMP 2659-001
Semester:   Winter 2022
Instructor: Paul Pospisil

Project: Puals Astro Golf Adventure (Paga)

File: EVENTS.C

Purpose: Module for processing the events of the game
*/
#include "EVENTS.H"
#define MOUSE_WIDTH 8
#define MOUSE_HEIGHT 8


/**
 * Name: event_ball_rotate_toRight
 * Purpose: The ball rotates one postion to the right of its current state.
 * Input:
 *     struct Ball *ball: Ball object being acted upon
 * Return: void
**/
void event_ball_rotate_toRight(Ball *ball) {
    if (ball->angle < 11) {
        ball->angle += 1;
    } else {
        ball->angle = 0;
    }
}

/**
 * Name: event_ball_rotate_toLeft
 * Purpose: The ball rotates one postion to the left of its current state.
 * Input:
 *     struct Ball *ball: Ball object being acted upon
 * Return: void
 */
void event_ball_rotate_toLeft(Ball *ball) {
    if (ball->angle > 0) {
        ball->angle -= 1;
    } else {
        ball->angle = 11;
    }
}

/**
 * Name: event_ball_power_Up
 * Purpose: The ball's power modifier is increased by one from its current state.
 * Input:
 *     struct Ball *ball: Ball object being acted upon
 * Return: void
**/
void event_ball_power_Up(Ball *ball) {
    if (ball->power_level < MAX_POWER) {
        ball->power_level += 1;
    } else {
        ball->power_level = 10;
    }
}

/**
 * Name: event_ball_power_Down
 * Purpose: The ball's power modifier is decreased by one from its current state.
 * Input:
 *     struct Ball *ball: Ball object being acted upon
 * Return: void
**/
void event_ball_power_Down(Ball *ball) {
    if (ball->power_level > 0) {
        ball->power_level -= 1;
    } else {
        ball->power_level = 0;
    }
}

/* Sync  */
/**
 * check_collision
 * checks if the two objects overlap
 * @param obj1X
 * @param obj1Y
 * @param obj1Width
 * @param obj1Height
 * @param obj2X
 * @param obj2Y
 * @param obj2Width
 * @param obj2Height
 * @return 1 if objects overlap and 0 if they don't
 */
int check_collision(int obj1X, int obj1Y, int obj1Width,
                    int obj1Height, int obj2X, int obj2Y,
                    int obj2Width, int obj2Height) {
    return ((obj1X + obj1Width) >= (obj2X) &&
            (obj1X) <= (obj2X + obj2Width) &&
            (obj1Y + obj1Height) >= (obj2Y) &&
            (obj1Y) <= (obj2Y + obj2Height));
}

/**
 * is_portal_collision
 * check if ball collides with a portal
 * @param ball
 * @param portal
 * @return 1 if ball collides with portal
 */
int is_portal_collision(Ball *ball, Portal *portal) {
    return check_collision(ball->posX, ball->posY, BALL_WIDTH, BALL_HEIGHT,
                           portal->posX, portal->posY, PORTAL_WIDTH, PORTAL_HEIGHT);
}

/**
 * is_hole_collision
 * checks if ball collides with the hole
 * @param ball
 * @param hole
 * @return 1 if ball collides with hole
 */
int is_hole_collision(Ball *ball, Hole *hole) {
    return check_collision(ball->posX, ball->posY, BALL_WIDTH, BALL_HEIGHT,
                           hole->posX + 6, hole->posY + 6, 4, 4);
}

/**
 * is_mouse_start_collision
 * checks if mouse collides with the start option of the StartBox
 * @param mouse
 * @return
 */
int is_mouse_start_collision(Mouse *mouse, StartBox * start) {
    return check_collision(mouse->posX, mouse->posY, MOUSE_WIDTH, MOUSE_HEIGHT,
                           start->posX, start->posY, start->width, start->height);
}

/**
 * is_mouse_retry_collision
 * checks if mouse collides with the retry option of the RetryBox
 * @param mouse
 * @return
 */
int is_mouse_retry_collision(Mouse *mouse, RetryBox * retry) {
    return check_collision(mouse->posX, mouse->posY, MOUSE_WIDTH, MOUSE_HEIGHT,
                           retry->posX, retry->posY, retry->width, retry->height);
}

/**
 * is_mouse_quit_collision
 * checks if mouse collides with the quit option of the QuitBox
 * @param mouse
 * @return
 */
int is_mouse_quit_collision(Mouse *mouse, QuitBox * quit) {
    return check_collision(mouse->posX, mouse->posY, MOUSE_WIDTH, MOUSE_HEIGHT,
                           quit->posX, quit->posY, quit->width, quit->height);
}

/**
 * check_tile_collision
 * checks which object the ball is colliding with at a tile.
 * @param ball
 * @param grid
 * @return the object code of the object at the tile the ball is on
 */
int check_tile_collision(Ball *ball,
                         TileGrid *grid) { /** 0 ground collision, 1 portal collision, 2 wall collision, 3 hole collision**/
    return checkTile(grid, (ball->posX), (ball->posY));
}

/**
 * Name: event_ground_pass
 * Purpose: The ball is crossing a ground tile.
 * Input:
 *     struct Ball *ball: Ball object being acted upon
 *     struct MapBox map: Map object being refrenced to
 * Return: void
**/
void event_ground_pass(Ball *ball, MapBox *map) {
    /** check that ball collides with the object **/
    /** ground will always collide               **/
    int portal_posX = ((ball->posX) >> 4);
    int portal_posY = ((ball->posY) >> 4);
    UINT32 *ground_ref;
    int friction;
    TileGrid *grid = &(map->playSpace);
    decreaseBallVelocity(ball, GROUND_FRICTION);
    if (ball->velocity > 0) {
        ballMoving(ball);
    } else {
        ballStop(ball);
    }
}

/**
 * Name: event_portal_hit
 * Purpose: The ball is crossing a portal tile.
 * Input:
 *     struct Ball *ball: Ball object being acted upon
 *     struct MapBox map: Map object being refrenced to
 * Return: void
**/
void event_portal_hit(Ball *ball, MapBox *map) {
    int portal_posX = ((ball->posX) >> 4);
    int portal_posY = ((ball->posY) >> 4);
    TileGrid *grid = &(map->playSpace);
    if (map->portals[0].active == ON && map->portals[1].active == ON) {
        if (is_portal_collision(ball, &(map->portals[0])) == 1) {
            setBallPos(ball, map->portals[1].posX, map->portals[1].posY);
            map->portals[1].active = OFF;
            map->portals[0].active = OFF;
        } else if (is_portal_collision(ball, &(map->portals[1])) == 1) {
            setBallPos(ball, map->portals[0].posX, map->portals[0].posY);
            map->portals[0].active = OFF;
            map->portals[1].active = OFF;

        }
    }
}

/**
 * Name: event_wall_hit
 * Purpose: The ball hits a wall tile.
 * Input:
 *     struct Ball *ball: Ball object being acted upon
 *     struct MapBox map: Map object being refrenced to
 * Return: void
**/
void event_wall_hit(Ball *ball, MapBox *map) {
    TileGrid *grid = &(map->playSpace);
    ballWallAngleCollision(ball, grid);
}

/**
 * Name: event_hole_hit
 * Purpose: The ball hits a hole tile.
 * Input:
 *     struct Ball *ball: Ball object being acted upon
 *     struct MapBox map: Map object being refrenced to
 * Return: void
**/
void event_hole_hit(Ball *ball, MapBox *map) {
    if (ball->velocity < 100 && is_hole_collision(ball, &(map->hole)) == 1) {
        if (map->hole.hit == 0) {
            setHit(&(map->hole), 1);
        }
    }

}

/**
 * event_update_ball_power
 * Updates the balls powerlevel to the powerlevel of the power precentage.
 * @param screen the model containing the ball and power precentage
 */
void event_update_ball_power(Model *screen) {
    screen->map_box.ball.power_level = screen->stat_box.power_bar_box.power_precentage.percent;
}

/**
 * event_ball_collides
 * Check for the highest priority collision of the ball and processed the corresponding event based on
 * the collision type
 * @param screen
 */
void event_ball_collides(Model *screen) {
    checkForHighPriCollision(&screen->map_box.ball, &screen->map_box.playSpace);
    switch (screen->map_box.ball.collision_type) {       /** ball currently resides within: **/
        case GROUND: /** a gound tile                   **/
            event_ground_pass(&(screen->map_box.ball), &(screen->map_box));
            break;
        case PORTAL: /** a portal tile                  **/
            event_portal_hit(&(screen->map_box.ball), &(screen->map_box));
            break;
        case WALL: /** a wall tile                    **/
            event_wall_hit(&(screen->map_box.ball), &(screen->map_box));
            break;
        case HOLE: /** a hole tile                    **/
            event_hole_hit(&(screen->map_box.ball), &(screen->map_box));
            break;
    }

}

/**
 * event_ball_moving
 * Moves the ball in the model, processing the collisions of the ball each movement. Terminates game if ball
 * hits hole.
 * @param screen
 */
void event_ball_moving(Model *screen) {
    if (screen->map_box.ball.moving == MOVING) {
        moveBall(&(screen->map_box.ball));
        event_ball_collides(screen);
    } else {
        screen->state = STAGING;
    }
    if (screen->map_box.hole.hit == HOLE_HIT) {
        screen->state = GAME_OVER;
    }

}

/**
 * Name: event_ball_shot
 * Purpose: The ball is moved dependednt on the tile it crosses.
 * Input:
 *     struct Ball *ball: Ball object being acted upon
 *     struct MapBox *map: Map object being refrenced to
 * Return: void
**/
void event_shot(Model *screen) {
    screen->state = MOVING;
    screen->map_box.ball.moving = MOVING;
    increaseShots(&screen->stat_box.shot_box, screen->stat_box.shot_box.shots + 1);
    if (screen->stat_box.power_bar_box.power_precentage.percent > 0) {
        setBallVelocity(&screen->map_box.ball, (screen->map_box.ball.power_level << 6));
        event_ball_moving(screen);
    }
    if (screen->map_box.hole.hit != HOLE_HIT) {
        increaseScore(&screen->stat_box.total_score_box, screen->stat_box.total_score_box.score + 1);
    }
    if (screen->map_box.portals[0].active == 0 && screen->map_box.portals[1].active == 0) {
        screen->map_box.portals[0].active = ON;
        screen->map_box.portals[1].active = ON;
    }
}

/**
 * event_power_Up
 * Sets the power bar box indicators to the power-level of the power present and propagates changes to ball
 * @param screen
 */
void event_power_Up(Model *screen) {

    if (screen->map_box.ball.power_level < MAX_POWER) {
        increasePowerBarBoxLevel(&(screen->stat_box.power_bar_box));
        turnOnPowerBarIndicators(&(screen->stat_box.power_bar_box));
        event_update_ball_power(screen);
    } else {
        setPowerBarBoxLevel(&(screen->stat_box.power_bar_box), MAX_POWER);
        turnOnPowerBarIndicators(&(screen->stat_box.power_bar_box));
        event_update_ball_power(screen);

    }
}

/**
 * Name: event_power_Down
 * Purpose: The ball's power modifier is decreased by one from its current state.
 * Input:
 *     struct Ball *ball: Ball object being acted upon
 * Return: void
**/
void event_power_Down(Model *screen) {
    if (screen->stat_box.power_bar_box.power_precentage.percent > 0) {
        screen->stat_box.power_bar_box.power_precentage.percent -= 1;
        turnOffPowerBarIndicators(&(screen->stat_box.power_bar_box));
        event_update_ball_power(screen);
    } else {
        setPowerBarBoxLevel(&(screen->stat_box.power_bar_box), 0);
        resetPowerBarIndicators(&(screen->stat_box.power_bar_box));
        event_update_ball_power(screen);
    }
}

/**
 * event_ball_stops
 * stops the ball and resets power level of power bar box and power bar indicators
 * @param screen
 */
void event_ball_stops(Model *screen) {
    /**setBallAngle(&screen->map_box.ball, 0);**/
    setBallPower(&screen->map_box.ball, 0);
    setPowerBarBoxLevel(&(screen->stat_box.power_bar_box), 0);
    resetPowerBarIndicators(&(screen->stat_box.power_bar_box));
}

/**
 *  event_reset_ball
 *  Resets the ball and configurable options in the statbox
 * @param model the model
 * @param ball_posX new ball x position
 * @param ball_posY new ball y position
 */
void event_reset_ball(Model *model, int ball_posX, int ball_posY) {
    model->map_box.ball.posX = ball_posX;
    model->map_box.ball.posY = ball_posY;
    model->map_box.ball.ball_direct_box.posX = ball_posX - BALL_DIRECTION_PTR_OFFSET;
    model->map_box.ball.ball_direct_box.posY = ball_posY - BALL_DIRECTION_PTR_OFFSET;
    model->map_box.hole.hit = 0;
    model->stat_box.total_score_box.score = 0;
    model->stat_box.shot_box.shots = 0;
    model->map_box.ball.power_level = 0;
    model->stat_box.power_bar_box.power_precentage.percent = 0;
    turnOffPowerBarIndicators(&(model->stat_box.power_bar_box));
}