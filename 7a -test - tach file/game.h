#ifndef GAME_H
#define GAME_H

#define INITIAL_SPEED 3

struct Mouse {
    int x, y;
    int dx = 0, dy = 0;
    int speed = INITIAL_SPEED;
    void move();
    void turnNorth();
    void turnSouth();
    void turnWest();
    void turnEast();
    void updateKeyboard();
    void check ();
};



#endif // GAME_H

