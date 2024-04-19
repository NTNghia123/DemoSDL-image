
#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include "defs.h"
#include "graphics.h"

#define INITIAL_SPEED 65
class Sprite {
    private:


    public:
    SDL_Texture* texture;
    std::vector <SDL_Rect> clips;
    int currentFrame = 0;

    int x = INIT_X;
    int y = INIT_Y;
    int dx = 0;
    int dy = 0;
    int speed = INITIAL_SPEED;

    void initClip(SDL_Texture* _texture, int frames, const int _clips [][4]);
    void tick();
    const SDL_Rect* getCurrentClip() const;

    void movee();
    void turnLeft();
    void turnRight();
    void turnUp();
    void turnDown();
    void updateToado(int keyboard[]);
    void render(int x, int y, SDL_Renderer *renderer);
    void render(SDL_Renderer *renderer);
};
class Player : public Sprite{
    private:

    public :
    bool Jumping = false;
    bool Shooting = false;
    SDL_Texture* JumpingTexture;
    void turnUp();
    void turnDown();
    void moveee();
    // void PlayerSetTexture(SDL_Texture* _texture);
};
struct Input {
    int keyboard[MAX_KEYBOARD_KEYS] = {0};

	void init()
    {
        for (int i = 0; i < MAX_KEYBOARD_KEYS; i++) keyboard[i] = 0;
    }

    void get() {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    exit(0);
                    break;

                case SDL_KEYDOWN:
                    if (event.key.repeat == 0
                        && event.key.keysym.scancode < MAX_KEYBOARD_KEYS) {
                        keyboard[event.key.keysym.scancode] = 1;
                    }
                    break;

                case SDL_KEYUP:
                    if (event.key.repeat == 0
                        && event.key.keysym.scancode < MAX_KEYBOARD_KEYS) {
                        keyboard[event.key.keysym.scancode] = 0;
                    }
                    break;

                default:
                    break;
            }
        }
    }
};
