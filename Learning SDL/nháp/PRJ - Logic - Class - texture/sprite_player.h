
#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <algorithm>
#include "defs.h"
#include "graphics.h"

#define INITIAL_SPEED 69
#define ARROW_SPEED 75
#define ULTI_SPEED 120
#define ZOMBIE_SPEED 6
class Sprite {
    public:
    SDL_Texture* texture;
    std::vector <SDL_Rect> clips;
    int currentFrame = 0;
    int randomTexture = 0;
    int penetrate;
    bool isUlti = false;

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
    void getPos(int _x, int _y);

    bool isCollides(Sprite* arrow);

};
class Archer : public Sprite{
    public :
    bool Jumping;
    bool Shooting;
    bool isShooting;
    bool isStanding;
    SDL_Texture* NormalTexture;
    SDL_Texture* JumpingTexture;
    SDL_Texture* ShootingTexture;
    SDL_Texture* ArcherDefaultTexture;
    std::vector <SDL_Texture*> ArcherTexture;
    int currentTexture = 0;

    void ArcherInit();
    void render(SDL_Renderer *renderer);
    void turnUpp();
    void turnDownn();
    void shootArrow();
    void moveee();
};
class Wizard : public Sprite{
    public :
    bool isCasting;
    int frameCasting;
    SDL_Texture* NormalTexture;
    SDL_Texture* AttackTexture;
    SDL_Texture* DieTexture;
    SDL_Texture* WizardDefaultTexture;
    std::vector <SDL_Texture*> WizardTexture;
    int currentTexture = 0;

    void WizardInit();
    void render(SDL_Renderer *renderer);
};
enum {
    ZOMBIE_ENTER_TEXT,
    ZOMBIE_WALK_TEXT,
    ZOMBIE_DIE_TEXT,
    ZOMBIE_FREEZE_TEXT,
    ZOMBIE_FREEZING_TEXT
    };
class Zombie : public Sprite{
    public:
    bool isDying;
    std::vector <SDL_Texture*> ZombieTexture;
    int currentTexture = 0;
    bool nightZombie;

    void renderZombie(SDL_Renderer *renderer);
};

class clickedBoom : public Sprite{
};

