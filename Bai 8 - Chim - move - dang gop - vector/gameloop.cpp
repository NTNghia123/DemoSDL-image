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

    arrowTexture = loadTexture(ARROW_IMG,renderer);
}
void Game::play(){
    bool quit = false;
    while( !quit ) {

        //explode.tick();
        //healthBar.tick();
        prepareScene(renderer);
        //cap nhat toa do

        get();
        player.updateToadoPlayer(keyboard);
        player.moveee();

        bg.scroll(BG_SCROLL_SPEED);
        render(bg,renderer);
        renderTexture(staticBG,0,200,renderer);

        player.render(renderer);

        healthBar.render(-13,0,renderer);
        //graphics.render(toado.x,toado.y,bird);
        explode.render(-195,0,renderer);
        for (Sprite* a: arrows)
        renderTexture(a->texture, a->x, a->y,renderer);

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
        if (!anyEventProcessed)  {
        player.currentTexture = 0;
        //if (player.isStanding && !player.Shooting && !player.Jumping) player.tick();
        //std::cerr << "worked" << std::endl;
        }
    }
    void Game::shootArrow()
    {
        Sprite *arrow = new Sprite();
        arrows.push_back(arrow);

        arrow->x = player.x;
        arrow->y = player.y;
        arrow->y += (player.h / 2) - (arrow->h / 2);
        arrow->dx = ARROW_SPEED;
        arrow->health = 1;
        arrow->texture = arrowTexture;
        SDL_QueryTexture(arrowTexture, NULL, NULL, &arrow->w, &arrow->h);

        //player.reload = PLAYER_RELOAD;
    }
    void Game::doArrows()
    {
        auto it = arrows.begin();
        while (it != arrows.end()) {
            auto temp = it++;
            Sprite* b = *temp;
            b->turnRight();
            b->movee();
//            if (bulletHitFighter(b) || b->offScreen()) {
//                delete b;
//                bullets.erase(temp);
//            }
        }
    }

