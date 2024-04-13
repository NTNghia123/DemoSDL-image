#pragma once

#include "defs.h"
#define INITIAL_SPEED 3

struct Mouse {
    int x, y;
    int dx = 0, dy = 0;
    int speed = INITIAL_SPEED;
    void movee();
    void turnNorth();
    void turnSouth();
    void turnWest();
    void turnEast();
    void updateKeyboard();
    void check ();
};



