#include "gameloop.h"
#include "graphics.h"

void Game::initGame() {

	init();
	window = initWin();
	renderer = initRen(window);
	explode.initClip(loadTexture(TOWER_EXPLODE_FILE,renderer), TOWER_EXPLODE_FRAMES, TOWER_EXPLODE_CLIPS);
	healthBar.initClip(loadTexture(TOWER_EXPLODE_FILE,renderer), HEALTH_BAR_FRAMES, HEALTH_BAR_CLIPS);

	player.initClip(loadTexture(PLAYER_NORMAL_IMG,renderer),PLAYER_FRAMES,PLAYER_CLIPS);

    bg.setTexture(loadTexture(BG_IMAGE,renderer));
    staticBG = loadTexture(STATIC_BG_IMAGE,renderer);

    player.JumpingTexture = loadTexture(PLAYER_JUMPING_IMG, renderer);
}
void Game::play(Input input){
    bool quit = false;
    while( !quit ) {

        //bird.tick(); // cap nhat frame
        //explode.tick();
        //player.tick();
        //healthBar.tick();
        prepareScene(renderer);
        //cap nhat toa do

        input.get();
        player.updateToado(input.keyboard);
        player.moveee();

        bg.scroll(BG_SCROLL_SPEED);
        render(bg,renderer);
        renderTexture(staticBG,0,200,renderer);

        if ( player.Jumping == true ) setPlayerTexture();
        player.render(renderer);

        healthBar.render(-13,0,renderer);
        //graphics.render(toado.x,toado.y,bird);
        explode.render(-195,0,renderer);
        presentScene(renderer);
        SDL_Delay(100);
    }
}
void Game::setPlayerTexture(){
    player.texture = player.JumpingTexture;
}
