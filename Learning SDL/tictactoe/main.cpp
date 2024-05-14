
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "defs.h"
#include "graphics.h"
#include "logic.h"
using namespace std;

void processClick(int x, int y, Tictactoe& game){
    int clickedCol = (x - BOARD_X) / CELL_SIZE;
    int clickedRow = (y - BOARD_Y) / CELL_SIZE;
    game.move(clickedRow, clickedCol);
}

int main(int argc, char *argv[])
{

    Graphics graphics;
    graphics.init();

    SDL_Texture * bg = graphics.loadTexture("bg.jpg");
    graphics.prepareScene(bg);
    graphics.presentScene();

    Tictactoe game;
    game.init();
    graphics.render(game);



    SDL_Event event;
    int x, y;
    bool quit = false;
    while (!quit) {
        SDL_PollEvent(&event);
        switch (event.type) {
            case SDL_QUIT:
                 quit = true;
                 break;
        case SDL_MOUSEBUTTONDOWN:
                 SDL_GetMouseState(&x,&y);
                 cerr << "Down at (" << x << ", " << y << ")\n";
                 processClick(x,y,game);
                 graphics.render(game);
                 break;
        }
        SDL_Delay(100);
    }

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
