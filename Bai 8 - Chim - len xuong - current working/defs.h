#ifndef _DEFS__H
#define _DEFS__H

#define BG_IMAGE "img\\forest.jpg"
#define WINDOW_TITLE "Hello World!"
#define BIRD_SPRITE_FILE "img\\sprite.png"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

const int INIT_X = 100;
const int INIT_Y = 200;
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

#endif

