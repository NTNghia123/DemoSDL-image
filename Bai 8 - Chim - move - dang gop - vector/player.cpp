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
        if (keyboard[SDL_SCANCODE_S]) shootArrow();
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
        Shooting = false;
        isStanding = false;
        std::cerr << "upp" << std::endl;
    }
    void Player::turnDownn(){
        if ( y + speed >= 170 && y + speed <= 400){
        dx = 0;
        dy = speed ;
        }
        Jumping = true;
        Shooting = false;
        isStanding = false;
        std::cerr << "downn" << std::endl;
    }
    void Player::shootArrow(){
        Shooting = true;
        Jumping = false;
        isStanding = false;
    }
    void Player::moveee(){
        x += dx;
        y += dy;
        if ( Jumping ){
            currentTexture = 1;
        }
        else if ( Shooting ) {
            currentTexture = 2;
        }
    }

void Player::PlayerInit (){
    x = INIT_X;
    y = INIT_Y;
    health = 5;
    PlayerTexture.push_back(NormalTexture);
    PlayerTexture.push_back(JumpingTexture);
    PlayerTexture.push_back(ShootingTexture);
}
void Player::render(SDL_Renderer *renderer) {
        if ( Shooting || Jumping ) currentFrame = 0 ;
        const SDL_Rect* clip = getCurrentClip();
        SDL_Rect renderQuad = {x, y, clip->w, clip->h};

        SDL_RenderCopy(renderer,PlayerTexture[currentTexture], clip, &renderQuad);

        std::cerr << currentTexture << std::endl;

        if (isStanding && !Shooting && !Jumping) tick();
        Jumping = false;
        Shooting = false;
        isStanding = true;
    }