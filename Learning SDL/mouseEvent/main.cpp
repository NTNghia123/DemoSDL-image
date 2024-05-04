#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "defs.h"
#include "graphics.h"
using namespace std;

int main(int argc, char *argv[])
{

    Graphics graphics;
    graphics.init();

    SDL_Rect rect;
    rect.x=100;
    rect.y=100;
    rect.h=100;
    rect.w=100;
    SDL_SetRenderDrawColor(graphics.renderer, 255, 255, 255, 0 );
    SDL_RenderFillRect(graphics.renderer, &rect);
    SDL_RenderPresent(graphics.renderer);


    SDL_Event event;
    int x, y;
    while (true) {
        SDL_GetMouseState(&x, &y);
   //  cerr << ((x > 100 && y > 100 && x < 200 && y < 200) ? "In\n" : "Out\n");

        SDL_PollEvent(&event);
        switch (event.type) {
            case SDL_QUIT:
                 exit(0);
                 break;
        case SDL_MOUSEBUTTONDOWN:
                 cerr << "Down at (" << x << ", " << y << ")\n";
                 break;
        case SDL_MOUSEBUTTONUP:
                 cerr << "Up at (" << x << ", " << y << ")\n";
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
