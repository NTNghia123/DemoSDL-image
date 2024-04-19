#include "gameloop.h"
#include "graphics.h"

void Game::initGame() {

	init();
	for (int i = 0; i < MAX_KEYBOARD_KEYS; i++) keyboard[i] = 0;
	window = initWin();
	renderer = initRen(window);
	explode.initClip(loadTexture(TOWER_EXPLODE_FILE,renderer), TOWER_EXPLODE_FRAMES, TOWER_EXPLODE_CLIPS);
	healthBar.initClip(loadTexture(TOWER_EXPLODE_FILE,renderer), HEALTH_BAR_FRAMES, HEALTH_BAR_CLIPS);

    bg.setTexture(loadTexture(BG_IMAGE,renderer));
    staticBG = loadTexture(STATIC_BG_IMAGE,renderer);

    player.NormalTexture = loadTexture(PLAYER_NORMAL_IMG, renderer);
    player.initClip(player.NormalTexture,PLAYER_FRAMES,PLAYER_CLIPS);
    player.JumpingTexture = loadTexture(PLAYER_JUMPING_IMG, renderer);
    player.ShootingTexture = loadTexture(PLAYER_SHOOTING_IMG, renderer);
    player.PlayerInit();
}
void Game::play(){
    bool quit = false;
    while( !quit ) {

        //bird.tick(); // cap nhat frame
        //explode.tick();
        //player.tick();
        //healthBar.tick();
        prepareScene(renderer);
        //cap nhat toa do

        get();
        player.updateToadoPlayer(keyboard);
        player.moveee();

        bg.scroll(BG_SCROLL_SPEED);
        render(bg,renderer);
        renderTexture(staticBG,0,200,renderer);

        if ( player.Jumping == true ) player.texture = player.JumpingTexture;
        player.render(renderer);

        healthBar.render(-13,0,renderer);
        //graphics.render(toado.x,toado.y,bird);
        explode.render(-195,0,renderer);
        presentScene(renderer);
        SDL_Delay(100);
    }
}

void Game::get() {
        SDL_Event event;
        bool anyEventProcessed = false;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    exit(0);
                    break;
                case SDL_KEYDOWN:
                    if (event.key.repeat == 0
                        && event.key.keysym.scancode < MAX_KEYBOARD_KEYS) {
                        keyboard[event.key.keysym.scancode] = 1;
                        anyEventProcessed = true;
                    }
                    break;
                case SDL_KEYUP:
                    if (event.key.repeat == 0
                        && event.key.keysym.scancode < MAX_KEYBOARD_KEYS) {
                        keyboard[event.key.keysym.scancode] = 0;
                        anyEventProcessed = true;
                    }
                    break;

                default:
                    break;
            }
        }
        //if (!isPressed) player.currentTexture = 0;
        if (!anyEventProcessed)  {
        player.currentTexture = 0;
        //std::cerr << "worked" << std::endl;
        }
    }
