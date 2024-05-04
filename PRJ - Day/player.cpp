#include "sprite_player.h"
void Player::updateToadoPlayer(int keyboard[])
    {
//        if (player.health == 0) return;
//
          dx = dy = 0;
//
        if (keyboard[SDL_SCANCODE_UP]) turnUpp();
        if (keyboard[SDL_SCANCODE_DOWN]) turnDownn();
        if (keyboard[SDL_SCANCODE_S]) shootArrow();
    }
    void Player::turnUpp(){
        if ( y - speed >= INIT_Y ){
        dx = 0;
        dy = - speed ;
        }
        Jumping = true;
        Shooting = false;
        isStanding = false;
        isShooting = false;
        //std::cerr << "upp" << std::endl;
    }
    void Player::turnDownn(){
        if ( y + speed + h <= SCREEN_HEIGHT){
        dx = 0;
        dy = speed ;
        }
        Jumping = true;
        Shooting = false;
        isStanding = false;
        isShooting = false;
        //std::cerr << "downn" << std::endl;
    }
    void Player::shootArrow(){
        if (Shooting) isShooting = true;
        Shooting = true;
        Jumping = false;
        isStanding = false;
    }
    void Player::moveee(){
        x += dx;
        y += dy;
    }

void Player::PlayerInit (){
    Jumping = false;
    Shooting = false;
    isShooting = false;
    isStanding = true;
    x = INIT_X;
    y = INIT_Y;
    health = 5;
    PlayerTexture.push_back(NormalTexture);
    PlayerTexture.push_back(JumpingTexture);
    PlayerTexture.push_back(ShootingTexture);
    SDL_QueryTexture(PlayerDefaultTexture, NULL, NULL, &w, &h);
}
void Player::render(SDL_Renderer *renderer) {
        if ( Jumping ){
            currentTexture = 1;
        }
        else if ( Shooting ) {
            currentTexture = 2;
        }

        const SDL_Rect* clip = getCurrentClip();
        SDL_Rect renderQuad = {x, y, clip->w, clip->h};

        SDL_RenderCopy(renderer,PlayerTexture[currentTexture], clip, &renderQuad);

        tick();
    }

void Zombie::renderZombie(SDL_Renderer *renderer){
    const SDL_Rect* clip = getCurrentClip();
    SDL_Rect renderQuad = {x, y, clip->w, clip->h};
    SDL_RenderCopy(renderer,ZombieTexture[currentTexture], clip, &renderQuad);
}
