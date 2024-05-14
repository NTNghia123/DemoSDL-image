#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
void writeGameScore(const int score);
void eraseFileData(const char * path);
void rewriteTopScore(const int score);
void readBestscore(int & bestScore, const int score);

struct Combo{
    int x;
    int y;
    int comboPoint;
    int presentTime = 4;
    TTF_Font* comboFont;

    Combo(int _comboPoint,int _x, int _y){
    comboPoint = _comboPoint;
    x = _x;
    y = _y;
    }
};
