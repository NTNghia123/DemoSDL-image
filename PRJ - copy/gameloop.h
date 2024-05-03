#pragma once

#include <iostream>
#include <list>
#include <ctime>
#include <algorithm>
#include "defs.h"
#include "sprite_player.h"
#include "background.h"
class Game {
private:

	SDL_Window* window;
	SDL_Renderer* renderer;
	Sprite explode;
    Sprite healthBar;
    std::list<Sprite*> arrows;
    std::list<Zombie*> zombies;
    Player player;


    SDL_Texture* arrowTexture;
    SDL_Texture* zombieDie, *zombieEnter,*zombieWalk, *zombieDefault;
    int canShootFrame = ARROW_LOADING_TIME;
    ScrollingBackground bg;
    SDL_Texture* staticBG;

    int zombieSpawnTime;
    int stageResetTimer;
    int FPS = 10;

    int point;
    TTF_Font* fontScore, *fontText;
    SDL_Color color;

    int keyboard[MAX_KEYBOARD_KEYS] = {0};
    // ~Game();

public:
	void initGame();
	void play();
    void get();
    void GameshootArrow();
    void doArrows();
    void spawnZombies();
    void doZombies();
    void empty(std::list<Sprite*>& entities);
    void emptyZombie(std::list<Zombie*>& entities);
    void reset();

    bool checkCollides(Sprite* arrow);
};
