#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <string>
#include <vector>
#include <list>
#include "defs.h"
#include "sprite_player.h"
#include "background.h"

    void logErrorAndExit(const char* msg, const char* error);
    void init();
    SDL_Window* initWin();
    SDL_Renderer* initRen(SDL_Window* window);
    SDL_Texture *loadTexture(const char *filename,SDL_Renderer *renderer);
    void createCustomCursor();
    void prepareScene(SDL_Texture * background,SDL_Renderer *renderer);
    void prepareScene(SDL_Renderer *renderer);
    void presentScene(SDL_Renderer *renderer);
    void renderTexture(SDL_Texture *texture, int x, int y,SDL_Renderer *renderer);
    void renderTextureCenter(SDL_Texture* texture, SDL_Renderer* renderer);
    void render(const ScrollingBackground& background,SDL_Renderer *renderer);
    void quitLoop(SDL_Renderer *renderer, SDL_Window *window);
    void waitUntilKeyPressed();
    TTF_Font* loadFont(const char* path, int size);
    SDL_Texture* renderScore(int number, TTF_Font* font, SDL_Color textColor, int y,SDL_Renderer *renderer);
    SDL_Texture* renderText(std::string text, TTF_Font* font, SDL_Color textColor, int x, int y,SDL_Renderer *renderer);

    Mix_Music *loadMusic(const char* path);
    //void play(Mix_Music *gMusic);
    Mix_Chunk* loadSound(const char* path);
    //void play(Mix_Chunk* gChunk);

