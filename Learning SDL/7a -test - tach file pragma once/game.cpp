#include "game.h"

    void Mouse::movee() {
        x += dx;
        y += dy;
    }
    void Mouse::turnNorth() {
        dy = -speed;
        dx = 0;
    }
    void Mouse::turnSouth() {
        dy = speed;
        dx = 0;
    }
    void Mouse::turnWest() {
        dy = 0;
        dx = -speed;
    }
    void Mouse::turnEast() {
        dy = 0;
        dx = speed;
    }
    void Mouse::updateKeyboard(){
        const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

        if (currentKeyStates[SDL_SCANCODE_UP]) turnNorth();
        if (currentKeyStates[SDL_SCANCODE_DOWN]) turnSouth();
        if (currentKeyStates[SDL_SCANCODE_LEFT]) turnWest();
        if (currentKeyStates[SDL_SCANCODE_RIGHT]) turnEast();
    }
    void Mouse::check () {
        if ( x >= SCREEN_WIDTH ) x = 0;
        if ( y >= SCREEN_HEIGHT) y = 0;
        if ( x < 0 ) x = SCREEN_WIDTH;
        if ( y < 0 ) y = SCREEN_HEIGHT;
    }

bool gameOver(const Mouse& mouse) {
    return mouse.x < 0 || mouse.x >= SCREEN_WIDTH ||
           mouse.y < 0 || mouse.y >= SCREEN_HEIGHT;
}



