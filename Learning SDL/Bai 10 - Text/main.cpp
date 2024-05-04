#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <vector>
#include "defs.h"
#include "graphics.h"
using namespace std;

int main(int argc, char *argv[])
{

    Graphics graphics;
    graphics.init();

    TTF_Font* font = graphics.loadFont("assets/Purisa-BoldOblique.ttf", 60);
    SDL_Color color = {255, 0, 0, 0};
    // SDL_Texture* helloText = graphics.renderText("Hello", font, color);


    Sprite bird;
    SDL_Texture* birdTexture = graphics.loadTexture(BIRD_SPRITE_FILE);
    bird.init(birdTexture, BIRD_FRAMES, BIRD_CLIPS);


    bool quit = false;
    SDL_Event e;
    while( !quit ) {
        while( SDL_PollEvent( &e ) != 0 ) {
            if( e.type == SDL_QUIT ) quit = true;
        }
        bird.tick();
        graphics.prepareScene();

        graphics.renderText(4, font, color);

        graphics.render(100,100,bird);
        graphics.presentScene();
        SDL_Delay(100);
    }

    // SDL_DestroyTexture( helloText );
    TTF_CloseFont( font );
    //helloText = NULL;


    SDL_DestroyTexture( birdTexture );
    birdTexture = NULL;

    graphics.quit();
    return 0;
}



/*SDL_RenderClear(renderer) để xoá toàn bộ render
waitUntilKeyPressed để chờ mình nhần
các bước in 1 ảnh lên màn hình
Bước 1: truyền file ảnh vào sử dụng loadTexture, như initSDL, cần kiểm tra lỗi nếu file ảnh được truyền vào thành công k
nếu k truyền ảnh thành công, ảnh k dc truyền nhưng chương trình vẫn sẽ tiếp tục
Bước 2: RenderCopy để copy ảnh lên renderer. Syntax SDL_RenderCopy(renderer, tên texture, NULL, &dest);
Bước 3: RenderPresent(renderer) vẽ những thứ có trong renderer
*/
