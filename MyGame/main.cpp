
#include "defs.h"
#include "graphics.h"
#include "chim.h"
#include "background.h"
using namespace std;

int main(int argc, char *argv[])
{

    Graphics graphics;
    graphics.init();

    Input input;
    input.init();

    GameLoop gameloop;
    gameloop.init(graphics);

    ScrollingBackground bg;
    bg.setTexture(graphics.loadTexture(BG_IMAGE));

    SDL_Texture* staticBG = graphics.loadTexture(STATIC_BG_IMAGE);

    bool quit = false;
    SDL_Event e;
    while( !quit ) {


        //explode.tick(); // cap nhat frame
        gameloop.healthBar.tick();
        graphics.prepareScene();
        //cap nhat toa do

        input.get();
        gameloop.player.updateToado(input.keyboard);
        gameloop.player.movee();

        bg.scroll(BG_SCROLL_SPEED);
        graphics.render(bg);
        graphics.renderTexture(staticBG,0,200);
        graphics.renderTexture(gameloop.player.texture,150,200);
        graphics.render(-13,0,gameloop.healthBar);
        graphics.render(-185,0,gameloop.explode);
        graphics.presentScene();

        SDL_Delay(100);
    }

//    SDL_DestroyTexture( birdTexture );
//    birdTexture = NULL;

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
