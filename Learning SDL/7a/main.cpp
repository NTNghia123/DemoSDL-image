#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "graphics.h"
#include "defs.h"
#include "game.h"

using namespace std;
void check (Mouse& mouse) {
    if ( mouse.x >= SCREEN_WIDTH ) mouse.x = 0;
    if ( mouse.y >= SCREEN_HEIGHT) mouse.y = 0;
    if ( mouse.x < 0 ) mouse.x = SCREEN_WIDTH;
    if ( mouse.y < 0 ) mouse.y = SCREEN_HEIGHT;
}
int main(int argc, char *argv[])
{
    Graphics graphics;
    graphics.init();

    Mouse mouse;
    mouse.x = SCREEN_WIDTH / 2;
    mouse.y = SCREEN_HEIGHT / 2;

    bool quit = false;
    SDL_Event event;
    while (!quit ) {
        graphics.prepareScene();

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) quit = true;
        }

        const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

        if (currentKeyStates[SDL_SCANCODE_UP]) mouse.turnNorth();
        if (currentKeyStates[SDL_SCANCODE_DOWN]) mouse.turnSouth();
        if (currentKeyStates[SDL_SCANCODE_LEFT]) mouse.turnWest();
        if (currentKeyStates[SDL_SCANCODE_RIGHT]) mouse.turnEast();

        mouse.move();

        render(mouse, graphics);

        graphics.presentScene();
        SDL_Delay(10);
    }

    graphics.quit();
    return 0;
}
