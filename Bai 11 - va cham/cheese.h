
#pragma once
#define CHEESE_SIZE 10

struct Cheese {
    SDL_Rect rect;
    Cheese(int x, int y) {
        rect.x = x;
        rect.y = y;
        rect.h = CHEESE_SIZE;
        rect.w = CHEESE_SIZE;
    }
};

void render(const Cheese& cheese, const Graphics& graphics) {
    SDL_SetRenderDrawColor(graphics.renderer, 255, 255, 0, 255); // green
    SDL_RenderFillRect(graphics.renderer, &cheese.rect);
}
