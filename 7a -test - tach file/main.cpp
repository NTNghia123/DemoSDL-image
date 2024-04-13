#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "graphics.h"
#include "game.cpp"

using namespace std;


int main(int argc, char *argv[])
{
    Graphics graphics;
    graphics.init();

    Mouse mouse;
    mouse.x = SCREEN_WIDTH / 2;
    mouse.y = SCREEN_HEIGHT / 2;

    bool quit = false;
    SDL_Event event;
    while (!quit ) { // && !gameOver(mouse)
        graphics.prepareScene(graphics.bg);

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) quit = true;
        }


        mouse.updateKeyboard(); // lay dx dy
        mouse.move(); // cap nhat x y
        mouse.check();

        graphics.blitRect(graphics.img,&graphics.src,mouse.x,mouse.y);

        graphics.presentScene();
        SDL_Delay(10);
    }

    graphics.quit();
    return 0;
}
