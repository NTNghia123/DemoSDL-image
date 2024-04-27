
#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <algorithm>
#include "defs.h"
#include "graphics.h"

#define INITIAL_SPEED 69
#define ARROW_LOADING_TIME 4
#define ARROW_SPEED 75
#define ZOMBIE_SPEED 10
class Sprite {
    public:
    SDL_Texture* texture;
    std::vector <SDL_Rect> clips;
    int currentFrame = 0;

    int health;
    int x;
    int y;
    int w;
    int h;
    int dx = 0;
    int dy = 0;
    int speed = INITIAL_SPEED;

    void initClip(SDL_Texture* _texture, int frames, const int _clips [][4]);
    void tick();
    const SDL_Rect* getCurrentClip() const;
    const SDL_Rect  CurrentClip() const;

    void movee();
    void turnLeft();
    void turnRight();
    void turnUp();
    void turnDown();
    void updateToado(int keyboard[]);
    void render(int x, int y, SDL_Renderer *renderer);

    bool isCollides(Sprite* arrow);

};
class Player : public Sprite{
    public :
    bool Jumping = false;
    bool Shooting = false;
    bool isStanding = true;
    bool isShooting = false;
    SDL_Texture* NormalTexture;
    SDL_Texture* JumpingTexture;
    SDL_Texture* ShootingTexture;
    SDL_Texture* PlayerDefaultTexture;
    std::vector <SDL_Texture*> PlayerTexture;
    int currentTexture = 0;


    void PlayerInit();
    void updateToadoPlayer(int keyboard[]);
    void render(SDL_Renderer *renderer);
    void turnUpp();
    void turnDownn();
    void shootArrow();
    void moveee();
};

class Zombie : public Sprite{
    public:
    std::vector <SDL_Texture*> ZombieTexture;
    int currentTexture = 0;

    void renderZombie(SDL_Renderer *renderer);
};


