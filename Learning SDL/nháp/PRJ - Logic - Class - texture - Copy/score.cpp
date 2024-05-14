#include "score.h"
#include "defs.h"
void writeGameScore(const int score){
    std::ofstream file("score.txt");
    if ( file.is_open()){
        file << score << std::endl;
    }
    file.close();
    return;
}
void eraseFileData(const char * path){
    std::ofstream file(path);
    if ( file.is_open()){
        file << "0" << std::endl;
    }
    file.close();
    return;
}

void rewriteTopScore(const int score, int *scores) {
    std::ifstream input("top_score.txt");
    int number;
    int index = 0;
    int scoresTMP[MAX_SCORES + 1];
    if (input.is_open()) {
        while (input >> number && index < MAX_SCORES) scoresTMP[index++] = number;
    }
    input.close();
    scoresTMP[MAX_SCORES ] = score;
    std::sort(scoresTMP, scoresTMP + MAX_SCORES + 1, std::greater<int>());

    std::ofstream output("top_score.txt");
    index = 0;
    while (index < MAX_SCORES) {
        output << scoresTMP[index] << std::endl;
        scores[index] = scoresTMP[index];
        index++;
    }
    output.close();
}

void readBestscore(int& bestScore, const int score) {
    if (score > bestScore) bestScore = score;
    std::ifstream topfile("top_score.txt");
    if (topfile.is_open()) {
        while (!topfile.eof()) {
            std::string line;
            if (getline(topfile, line)) {
                    int number = std::stoi(line);
                    if (bestScore < number) bestScore = number;
            }
        }
    }
    topfile.close();
}
