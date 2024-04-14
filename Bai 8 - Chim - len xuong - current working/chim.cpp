#include "chim.h"
#include "defs.h"


    void Sprite::init(SDL_Texture* _texture, int frames, const int _clips [][4]) {
        texture = _texture;
        SDL_Rect clip;
        for (int i = 0; i < frames; i++) {
            clip.x = _clips[i][0];
            clip.y = _clips[i][1];
            clip.w = _clips[i][2];
            clip.h = _clips[i][3];
            clips.push_back(clip);
        }
    }
    void Sprite::tick() {
        currentFrame = (currentFrame + 1) % clips.size();
    }

    const SDL_Rect* Sprite::getCurrentClip() const {
        return &(clips[currentFrame]);
    }


    void ToaDo::movee(){
            x += dx;
            y += dy;
            dx = 0;
            dy = 0;
        if (isFloating == true){
            turnDown();
        }
    }
    void ToaDo::turnUp(){
        dx = 0;
        dy = - speed ;
        isFloating = true;
        std::cerr << "up" << std::endl;
    }
    void ToaDo::turnDown(){
        dx = 0;
        dy = speed ;
        std::cerr << "down" << std::endl;
        isFloating = false;
    }
    void ToaDo::updateKeyboard(SDL_Event event){
        if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_UP && (isFloating == false) ){
            turnUp();
        }
    }



