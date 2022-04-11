/*
Name:       Soren Bradley, Joe Spurway
Email:      sbrad910@mtroyal.ca
Course:     COMP 2659-001
Semester:   Winter 2022
Instructor: Paul Pospisil

Project: Puals Astro Golf Adventure (Paga)

File: RENDERER.C

Purpose: Is the glue between model and raster. Allows us to be able to render our model
*/
#include "RENDERER.H"

/**
 * @brief renderPlayerBox
 *      renders Player text and the player number
 * @param base 
 * @param player 
 */
void renderPlayerBox(UINT8 *base, PlayerBox *player)
{
    plot_text(base, player->posX, player->posY, player_text, 7);
    plot_number(base, (PLAYERBOX_X + 56), PLAYERBOX_Y, number_text, player->player);
}
/**
 * @brief renderTotalScoreNumber
 *  clears then renders the current total score data
 * @param base 
 * @param total_score 
 */
void renderTotalScoreNumber(UINT8 *base, TotalScoreBox *total_score)
{
    if(((total_score->score/100)%10) != 0){
        plot_number(base, (TOTALSCOREBOX_X + 56), TOTALSCOREBOX_Y, number_text, ((total_score->score/100)%10));
    }
    if(((total_score->score/10)%10) != 0){
        plot_number(base, (TOTALSCOREBOX_X + 64), TOTALSCOREBOX_Y, number_text, ((total_score->score/10)%10));
    }
    plot_number(base, (TOTALSCOREBOX_X + 72), TOTALSCOREBOX_Y, number_text, ((total_score->score)%10));
}
/**
 * @brief renderTotalScoreBox
 *      renders the score text and calls for total score
 * @param base 
 * @param total_score 
 */
void renderTotalScoreBox(UINT8 *base, TotalScoreBox *total_score)
{
    plot_text(base, total_score->posX, total_score->posY, score_text, 6);
}
/**
 * @brief renderMapNumberBox
 *      renders the map text and calls to plot the map number
 * @param base 
 * @param map_number 
 */
void renderMapNumberBox(UINT8 *base, MapNumberBox *map_number)
{
    plot_text(base, map_number->posX, map_number->posY, map_number_text, 5);
    plot_number(base, (MAPNUMBER_X + 56), MAPNUMBER_Y, number_text, map_number->map_num);
}
/**
 * @brief renderParBox
 *      renders the par text and calls to plot the par number 
 * @param base 
 * @param par 
 */
void renderParBox(UINT8 *base, ParBox *par)
{
    plot_text(base, par->posX, par->posY, par_text, 4);
    plot_number(base, (PARBOX_X + 56), PARBOX_Y, number_text, par->par_num);
}
/**
 * @brief renderShotsNumber
 *      clears and then renders the shot number 
 * @param base 
 * @param shots 
 */
void renderShotsNumber(UINT8 *base, ShotBox *shots)
{
    if(((shots->shots/10)%10) != 0){
        plot_number(base, (SHOTBOX_X + 64), SHOTBOX_Y, number_text, ((shots->shots/10)%10));
    }
    plot_number(base, (SHOTBOX_X + 72), SHOTBOX_Y, number_text, ((shots->shots)%10));
}
/**
 * @brief renderShotBox
 *      renders the shot text and calls to plot the shot number
 * @param base 
 * @param shots 
 */
void renderShotBox(UINT8 *base, ShotBox *shots)
{
    plot_text(base, shots->posX, shots->posY, shots_text, 6);
}
/**
 * @brief renderPowerText
 *      renders just power text 
 * @param base 
 * @param power_txt 
 */
void renderPowerText(UINT8 *base, PowerText *power_txt)
{
    plot_text(base, power_txt->posX, power_txt->posY, power_text, 6);
}
/**
 * @brief renderPowerBarIndicator
 *      clears and renders the whole power bar 
 * @param base 
 * @param power_indicator 
 */
void renderPowerBarIndicator(UINT16 *base, PowerBarIndicator *power_indicator)
{
    if (power_indicator->on == POWER_BAR_IND_ON)
    {
        plot_bitmap_16_unsafe(base, power_indicator->posX, power_indicator->posY, power_indicator_on, POWER_INDICATOR_HEIGHT);
    }
    else
    {
        plot_bitmap_16_unsafe(base, power_indicator->posX, power_indicator->posY, power_indicator_off, POWER_INDICATOR_HEIGHT);
    }
}
/**
 * @brief renderPowerPercentage
 *         clears and renders the current power bar percentage  
 * @param base 
 * @param power_percent 
 */
void renderPowerPercentage(UINT8 *base,  PowerPercentage *power_percent)
{
    if (power_percent->percent == MAX_POWER_PERCENT)
    {
        plot_number(base, (power_percent->posX), power_percent->posY, number_text, 1);
        plot_number(base, (power_percent->posX + TEXT_NUMBER_SIZE), power_percent->posY, number_text, 0);
    }else if (power_percent->percent != 0){
        plot_number(base, (power_percent->posX + TEXT_NUMBER_SIZE), power_percent->posY, number_text, power_percent->percent);
    }
    plot_number(base, (power_percent->posX + TEXT_NUMBER_OFFSET_BY_ONE), power_percent->posY, number_text, 0);
    plot_number(base, (power_percent->posX + TEXT_NUMBER_OFFSET_BY_TWO), power_percent->posY, number_text, 10);
}
/**
 * @brief renderPowerBarBox
 *      complete the complete rendering of all components of the power box
 * @param base 
 * @param power_bar_box 
 */
void renderPowerBarBox(UINT16 *base,  PowerBarBox *power_bar_box)
{
    int i;

        renderPowerText((UINT8 *) base, &(power_bar_box->power_text));
        for (i = 0; i < MAX_POWER_PERCENT; i++) {
            renderPowerBarIndicator(base, &(power_bar_box->bar_indicators[i]));
        }
    renderPowerPercentage((UINT8 *)base, &(power_bar_box->power_precentage));
}
/**
 * @brief renderStatBox
 *      renders the whole statistic box
 * @param base 
 * @param stat_box 
 */
void renderStatBox(UINT16 *base, StatBox *stat_box)
{
    renderPowerBarBox(base, &(stat_box->power_bar_box));
    renderTotalScoreBox((UINT8 *)base, &(stat_box->total_score_box));
    renderMapNumberBox((UINT8 *)base, &(stat_box->map_number_box));
    renderParBox((UINT8 *)base, &(stat_box->par_box));
    renderShotBox((UINT8 *)base, &(stat_box->shot_box));
    renderPlayerBox((UINT8 *)base, &(stat_box->player_box));
}
/**
 * @brief renderBallDirectionPointer
 *      renders the ball direction pointer dependent on the angle given
 * @param base 
 * @param direct_ptr 
 * @param angle 
 */
void renderBallDirectionPointer(UINT32 *base,  BallDirectionPointer *direct_ptr, int angle)
{
    switch (angle)
    {
    case NORTH_ARROW:
        plot_bitmap_16((UINT16* ) base, direct_ptr->posX, direct_ptr->posY, NNN_arrow, DIRECTION_POINTER_HEIGHT);
        break;
    case NORTH_NORTH_EAST_ARROW:
        plot_bitmap_16((UINT16* ) base, direct_ptr->posX, direct_ptr->posY, NNE_arrow, DIRECTION_POINTER_HEIGHT);
        break;
    case NORTH_EAST_EAST_ARROW:
        plot_bitmap_16((UINT16* ) base, direct_ptr->posX, direct_ptr->posY, NEE_arrow, DIRECTION_POINTER_HEIGHT);
        break;
    case EAST_ARROW:
        plot_bitmap_16((UINT16* ) base, direct_ptr->posX, direct_ptr->posY, EEE_arrow, DIRECTION_POINTER_HEIGHT);
        break;
    case SOUTH_NORTH_EAST_ARROW:
        plot_bitmap_16((UINT16* ) base, direct_ptr->posX, direct_ptr->posY, SNE_arrow, DIRECTION_POINTER_HEIGHT);
        break;
    case SOUTH_SOUTH_EAST_ARROW:
        plot_bitmap_16((UINT16* ) base, direct_ptr->posX, direct_ptr->posY, SSE_arrow, DIRECTION_POINTER_HEIGHT);
        break;
    case SOUTH_ARROW:
        plot_bitmap_16((UINT16* ) base, direct_ptr->posX, direct_ptr->posY, SSS_arrow, DIRECTION_POINTER_HEIGHT);
        break;
    case SOUTH_SOUTH_WEST_ARROW:
        plot_bitmap_16((UINT16* ) base, direct_ptr->posX, direct_ptr->posY, SSW_arrow, DIRECTION_POINTER_HEIGHT);
        break;
    case SOUTH_WEST_WEST_ARROW:
        plot_bitmap_16((UINT16* ) base, direct_ptr->posX, direct_ptr->posY, SWW_arrow, DIRECTION_POINTER_HEIGHT);
        break;
    case WEST_ARROW:
        plot_bitmap_16((UINT16* ) base, direct_ptr->posX, direct_ptr->posY, WWW_arrow, DIRECTION_POINTER_HEIGHT);
        break;
    case WEST_SOUTH_WEST_ARROW:
        plot_bitmap_16((UINT16* ) base, direct_ptr->posX, direct_ptr->posY, WSW_arrow, DIRECTION_POINTER_HEIGHT);
        break;
    case WEST_NORTH_NORTH_ARROW:
        plot_bitmap_16((UINT16* ) base, direct_ptr->posX, direct_ptr->posY, WNN_arrow, DIRECTION_POINTER_HEIGHT);
        break;
    }
}
/**
 * @brief renderBall
 *      plots the ball and its pointers if its stationary
 * @param base 
 * @param ball 
 */
void renderBall(UINT8 *base, Ball *ball)
{
    plot_bitmap_8(base, ball->posX, ball->posY, ball_small, BALL_HEIGHT);
}
/**
 * @brief renderPortal 
 *      renders a portal at its current position
 * @param base 
 * @param portal 
 */
void renderPortal(UINT16 *base, Portal *portal)
{
    if (portal->active == PORTAL_DEACTIVATED) {
        plot_bitmap_16_unsafe(base, portal->posX, portal->posY, portal_inactive, PORTAL_HEIGHT);
    } else {
        plot_bitmap_16_unsafe(base, portal->posX, portal->posY, portal_active, PORTAL_HEIGHT);
    }
}
/**
 * @brief renderHole
 *      renders a hole at its current postion 
 * @param base 
 * @param hole 
 */
void renderHole(UINT16 *base, Hole *hole)
{
    plot_bitmap_16_unsafe(base, hole->posX, hole->posY, hole_bitmap, HOLE_HEIGHT);
}
/**
 * @brief renderTile
 *      renders the tile based on the object code of the specific tile
 * @param base 
 * @param tile 
 */
void renderTile(UINT16 *base,  Tile *tile)
{
    if (tile->obj_code == GROUND)
    {
        plot_bitmap_16_unsafe(base, tile->posX, tile->posY, ground_tile, GROUND_HEIGHT);
    }
    else if (tile->obj_code == WALL)
    {
        plot_bitmap_16_unsafe(base, tile->posX, tile->posY, wall_tile, WALL_HEIGHT);
    }
}
/**
 * @brief renderTileGrid
 *      for each tile in the tile grid we render it current state
 * @param base 
 * @param tile_grid 
 */
void renderTileGrid(UINT16 *base,  TileGrid *tile_grid)
{
    int i, j;
    for (i = 0; i < TILE_GRID_HEIGHT; i++)
    {
        for (j = 0; j < TILE_GRID_WIDTH; j++)
        {
            renderTile(base, &(tile_grid->tile_grid[i][j]));
        }
    }
}
/**
 * @brief renderMapBox
 *      renders all the components that make up the map 
 * @param base 
 * @param map 
 */
void renderMapBox(UINT16 *base,  MapBox *map)
{
    renderTileGrid(base, &(map->playSpace));
    renderBall((UINT8 *)base, &(map->ball));
}
/**
 * @brief renderScreen
 *      renders both the map and statistics to the screen 
 * @param base 
 * @param screen 
 */
void renderScreen(UINT16 *base,  Model *screen)
{
    renderMapBox(base, &(screen->map_box));
    if (screen->map_box.ball.moving == BALL_STOPPED) {
        renderBallDirectionPointer((UINT32*) base,
                                   &screen->map_box.ball.ball_direct_box,
                                   screen->map_box.ball.angle);
    }
    renderStatBox(base, &(screen->stat_box));
}
/**
 * @brief updateBallDetails
 *      updates by clearing and rendering the ball and its objects
 * 
 * @param base 
 * @param screen 
 */
void updateBallDetails(UINT8* base, Model* screen){
    if (screen->state == STAGING) {
        renderBallDirectionPointer((UINT32 *)base,
                                   &screen->map_box.ball.ball_direct_box,
                                   screen->map_box.ball.angle);
    }
    renderBall((UINT8 *)base, &(screen->map_box.ball));
}
/**
 * @brief updateStagingDetails
 *      renders just the changing infomation within stats 
 * @param base 
 * @param screen 
 */
void updateStagingDetails(UINT8* base, Model* screen) {
    renderPowerBarBox((UINT16*) base, &(screen->stat_box.power_bar_box));
    renderShotsNumber(base, &screen->stat_box.shot_box);
    renderTotalScoreNumber(base, &screen->stat_box.total_score_box);
}
/**
 * @brief updateScreen
 *  updates the screen with current data
 * 
 * @param base 
 * @param screen 
 */
void updateScreen(UINT16 *base, Model *screen) {
    if (screen->state == STAGING) {
        updateStagingDetails((UINT8*) base, screen);
    }
    updateBallDetails((UINT8*) base, screen);
}
/**
 *
 * @param base
 */
void clearScreen(UINT32* base) {
    clean_screen(base);
}
/**
 * @brief renderStatic
 *      renders the static objects on the screen 
 * @param base 
 * @param screen 
 */
void renderStatic(UINT16* base, Model * screen) {
    renderTileGrid(base, &screen->map_box.playSpace);
    renderHole(base, &(screen->map_box.hole));
    renderPortal(base, &(screen->map_box.portals[PORTAL_ONE]));
    renderPortal(base, &(screen->map_box.portals[PORTAL_TWO]));
    renderStatBox(base, &screen->stat_box);
}
/**
 * renderMouse
 * renders mouse 
 * @param base
 * @param mouse
 */
void renderMouse(UINT8* base, Mouse * mouse) {
    plot_bitmap_8(base, mouse->posX, mouse->posY, mouse_ball, BALL_HEIGHT);
}
/**
 * renderSplashScreen
 * prints splash screen
 * @param base
 */
void renderSplashScreen(UINT32* base){
    print_screen((UINT8 *)base,splash_screen);
}
/**
 * renderEndScreen 
 * renders end screen
 * @param base
 * @param model
 */
void renderEndScreen(UINT32* base, EndScreen * end) {
    print_screen((UINT8 *)base,end_screen);
    plot_text((UINT8 *)base, END_SCREEN_TEXT_SCORE_X_POS, END_SCREEN_TEXT_SCORE_Y_POS, score_text, 6);
    if(((end->final_score/10)%10) != 0){
        plot_number((UINT8*)base,
                    (END_SCREEN_TEXT_SCORE_X_POS + END_SCREEN_MSD_OFFSET),
                    END_SCREEN_TEXT_SCORE_Y_POS,
                    number_text,
                    ((end->final_score/10)%10));
    }
    plot_number((UINT8*)base,
                (END_SCREEN_TEXT_SCORE_X_POS + END_SCREEN_LSD_OFFSET),
                END_SCREEN_TEXT_SCORE_Y_POS,
                number_text,
                ((end->final_score)%10));

    if (end->is_hole_hit == HOLE_NOT_HIT) {
        plot_text((UINT8*) base,
                  END_SCREEN_NO_HOLE_MSG_POSX,
                  END_SCREEN_MSG_POSY,
                  no_ball_hit,
                  18);
    } else {
        plot_text((UINT8*) base,
                  END_SCREEN_HOLE_MSG_POSX,
                  END_SCREEN_MSG_POSY,
                  ball_hit,
                  21);
    }
}




