#include <iostream>
#include <SDL.h>

using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const char* WINDOW_TITLE = "Hello World!";

void logErrorAndExit(const char* msg, const char* error)
{
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "%s: %s", msg, error);
    /*
    syntax SDL_LogMessage(int category,
                    SDL_LogPriority priority,
                    SDL_PRINTF_FORMAT_STRING const char *fmt, ...)

    LogMessage dùng để ghi thông điệp ( thường là lỗi )
    category dùng để chỉ danh mục thông điệp
    priority dùng để xác định mức qua trọng của thông điệp
    "%s: %s" là fmt, tương đương cin, để ghi vào log, % là đối số trong đó %s là string, %d là int và %f là số thực
    */
    SDL_Quit();
}
//viết hàm initSDL để tạo con trỏ trả về màn hình
SDL_Window* initSDL(int SCREEN_WIDTH, int SCREEN_HEIGHT, const char* WINDOW_TITLE)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logErrorAndExit("SDL_Init", SDL_GetError());
/*
SDL_Init (Uint32 flags) trả về 0 nếu true, âm nếu false;
SDL_INIT_EVERYTHING khởi tạo các thành phần của SDL
*/
    SDL_Window* window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    /*
    SDL_Window * SDL_CreateWindow(const char *title,
                              int x, int y, int w,
                              int h, Uint32 flags);

    gồm tiêu đề, vị trí chiều ngang màn hình, vị trí chiều dọc màn hình, width, height, flag
    flag cung cấp các tùy chọn và cài đặt cho các hàm và các thành phần của SDL. ( mang tính chất)

    */

    //full screen
    //window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);
    if (window == nullptr) logErrorAndExit("CreateWindow", SDL_GetError());

    return window;
}

SDL_Renderer* createRenderer(SDL_Window* window)
{
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                              SDL_RENDERER_PRESENTVSYNC);
    //Khi chạy trong máy ảo (ví dụ phòng máy ở trường)
    //renderer = SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(window));

    if (renderer == nullptr) logErrorAndExit("CreateRenderer", SDL_GetError());

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");// thiết lập chất lượng scale
    // linear: làm mịn tuyến tính, nearest làm mịn gần nhất, dễ gẫy ảnh
    //hint nghĩa là chỉ dẫn cho máy tính
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
    // kích thước sd đồ hoạ, k phụ thuộc vào cửa sổ, SDL sẽ tự scale đồ hoạ cho phù hợp cửa sổ
    return renderer;
}

void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if ( SDL_PollEvent(&e) != 0 &&
             (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }
}

void drawSomething(SDL_Window* window, SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);   // white
    SDL_RenderDrawPoint(renderer, SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);   // red
    SDL_RenderDrawLine(renderer, 100, 100, 200, 200);
    SDL_Rect filled_rect;
    filled_rect.x = SCREEN_WIDTH - 400;
    filled_rect.y = SCREEN_HEIGHT - 150;
    filled_rect.w = 320;
    filled_rect.h = 100;
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // green
    SDL_RenderFillRect(renderer, &filled_rect);
}

int main(int argc, char* argv[])
{
    //Khởi tạo môi trường đồ họa
    SDL_Window* window = initSDL(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SDL_Renderer* renderer = createRenderer(window);

    //Xóa màn hình
    SDL_RenderClear(renderer);

    //Vẽ gì đó
    drawSomething(window, renderer); // vẽ lên buffer (background)

    //Hiện bản vẽ ra màn hình
    //Khi chạy tại môi trường bình thường
    SDL_RenderPresent(renderer); // cập nhật renderer lên màn hình
    //Khi chạy trong máy ảo (ví dụ phòng máy ở trường)
    //SDL_UpdateWindowSurface(window);

    //Đợi phím bất kỳ trước khi đóng môi trường đồ họa và kết thúc chương trình
    waitUntilKeyPressed();
    quitSDL(window, renderer);
    return 0;
}

