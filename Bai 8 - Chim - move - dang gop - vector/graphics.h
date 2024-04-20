#pragma once
//#ifndef _GRAPHICS__H
//#define _GRAPHICS__H

#include <SDL.h>
#include <SDL_image.h>
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
    void prepareScene(SDL_Texture * background,SDL_Renderer *renderer);
    void prepareScene(SDL_Renderer *renderer);
    void presentScene(SDL_Renderer *renderer);
    void renderTexture(SDL_Texture *texture, int x, int y,SDL_Renderer *renderer);
    void render(const ScrollingBackground& background,SDL_Renderer *renderer);
    void quitLoop(SDL_Renderer *renderer, SDL_Window *window);
    void waitUntilKeyPressed();


 //#endif // _GRAPHICS__H
