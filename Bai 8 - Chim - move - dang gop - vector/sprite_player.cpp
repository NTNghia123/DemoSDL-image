
#include "sprite_player.h"
#include "defs.h"

void Sprite::initClip(SDL_Texture* _texture, int frames, const int _clips[][4]) {

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
        //std::cerr << "tick " << std::endl;
    }

   const SDL_Rect* Sprite::getCurrentClip() const {
        return &(clips[currentFrame]);
    }
void Sprite::updateToado(int keyboard[])
    {
        dx = dy = 0;

        if (keyboard[SDL_SCANCODE_UP]) turnUp();
        if (keyboard[SDL_SCANCODE_DOWN]) turnDown();
        //if (keyboard[SDL_SCANCODE_LEFT]) turnLeft();
        //if (keyboard[SDL_SCANCODE_RIGHT]) turnRight();
    }

    void Sprite::movee(){
        x += dx;
        y += dy;
    }
//    void Sprite::turnLeft(){
//        dx = - speed;
//        dy = 0 ;
//        std::cerr << "left" << std::endl;
//
//    }
//    void Sprite::turnRight(){
//        dx =  speed;
//        dy = 0 ;
//        std::cerr << "right" << std::endl;
//
//    }
    void Sprite::turnUp(){
        if ( y - speed >= 170 && y - speed <= 470){
        dx = 0;
        dy = - speed ;
        }
        tick();
        std::cerr << "up" << std::endl;
    }
    void Sprite::turnDown(){
        if ( y + speed >= 170 && y + speed <= 400){
        dx = 0;
        dy = speed ;
        }
        tick();
        std::cerr << "down" << std::endl;
    }
    void Sprite::render(int x, int y, SDL_Renderer *renderer) {
        const SDL_Rect* clip = getCurrentClip();
        SDL_Rect renderQuad = {x, y, clip->w, clip->h};
        SDL_RenderCopy(renderer, texture, clip, &renderQuad);
    }

