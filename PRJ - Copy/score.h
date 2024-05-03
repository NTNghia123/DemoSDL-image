#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
void writeGameScore(const int score);
void eraseFileData(const char * path1, const char * path2);
void rewriteTopScore(const int score);
void readBestscore(int & bestScore, const int score);
