#include "gameloop.h"
#include "graphics.h"

void Game::initGame() {

	init();
	for (int i = 0; i < MAX_KEYBOARD_KEYS; i++) keyboard[i] = 0;
	window = initWin();
	renderer = initRen(window);

	fontScore = loadFont("assets/pixel.TTF", 80);
    fontText = loadFont("assets/Karma Suture.otf", 30);
    color = {255,69,100, 0};

	explode.initClip(loadTexture(TOWER_EXPLODE_FILE,renderer), TOWER_EXPLODE_FRAMES, TOWER_EXPLODE_CLIPS);
	healthBar.initClip(loadTexture(HEALTH_BAR,renderer), HEALTH_BAR_FRAMES, HEALTH_BAR_CLIPS);

    bg.setTexture(loadTexture(BG_IMAGE,renderer));
    staticBG = loadTexture(STATIC_BG_IMAGE,renderer);

    player.NormalTexture = loadTexture(PLAYER_NORMAL_IMG, renderer);
    player.JumpingTexture = loadTexture(PLAYER_JUMPING_IMG, renderer);
    player.ShootingTexture = loadTexture(PLAYER_SHOOTING_IMG, renderer);
    player.PlayerDefaultTexture = loadTexture(PLAYER_DEFAULT, renderer);
    player.initClip(player.ShootingTexture,PLAYER_FRAMES,PLAYER_CLIPS);
    player.PlayerInit();

    arrowTexture = loadTexture(ARROW_IMG,renderer);

    zombieDie = loadTexture(ZOMBIE_DIE,renderer);
    zombieEnter = loadTexture(ZOMBIE_ENTER,renderer);
    zombieWalk = loadTexture(ZOMBIE_WALK,renderer);
    zombieDefault = loadTexture(ZOMBIE_DEFAULT,renderer);

    reset();
}
void Game::play(){
    bool quit = false;
    while( !quit ) {
        if ( explode.currentFrame >= 1 ) FPS = 5;
        else FPS = 10;
        int frameStart = SDL_GetTicks();
        prepareScene(renderer);

        if (player.health == 0  && explode.currentFrame == 7 ){
                reset();
                SDL_Delay(1000 * 10/ FPS);
        }
        get();
        player.updateToadoPlayer(keyboard);
        player.moveee();

        if ( canShootFrame < ARROW_LOADING_TIME ) canShootFrame ++;
        if ( player.Shooting && (canShootFrame == ARROW_LOADING_TIME) ){
                GameshootArrow ();
                canShootFrame = 0;
        }

        bg.scroll(BG_SCROLL_SPEED);
        render(bg,renderer);
        renderTexture(staticBG,0,200,renderer);

        renderScore(point, fontScore,color,renderer);

        spawnZombies();
        doZombies();
        doArrows();

        player.render(renderer);

        healthBar.currentFrame = player.health ;
        healthBar.render(-13,0,renderer);

        if ( healthBar.currentFrame == 0){
            explode.tick();
        }
        explode.render(-195,0,renderer);

        presentScene(renderer);

        int frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < 1000 / FPS) {
            SDL_Delay((1000 / FPS) - frameTime);
        }
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
                    }
                    break;
                case SDL_KEYUP:
                    if (event.key.repeat == 0
                        && event.key.keysym.scancode < MAX_KEYBOARD_KEYS) {
                        keyboard[event.key.keysym.scancode] = 0;
                    }
                    break;

                default:
                    break;
            }
        }
        for ( int i = 0 ; i < MAX_KEYBOARD_KEYS ; i++){
        if ( keyboard[i]){
            anyEventProcessed = true;
            break;
        }
        }
        if (!anyEventProcessed){
        player.currentTexture = 0;
        player.Jumping = false;
        player.Shooting = false;
        player.isStanding = true;
        player.Shooting = false;
        player.isShooting = false;
        }
    }
    void Game::GameshootArrow()
    {
        Sprite *arrow = new Sprite();
        arrows.push_back(arrow);

        arrow->x = player.x;
        arrow->y = player.y;
        arrow->x += player.w;
        arrow->y += (player.h / 2) - (arrow->h / 2) - 10;
        arrow->dx = ARROW_SPEED;
        arrow->texture = arrowTexture;
        SDL_QueryTexture(arrowTexture, NULL, NULL, &arrow->w, &arrow->h);

    }
    bool Sprite::isCollides(Sprite* arrow) {
	    return (std::max(x, arrow->x ) < std::min(x + w, arrow->x + arrow->w))
	        && (std::max(y, arrow->y) < std::min(y + h, arrow->y + arrow->h));
	}
    bool Game::checkCollides(Sprite * arrow)
    {
        for (Zombie* zombie: zombies) {
            bool flag = zombie->isCollides(arrow);
            if (flag) {
                if (zombie->health > 0) zombie->health = 0;
                return true;
            }
        }
        return false;
    }
    void Game::doArrows()
    {
        for (Sprite* a: arrows)
        renderTexture(a->texture, a->x, a->y,renderer);

        auto it = arrows.begin();
        while (it != arrows.end()) {
            auto temp = it++;
            Sprite* a = *temp;
            if ( a->x > SCREEN_WIDTH || checkCollides(a) ) {
                delete a;
                arrows.erase(temp);
            }
            a->movee();
        }
        auto ptr = zombies.begin();
        while (ptr != zombies.end()) {
            auto temp = ptr++;
            Zombie* zombie = *temp;
            if(!zombie->isDying) zombie->movee();
        }
    }
    void Game::spawnZombies() {

        if (--zombieSpawnTime <= 0) {
            Zombie *zombie = new Zombie();
            zombies.push_back(zombie);
            zombie->x = SCREEN_WIDTH - 70 - ( rand() % 100);
            zombie->y = 190 + 75 * (rand() %4) ;

            zombie->isDying = false;
            int decideHard = 0;
            if ( point <= 20 ) decideHard = 15;
            else if ( point <= 40) decideHard = 10;
            else decideHard = 3 - rand() % 3;
            zombie->dx =  -20 + ( rand() % decideHard);
            zombie->health = 1;

            zombie->ZombieTexture.push_back(zombieEnter);
            zombie->ZombieTexture.push_back(zombieWalk);
            zombie->ZombieTexture.push_back(zombieDie);

            decideHard = 0;
            if ( point <= 20 ) decideHard = 2;
            else if ( point <= 40) decideHard = 3;
            else decideHard = 6 + rand() % 2;
            zombieSpawnTime = 8 - (rand() % decideHard );

            zombie->initClip(zombieEnter,ZOMBIE_FRAMES,ZOMBIE_CLIPS);
            SDL_QueryTexture(zombieDefault, NULL, NULL, &zombie->w, &zombie->h);
        }
    }

    void Game::doZombies()
    {
        auto it = zombies.begin();
        while (it != zombies.end()) {
            auto temp = it++;
            Zombie* zombie = *temp;
        if ( zombie->x < 205 ){
            if ( player.health != 0 ) player.health --  ;
            delete zombie;
            zombies.erase(temp);
            continue;
        }
        if ( zombie->health == -1  && zombie->currentTexture == 2 && zombie->currentFrame == 3){
            point ++;
            delete zombie;
            zombies.erase(temp);
            continue;
        }
        else if ( zombie->health == 0  ){
            zombie->isDying = true;
            zombie->currentTexture = 2;
            zombie->currentFrame = 0;
            zombie->health = -1;
        }
            if ( zombie->currentTexture == 0 && zombie->currentFrame == 4 ){
                zombie->currentTexture = 1;
                zombie->currentFrame = 0;
            }
            zombie->renderZombie(renderer);
            zombie->tick();
        }
	}
    void Game::empty(std::list<Sprite*>& entities) {
        while (!entities.empty()) {
            Sprite* e = entities.front();
            entities.pop_front();
            delete e;
        }
    }
    void Game::emptyZombie(std::list<Zombie*>& entities) {
        while (!entities.empty()) {
            Zombie* e = entities.front();
            entities.pop_front();
            delete e;
        }
    }
    void Game::reset()
    {
//    for (Sprite* a : arrows) delete a;
//    arrows.clear();
//
//    for (Zombie* z : zombies) delete z;
//    zombies.clear();
    point = 0 ;
    emptyZombie(zombies);
    empty(arrows);

    zombieSpawnTime = 0;

    player.health = 5;
    explode.currentFrame = 0;
    bg.scrollingOffset = 0;

	}

