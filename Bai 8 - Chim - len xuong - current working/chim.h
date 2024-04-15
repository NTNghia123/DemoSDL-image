#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include "defs.h"

#define INITIAL_SPEED 80


struct Sprite {
    SDL_Texture* texture;

};

struct ToaDo {
    int x = INIT_X;
    int y = INIT_Y;
    int dx = 0;
    int dy = 0;
    int speed = INITIAL_SPEED;
    bool isFloating = false;

    void movee();
    void turnLeft();
    void turnRight();
    void turnUp();
    void turnDown();
    void updateKeyboard(SDL_Event event);
};
