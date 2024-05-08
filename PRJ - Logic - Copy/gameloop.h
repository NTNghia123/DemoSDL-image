#pragma once
#include <iostream>
#include <list>
#include <ctime>
#include <algorithm>
#include "score.h"
#include "defs.h"
#include "sprite_player.h"
#include "background.h"
enum MenuOption {
    MENU,
    PLAY_GAME,
    HIGH_SCORES,
    OPTIONS,
    QUIT
};
class Game {
private:

    int status ;
	SDL_Window* window;
	SDL_Renderer* renderer;
	Sprite tower;
    Sprite healthBar;
    Sprite flame;
    Sprite pauseButton;
    std::list<Sprite*> arrows;
    std::list<Sprite*> booms;
    std::list<Zombie*> zombies;
    Player player;
    SDL_Texture* emptyManaBar, *maxManaBar;
    double manaPercent;
    int upmanaPercent;

    Sprite SampleArrow;
    SDL_Texture* arrowTexture,* fireTexture,* blueTexture,* purpleTexture, *ultiTexture;
    SDL_Texture* boomTexture, *boom1Frame;
    int boom1FrameW, boom1FrameH;
    SDL_Texture* zombieDie, *zombieEnter,*zombieWalk,*zombieFreeze ,*zombieFreezing, *zombieDefault, *zombieHealthBar;
    int ARROW_LOADING_TIME;
    int canShootFrame;

    ScrollingBackground bg;
    SDL_Texture* staticBG;
    SDL_Texture* STATIC_BG_day, *STATIC_BG_night, *SCROLLING_BG_day, *SCROLLING_BG_night;
    int BG_SCROLL_SPEED = 4;
    bool night;

    int zombieSpawnTime;
    int stageResetTimer;
    int FPS = 10;

    Sprite MenuTexture, pauseMenuTexture, replayButton, toMenuButton, resumeButton;
    bool pause;
    int mouseX, mouseY;

    std::list <Combo*> combos;
    int comboCount, prev_comboCount;
    int comboLoadingTime;
    int score;
    int bestScore;
    int bestScoreX, bestScoreY;
    TTF_Font* fontScore, *fontText, *fontComboOkay, *fontComboGoody, *fontComboCrazy;
    SDL_Color colorRed, colorYellow, colorOrange, colorCandy;

    Mix_Music *mainMusic;
    Mix_Chunk *boomChunk, *kingCombo, *ultiSound;
    bool isKingCombo;

    int keyboard[MAX_KEYBOARD_KEYS] = {0};
    // ~Game();

public:
	void initGame();
	void play();
    void get();
    void getMenu();
    void updateEvent();
    void getIfPause();
    void updateEventIfPause();
    void GameshootDayArrow();
    void GameshootNightArrow();
    void GameshootUlti();
    void doArrows();
    void spawnZombies();
    void doZombies();
    void doBoom();
    void doCombo();
    void boomAtCollision(Zombie* zombie, Sprite* arrow);
    void empty(std::list<Sprite*>& entities);
    void emptyZombie(std::list<Zombie*>& entities);
    void reset();

    void play(Mix_Music *gMusic);
    void play(Mix_Chunk* gChunk);

    bool checkCollides(Sprite* arrow);
    bool isInRect(const Sprite& sprite);
};
