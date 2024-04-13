#ifndef GAME_H
#define GAME_H

#define INITIAL_SPEED 3

struct Mouse {
    int x, y;
    int dx = 0, dy = 0;
    int speed = INITIAL_SPEED;
    void move() {
        x += dx;
        y += dy;
    }
    void turnNorth() {
        dy = -speed;
        dx = 0;
    }
    void turnSouth() {
        dy = speed;
        dx = 0;
    }
    void turnWest() {
        dy = 0;
        dx = -speed;
    }
    void turnEast() {
        dy = 0;
        dx = speed;
    }
    void updateKeyboard(){
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

    if (currentKeyStates[SDL_SCANCODE_UP]) turnNorth();
    if (currentKeyStates[SDL_SCANCODE_DOWN]) turnSouth();
    if (currentKeyStates[SDL_SCANCODE_LEFT]) turnWest();
    if (currentKeyStates[SDL_SCANCODE_RIGHT]) turnEast();
}
    void check () {
        if ( x >= SCREEN_WIDTH ) x = 0;
        if ( y >= SCREEN_HEIGHT) y = 0;
        if ( x < 0 ) x = SCREEN_WIDTH;
        if ( y < 0 ) y = SCREEN_HEIGHT;
    }
};

void render(const Mouse& mouse, const Graphics& graphics) {
    SDL_Rect filled_rect;
    filled_rect.x = mouse.x;
    filled_rect.y = mouse.y;
    filled_rect.w = 10;
    filled_rect.h = 10;
    SDL_SetRenderDrawColor(graphics.renderer, 0, 255, 0, 255); // green
    SDL_RenderFillRect(graphics.renderer, &filled_rect);
}

bool gameOver(const Mouse& mouse) {
    return mouse.x < 0 || mouse.x >= SCREEN_WIDTH ||
           mouse.y < 0 || mouse.y >= SCREEN_HEIGHT;
}


#endif // GAME_H

