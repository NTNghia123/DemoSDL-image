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
    PLAY_GAME_MULTIPLAYER,
    PLAY_GAME_WIZARD,
    HIGH_SCORES,
    OPTIONS,
    QUIT,
    DIE,
    CHOOSE_CLASS
};

enum PREV_CLASS {
    ARCHER,
    WIZARD,
    MULTIPLAYER
};
class Game {
private:

    int status, prevClass ;
	SDL_Window* window;
	SDL_Renderer* renderer;
	Sprite tower;
    Sprite healthBar;
    Sprite flame;
    Sprite pauseButton;
    std::list<Sprite*> arrows;
    std::list<Sprite*> booms;
    std::list<Zombie*> zombies;
    std::list<clickedBoom*> clickedBooms;
    Archer archer;
    Wizard wizard;
    SDL_Texture* emptyManaBar, *maxManaBar;
    double manaPercent;
    int upmanaPercent;

    int FPS = 10;
    int zombieSpawnTime;
    int stageResetTimer;

    ScrollingBackground bg;
    SDL_Texture* staticBG;
    SDL_Texture* STATIC_BG_day, *STATIC_BG_night, *SCROLLING_BG_day, *SCROLLING_BG_night;
    int BG_SCROLL_SPEED = 4;
    bool night;

    Sprite SampleArrow;
    SDL_Texture* arrowTexture,* fireTexture,* blueTexture,* purpleTexture, *ultiTexture;
    SDL_Texture* boomTexture, *boom1Frame;
    int boom1FrameW, boom1FrameH;
    SDL_Texture* zombieDie, *zombieEnter,*zombieWalk,*zombieFreeze ,*zombieFreezing, *zombieDefault, *zombieHealthBar;
    int ARROW_LOADING_TIME;
    int canShootFrame;

    Sprite SampleMagic;
    SDL_Texture* magicLightning , *magicBoom, *magicBoth;

    Sprite MenuTexture, startButton, highscoreButton, infoButton, quitButton, backButton, backToGameButton;
    Sprite yesButton, noButton;
    SDL_Texture* quitMenu, *highscoreMenu, *dieMenu, *chooseClassMenu, *helpArcher, *helpWizard;
    bool ishelpWizard, ishelpArcher;
    Sprite pauseMenuTexture, replayButton, toMenuButton, helpButton, resumeButton, chooseClassWizard, chooseClassArcher;
    bool pause;
    int mouseX, mouseY;

    std::list <Combo*> combos;
    int comboCount, prev_comboCount;
    int comboLoadingTime;
    int score;
    int scores[MAX_SCORES];
    int bestScore;
    int bestScoreX, bestScoreY;
    TTF_Font* fontHighScore;
    TTF_Font* fontScore, *fontText, *fontComboOkay, *fontComboGoody, *fontComboCrazy;
    SDL_Color colorRed, colorYellow, colorOrange, colorCandy;

    Mix_Music *mainMusic;
    Mix_Chunk *chooseClass;
    Mix_Chunk *boomChunk, *kingCombo, *ultiSound, *clickSound, *explodeSound;
    Mix_Chunk *wizardFireSound, *wizardLightningSound, *wizardBothSound;
    bool isKingCombo;

    int keyboard[MAX_KEYBOARD_KEYS] = {0};
    // ~Game();

public:
	void initGame();
	void play();

	void getMenu();
	void getClass();
	void playArcher();
	void playWizard();
	void getIfHighScores();
    void getIfQuit();

    void get();
    void getWizard();
    void updateEvent();
    void getIfPause();
    void updateEventIfPause();
    void getIfDie();

    void GameshootDayArrow();
    void GameshootNightArrow();
    void GameshootUlti();
    bool checkCollides(Sprite* arrow);
    void doArrows();
    void spawnZombies();
    void spawnZombiesWizard();
    void spawnZombiesMultiplayer();
    void doZombies();
    void doBoom();
    void doCombo();
    void boomAtCollision(Zombie* zombie, Sprite* arrow);

    void spawnclickedBoom();
    void checkBoom(clickedBoom* a);
    void doclickedBoom();


    void empty(std::list<Sprite*>& entities);
    void emptyZombie(std::list<Zombie*>& entities);
    void reset();
    void quit();

    void play(Mix_Music *gMusic);
    void play(Mix_Chunk* gChunk);

    bool isInRect(const Sprite& sprite);
};
