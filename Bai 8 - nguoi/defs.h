#ifndef _DEFS__H
#define _DEFS__H

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const char* WINDOW_TITLE = "Hello World!";

const char* MAN_SPRITE_FILE = "img\\foo.png";
const int MAN_CLIPS[][4] = {
    {  0, 0, 64, 205},
    { 64, 0, 64, 205},
    {128, 0, 64, 205},
    {192, 0, 64, 205}};
const int MAN_FRAMES = sizeof(MAN_CLIPS)/sizeof(int)/4;


#endif

