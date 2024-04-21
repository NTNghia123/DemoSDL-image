#ifndef _DEFS__H
#define _DEFS__H

#define BG_IMAGE "img\\sky_crop.jpg" // cho scroll
#define STATIC_BG_IMAGE "img\\grass_field_resize_afterAse.jpg"
#define WINDOW_TITLE "Hello World!"
#define TOWER_EXPLODE_FILE "img\\tower_exploding_new.png"
//#define TEST "img\\adventurer-bow-Sheet.png"
#define PLAYER_NORMAL_IMG "img\\normal.png"
#define PLAYER_JUMPING_IMG "img\\jumpp.png"
#define PLAYER_SHOOTING_IMG "img\\shoot1.png"
#define ARROW_IMG "img\\arrow.png"
#define HEALTH_BAR "img\\health_bar.png"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 500;
const int FPS = 10;

const int MAX_KEYBOARD_KEYS = 350;
const int INIT_X = 110;
const int INIT_Y = 170;
const int BG_SCROLL_SPEED = 1;


const int BIRD_CLIPS[][4] = {
    {0, 0, 182, 168},
    {181, 0, 182, 168},
    {364, 0, 182, 168},
    {547, 0, 182, 168},
    {728, 0, 182, 168},

    {0, 170, 182, 168},
    {181, 170, 182, 168},
    {364, 170, 182, 168},
    {547, 170, 182, 168},
    {728, 170, 182, 168},

    {0, 340, 182, 168},
    {181, 340, 182, 168},
    {364, 340, 182, 168},
    {547, 340, 182, 168},
};
const int BIRD_FRAMES = sizeof(BIRD_CLIPS)/sizeof(int)/4;

const int TOWER_EXPLODE_CLIPS[][4] ={
    {1476,663,492,663},
    {0,0,492,663},
    {492,0,492,663},
    {984,0,492,663},
    {1476,0,492,663},
    {0,663,492,663},
    {492,663,492,663},
    {984,663,492,663},
    {1476,663,492,663}
};
const int TOWER_EXPLODE_FRAMES = 8;

const int HEALTH_BAR_CLIPS[][4] = {
    {0,0,224,83},
    {0,83,224,83},
    {0,166,224,83},
    {0,250,224,83},
    {0,333,224,83},
    {0,416,224,83}
};
const int HEALTH_BAR_FRAMES = 6;

const int PLAYER_CLIPS[][4] = {
    {0,0,119,119},
    {119,0,119,119}
};
const int PLAYER_FRAMES = 2;



#endif

