#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include "defs.h"

#define INITIAL_SPEED 3
struct Sprite {
    SDL_Texture* texture;
    std::vector <SDL_Rect> clips;
    int currentFrame = 0;

    void init(SDL_Texture* _texture, int frames, const int _clips [][4]);
    void tick();
    const SDL_Rect* getCurrentClip() const;
};

struct ToaDo {
    int x = INIT_X;
    int y = INIT_Y;
    int dx = 0;
    int dy = 0;
    int speed = INITIAL_SPEED;
    void movee();
    void turnLeft();
    void turnRight();
    void turnUp();
    void turnDown();
    void updateKeyboard();
};
