
#include "defs.h"
#include "graphics.h"
#include "chim.h"
using namespace std;

int main(int argc, char *argv[])
{

    Graphics graphics;
    graphics.init();

    Sprite bird;
    SDL_Texture* birdTexture = graphics.loadTexture(BIRD_SPRITE_FILE);
    bird.init(birdTexture, BIRD_FRAMES, BIRD_CLIPS);

    ToaDo toado;

    bool quit = false;
    SDL_Event e;
    while( !quit ) {
        while( SDL_PollEvent( &e ) != 0 ) {
            if( e.type == SDL_QUIT ) quit = true;
        }
        bird.tick(); // cap nhat frame
        graphics.prepareScene();
        //cap nhat toa do

        toado.updateKeyboard();
        toado.movee();

        graphics.render(toado.x,toado.y,bird);
        graphics.presentScene();
        SDL_Delay(1);
    }

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
