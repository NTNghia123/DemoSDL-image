#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
void writeGameScore(const int score);
void eraseFileData(const char * path);
void rewriteTopScore(const int score);
void readBestscore(int & bestScore, const int score);
