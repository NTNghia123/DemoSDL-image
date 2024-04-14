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
    }
    void ToaDo::turnLeft(){
        dx = - speed;
        dy = 0 ;
        std::cerr << "left" << std::endl;

    }
    void ToaDo::turnRight(){
        dx =  speed;
        dy = 0 ;
        std::cerr << "right" << std::endl;

    }
    void ToaDo::turnUp(){
        dx = 0;
        dy = - speed ;
        std::cerr << "up" << std::endl;

    }
    void ToaDo::turnDown(){
        dx = 0;
        dy = speed ;
        std::cerr << "down" << std::endl;

    }

    void ToaDo::updateKeyboard(){
        const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

        if (currentKeyStates[SDL_SCANCODE_UP]) turnUp();
        if (currentKeyStates[SDL_SCANCODE_DOWN]) turnDown();
        if (currentKeyStates[SDL_SCANCODE_LEFT]) turnLeft();
        if (currentKeyStates[SDL_SCANCODE_RIGHT]) turnRight();
    }
