#pragma once

#include "defs.h"
#include "sprite_player.h"
#include "background.h"
class Game {
private:

	SDL_Window* window;
	SDL_Renderer* renderer;
	Sprite explode;
    Sprite healthBar;
    Player player;
    ScrollingBackground bg;
    SDL_Texture* staticBG;
    // ~Game();

public:
	void initGame();
	void play(Input input);
	void setPlayerTexture();

};

