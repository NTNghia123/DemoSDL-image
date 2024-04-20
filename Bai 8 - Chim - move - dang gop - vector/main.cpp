
#include "defs.h"
#include "sprite_player.h"
#include "background.h"
#include "gameloop.h"
using namespace std;

int main(int argc, char *argv[])
{
    Game game;
	game.initGame();

    game.play();


//    SDL_DestroyTexture( birdTexture );
//    birdTexture = NULL;

    //quitLoop(renderer,window);
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
