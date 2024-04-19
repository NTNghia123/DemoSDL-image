
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
};
class Player : public Sprite{
    private:

    public :
    bool Jumping = false;
    bool Shooting = false;
    SDL_Texture* NormalTexture;
    SDL_Texture* JumpingTexture;
    SDL_Texture* ShootingTexture;
    std::vector <SDL_Texture*> PlayerTexture;
    int currentTexture = 0;

    void PlayerInit();
    void updateToadoPlayer(int keyboard[]);
    void render(SDL_Renderer *renderer);
    void turnUpp();
    void turnDownn();
    void moveee();
    // void PlayerSetTexture(SDL_Texture* _texture);
};


