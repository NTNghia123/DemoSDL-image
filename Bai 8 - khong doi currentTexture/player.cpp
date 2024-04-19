#include "sprite_player.h"
// #include "graphics.h"
void Player::updateToadoPlayer(int keyboard[])
    {
//        if (player.health == 0) return;
//
          dx = dy = 0;
//
//        if (player.reload > 0) player.reload--;
        if (keyboard[SDL_SCANCODE_UP]) turnUpp();
        if (keyboard[SDL_SCANCODE_DOWN]) turnDownn();
        //if (keyboard[SDL_SCANCODE_LEFT]) turnLeft();
        //if (keyboard[SDL_SCANCODE_RIGHT]) turnRight();
     // if (keyboard[SDL_SCANCODE_LCTRL] && player.reload == 0) fireBullet();
    }
    void Player::turnUpp(){
        if ( y - speed >= 170 && y - speed <= 470){
        dx = 0;
        dy = - speed ;
        }
        Jumping = true;
        std::cerr << "upp" << std::endl;

    }
    void Player::turnDownn(){
        if ( y + speed >= 170 && y + speed <= 400){
        dx = 0;
        dy = speed ;
        }
        Jumping = true;
        std::cerr << "downn" << std::endl;

    }
    void Player::moveee(){
        x += dx;
        y += dy;
        if ( Jumping ) currentTexture = 1;
    }
//    void Player::PlayerSetTexture(SDL_Texture* _texture) {
//    if ( Jumping == true ){
//            texture = JumpingTexture;
//        }
//    }
void Player::PlayerInit (){
    PlayerTexture.push_back(NormalTexture);
    PlayerTexture.push_back(JumpingTexture);
    PlayerTexture.push_back(ShootingTexture);
}
void Player::render(SDL_Renderer *renderer) {
        const SDL_Rect* clip = getCurrentClip();
        SDL_Rect renderQuad = {x, y, clip->w, clip->h};
        SDL_RenderCopy(renderer,PlayerTexture[currentTexture], clip, &renderQuad);
        std::cerr << currentTexture << std::endl;
    }
