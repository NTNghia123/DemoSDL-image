#include "sprite_player.h"

    void Archer::turnUpp(){
        if ( y - speed >= INIT_Y ){
        dx = 0;
        dy = - speed ;
        }
        Jumping = true;
        Shooting = false;
        isStanding = false;
        isShooting = false;
    }
    void Archer::turnDownn(){
        if ( y + speed + h <= SCREEN_HEIGHT){
        dx = 0;
        dy = speed ;
        }
        Jumping = true;
        Shooting = false;
        isStanding = false;
        isShooting = false;
    }
    void Archer::shootArrow(){
        if (Shooting) isShooting = true;
        Shooting = true;
        Jumping = false;
        isStanding = false;
    }
    void Archer::moveee(){
        x += dx;
        y += dy;
    }

void Archer::ArcherInit (){
    Jumping = false;
    Shooting = false;
    isShooting = false;
    isStanding = true;
    health = 5;
    ArcherTexture.push_back(NormalTexture);
    ArcherTexture.push_back(JumpingTexture);
    ArcherTexture.push_back(ShootingTexture);
    SDL_QueryTexture(ArcherDefaultTexture, NULL, NULL, &w, &h);
}
void Archer::render(SDL_Renderer *renderer) {
        if ( Jumping ){
            currentTexture = 1;
        }
        else if ( Shooting ) {
            currentTexture = 2;
        }

        const SDL_Rect* clip = getCurrentClip();
        SDL_Rect renderQuad = {x, y, clip->w, clip->h};
        SDL_RenderCopy(renderer,ArcherTexture[currentTexture], clip, &renderQuad);

        tick();
    }
    void Wizard::WizardInit (){
        health = 5;
        WizardTexture.push_back(NormalTexture);
        WizardTexture.push_back(AttackTexture);
        WizardTexture.push_back(DieTexture);
        SDL_QueryTexture(WizardDefaultTexture, NULL, NULL, &w, &h);
    }
    void Wizard::render(SDL_Renderer *renderer) {

        const SDL_Rect* clip = getCurrentClip();
        SDL_Rect renderQuad = {x, y, clip->w, clip->h};
        SDL_RenderCopy(renderer,WizardTexture[currentTexture], clip, &renderQuad);

        tick();
    }
void Zombie::renderZombie(SDL_Renderer *renderer){
    const SDL_Rect* clip = getCurrentClip();
    SDL_Rect renderQuad = {x, y, clip->w, clip->h};
    SDL_RenderCopy(renderer,ZombieTexture[currentTexture], clip, &renderQuad);
}
