
#include "defs.h"
#include "graphics.h"
#include "chim.h"
#include "background.h"
using namespace std;

int main(int argc, char *argv[])
{

    Graphics graphics;
    graphics.init();

    Sprite bird;
    SDL_Texture* birdTexture = graphics.loadTexture(BIRD_SPRITE_FILE);
    bird.init(birdTexture, BIRD_FRAMES, BIRD_CLIPS);

    Sprite explode;
    SDL_Texture* explodeTexture = graphics.loadTexture(TOWER_EXPLODE_FILE);
    explode.init(explodeTexture, TOWER_EXPLODE_FRAMES, TOWER_EXPLODE_CLIPS);

    Sprite healthBar;
    SDL_Texture* health_bar = graphics.loadTexture(HEALTH_BAR);
    healthBar.init(health_bar, HEALTH_BAR_FRAMES, HEALTH_BAR_CLIPS);

    SDL_Texture* test = graphics.loadTexture(TEST);

    ToaDo toado;

    Input input;
    input.init();

    ScrollingBackground bg;
    bg.setTexture(graphics.loadTexture(BG_IMAGE));

    SDL_Texture* staticBG = graphics.loadTexture(STATIC_BG_IMAGE);

    bool quit = false;
    SDL_Event e;
    while( !quit ) {

        //bird.tick(); // cap nhat frame
        //explode.tick();
        healthBar.tick();
        graphics.prepareScene();
        //cap nhat toa do

        input.get();
        toado.updateToado(input.keyboard);
        toado.movee();

        bg.scroll(BG_SCROLL_SPEED);
        graphics.render(bg);
        graphics.renderTexture(staticBG,0,200);
        graphics.renderTexture(test,150,200);
        graphics.render(-13,0,healthBar);
        //graphics.render(toado.x,toado.y,bird);
        graphics.render(-185,0,explode);
        graphics.presentScene();
        SDL_Delay(100);
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
