
#include "defs.h"
#include "graphics.h"
#include "chim.h"
#include "background.h"

using namespace std;

int main(int argc, char *argv[])
{

    Graphics graphics;
    graphics.init();

    ToaDo toado;

    Sprite bird;
    SDL_Texture* birdTexture = graphics.loadTexture(BIRD_SPRITE_FILE);
    bird.init(birdTexture, BIRD_FRAMES, BIRD_CLIPS);



    ScrollingBackground bg;
    bg.setTexture(graphics.loadTexture(BG_IMAGE));

    bool quit = false;
    SDL_Event event;
    while( !quit ) {
        while( SDL_PollEvent( &event ) != 0 ) {
            if( event.type == SDL_QUIT ) quit = true;
            toado.updateKeyboard(event);
        }
        bird.tick(); // cap nhat frame
        graphics.prepareScene();
        //cap nhat toa do

        toado.movee();

        bg.scroll(BG_SCROLL_SPEED);
        graphics.render(bg);
        graphics.render(toado.x,toado.y,bird);
        graphics.presentScene();
        SDL_Delay(1000);
    }

    SDL_DestroyTexture( birdTexture );
    birdTexture = NULL;

    graphics.quit();
    return 0;
}

