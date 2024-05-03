#include "score.h"

void writeGameScore(const int score){
    std::ofstream file("score.txt");
    if ( file.is_open()){
        file << score << std::endl;
    }
    file.close();
    return;
}
void eraseFileData(const char * path1, const char * path2){
    std::ofstream file(path1);
    if ( file.is_open()){
        file << "" << std::endl;
    }
    file.close();
    std::ofstream filee(path2);
    if ( filee.is_open()){
        filee << "" << std::endl;
    }
    filee.close();
    return;
}
//void rewriteTopScore(const int score){
//    std::ifstream input("top_score.txt");
//    int scores [6] = {0,0,0,0,0,0}; // nhung chi lay 5 thoi
//    int number;
//    int index = 0;
//    if ( input.is_open()){
//        std::string line;
//        if (getline(input,line)) number = std::stoi(line);
//        scores[index] = number;
//        index ++;
//    }
//    scores[5] = score;
//    int len = sizeof(scores) / sizeof(scores[0]);
//    std::sort(scores, scores + len, std::greater<int>());
//    input.close();
//
//    std::ofstream output("top_score.txt"); //,std::ios::app
//    index = 0;
//    while ( index < 5){
//        output << scores[index] << std::endl;
//        index ++;
//    }
//    output.close();
//
//    return;
//}
//void readBestscore(int & bestScore, const int score){
//    if ( score > bestScore ) bestScore = score;
//    std::ifstream topfile("top_score.txt");
//    if (topfile.is_open()){
//        while ( !topfile.eof()){
//            std::string line;
//            int number;
//            if (getline(topfile,line)){
//            number = std::stoi(line);
//            if ( bestScore < number ) bestScore = number;
//            }
//        }
//    }
//    topfile.close();
//    return;
//}
void rewriteTopScore(const int score) {
    std::ifstream input("top_score.txt");
    int scores[6] = {0, 0, 0, 0, 0, 0}; // nhung chi lay 5 thoi
    int number;
    int index = 0;
    if (input.is_open()) {
        std::string line;
        if (getline(input, line)) {
            try {
                number = std::stoi(line);
                scores[index] = number;
                index++;
            } catch (const std::invalid_argument& e) {
                // Handle error (e.g., line is not convertible to int)
            }
        }
    }
    scores[5] = score;
    int len = sizeof(scores) / sizeof(scores[0]);
    std::sort(scores, scores + len, std::greater<int>());
    input.close();

    std::ofstream output("top_score.txt");
    index = 0;
    while (index < 5) {
        output << scores[index] << std::endl;
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
                try {
                    int number = std::stoi(line);
                    if (bestScore < number) bestScore = number;
                } catch (const std::invalid_argument& e) {
                    // Handle error (e.g., line is not convertible to int)
                }
            }
        }
    }
    topfile.close();
}
