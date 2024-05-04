#include "sprite_player.h"
// #include "graphics.h"
    void Player::turnUp(){
        if ( y - speed >= 170 && y - speed <= 470){
        dx = 0;
        dy = - speed ;
        }
        Jumping = true;
        std::cerr << "up" << std::endl;

    }
    void Player::turnDown(){
        if ( y + speed >= 170 && y + speed <= 400){
        dx = 0;
        dy = speed ;
        }
        Jumping = true;
        std::cerr << "down" << std::endl;
    }
    void Player::moveee(){
        x += dx;
        y += dy;
    }
//    void Player::PlayerSetTexture(SDL_Texture* _texture) {
//    if ( Jumping == true ){
//            texture = JumpingTexture;
//        }
//    }
