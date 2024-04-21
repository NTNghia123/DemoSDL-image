#pragma once

#include <iostream>
#include <list>
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
    Player player;

    SDL_Texture* arrowTexture;
    bool justShoot = false;

    ScrollingBackground bg;
    SDL_Texture* staticBG;

    int keyboard[MAX_KEYBOARD_KEYS] = {0};
    // ~Game();

public:
	void initGame();
	void play();
    void get();
    void GameshootArrow();
    void doArrows();
};
