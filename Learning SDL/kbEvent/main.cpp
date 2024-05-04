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


        bool quit = false;
    SDL_Event event;
    while (!quit) {
        //Handle events on queue
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) quit = true;
        }

        const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

        if (currentKeyStates[SDL_SCANCODE_UP] ) cerr << " Up";
        if (currentKeyStates[SDL_SCANCODE_DOWN] ) cerr << " Down";
        if (currentKeyStates[SDL_SCANCODE_LEFT] ) cerr << " Left";
        if (currentKeyStates[SDL_SCANCODE_RIGHT] ) cerr << " Right";

        cerr << ".\n";

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
