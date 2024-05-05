#include "gameloop.h"
#include "graphics.h"
#include "score.h"

void Game::initGame() {

	init();
	eraseFileData("score.txt");
	eraseFileData("top_score.txt");
	for (int i = 0; i < MAX_KEYBOARD_KEYS; i++) keyboard[i] = 0;
	window = initWin();
	renderer = initRen(window);

	fontScore = loadFont("assets/pixel.TTF", 80);
    fontText = loadFont("assets/Karma Suture.otf", 30);
    color = {255,69,100, 0};

    MenuTexture.texture = loadTexture("img\\menu.jpg",renderer);
    pauseMenuTexture.texture = loadTexture("img\\pause_menu.png",renderer);
    replayButton.texture = loadTexture("img\\square.png",renderer);
    toMenuButton.texture = loadTexture("img\\square.png",renderer);
    resumeButton.texture = loadTexture("img\\resumeButton.png",renderer);
    SDL_QueryTexture(replayButton.texture, NULL, NULL, &replayButton.w, &replayButton.h);
    SDL_QueryTexture(replayButton.texture, NULL, NULL, &toMenuButton.w, &toMenuButton.h);
    SDL_QueryTexture(resumeButton.texture, NULL, NULL, &resumeButton.w, &resumeButton.h);

	tower.initClip(loadTexture(TOWER_FILE,renderer), TOWER_FRAMES, TOWER_CLIPS);
	healthBar.initClip(loadTexture(HEALTH_BAR,renderer), HEALTH_BAR_FRAMES, HEALTH_BAR_CLIPS);
	pauseButton.initClip(loadTexture("img\\pause_frame.png",renderer), PAUSE_FRAMES, PAUSE_CLIPS);
	SDL_QueryTexture(loadTexture("img\\pause_1frame.png",renderer), NULL, NULL, &pauseButton.w, &pauseButton.h);

    bg.setTexture(loadTexture(BG_DAY,renderer));
    STATIC_BG_day = loadTexture(STATIC_BG_DAY,renderer);
    STATIC_BG_night = loadTexture(STATIC_BG_NIGHT,renderer);
    SCROLLING_BG_day = loadTexture(BG_DAY,renderer);
    SCROLLING_BG_night = loadTexture(BG_NIGHT,renderer);

    player.NormalTexture = loadTexture(PLAYER_NORMAL_IMG, renderer);
    player.JumpingTexture = loadTexture(PLAYER_JUMPING_IMG, renderer);
    player.ShootingTexture = loadTexture(PLAYER_SHOOTING_IMG, renderer);
    player.PlayerDefaultTexture = loadTexture(PLAYER_DEFAULT, renderer);
    player.initClip(player.ShootingTexture,PLAYER_FRAMES,PLAYER_CLIPS);
    player.PlayerInit();

    arrowTexture = loadTexture(ARROW_IMG,renderer);
    fireTexture = loadTexture("img\\fire.png",renderer);
    blueTexture = loadTexture("img\\blue.png",renderer);
    purpleTexture = loadTexture("img\\purple.png",renderer);
    ARROW_LOADING_TIME = 3;

    zombieDie = loadTexture(ZOMBIE_DIE,renderer);
    zombieEnter = loadTexture(ZOMBIE_ENTER,renderer);
    zombieWalk = loadTexture(ZOMBIE_WALK,renderer);
    zombieFreeze = loadTexture("img\\freeze.png",renderer);
    zombieFreezing = loadTexture("img\\freezing.png",renderer);
    zombieDefault = loadTexture(ZOMBIE_DEFAULT,renderer);
    zombieHealthBar = loadTexture(ZOMBIE_HEALTHBAR,renderer);

    status = 0;
    score = 0;
    bestScore = 0;
    reset();
}
void Game::play(){
    bool quit = false;
    while( !quit ) {
        if ( tower.currentFrame >= 1 ) FPS = 5;
        else FPS = 10;
        int frameStart = SDL_GetTicks();
        switch (status) {
        case MENU:
        prepareScene(renderer);
        getMenu();
        renderTexture(MenuTexture.texture,0,0,renderer);
        presentScene(renderer);
        break;
        case PLAY_GAME:
        if (pause) {
            //std::cerr << "pause" << std::endl;
            getIfPause();
            updateEventIfPause();
            pauseButton.render(SCREEN_WIDTH - 63,0,renderer);
            renderTextureCenter(pauseMenuTexture.texture,renderer);
            renderTexture(replayButton.texture,257,218,renderer);
            replayButton.x = 257;
            replayButton.y = 218;
            renderTexture(toMenuButton.texture,362,218,renderer);
            toMenuButton.x = 362;
            toMenuButton.y = 218;
            //renderTexture(pausedButton.texture,460,218,renderer);
            renderTexture(resumeButton.texture,263,311,renderer);
            resumeButton.x = 263;
            resumeButton.y = 311;
            presentScene(renderer);
        }
        else if (!pause){
        get();
        updateEvent();
        prepareScene(renderer);

        if (bg.scrollingOffset == 4){
            if (night){
                night = false;
                bg.setTexture(SCROLLING_BG_day);
                staticBG = STATIC_BG_day;
                ARROW_LOADING_TIME = 3;
            }
            else{
                night = true;
                bg.setTexture(SCROLLING_BG_night);
                staticBG = STATIC_BG_night;
                ARROW_LOADING_TIME = 2;
            }
        }

        if (player.health == 0  && tower.currentFrame == 7 ){
                reset();
                SDL_Delay(1000 * 10/ FPS);
        }
        player.moveee();

        if ( canShootFrame < ARROW_LOADING_TIME ) canShootFrame ++;
        if ( player.Shooting && (canShootFrame >= ARROW_LOADING_TIME) ){
                if (night)GameshootNightArrow ();
                else GameshootDayArrow();
                canShootFrame = 0;
        }

        bg.scroll(BG_SCROLL_SPEED);
        render(bg,renderer);
        renderTexture(staticBG,0,200,renderer);

        spawnZombies();
        doZombies();
        doArrows();

        healthBar.currentFrame = player.health ;
        healthBar.render(-13,0,renderer);

        if ( healthBar.currentFrame == 0){
            tower.tick();
        }

        writeGameScore(score);
        readBestscore(bestScore,score);
        renderScore(score, fontScore,color,renderer);
        renderText("High Score: " + std::to_string(bestScore),fontText,color,0,0,renderer);

        player.render(renderer);
        tower.render(-195,0,renderer);
        pauseButton.render(SCREEN_WIDTH - 63,0,renderer);

        presentScene(renderer);
        }
        break;
        }

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
                case SDL_MOUSEBUTTONDOWN:
                    SDL_GetMouseState(&mouseX,&mouseY);
                    if( mouseX >= SCREEN_WIDTH - pauseButton.w && mouseY <= pauseButton.h ){
                        //if (pause) pause = false;
                        if (!pause) pause = true;
                        pauseButton.tick();
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
    void Game::getMenu() {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    exit(0);
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    //SDL_GetMouseState(&mouseX,&mouseY);
                    //if( mouseX >= SCREEN_WIDTH - pauseButton.w && mouseY <= pauseButton.h ){}
                    status = PLAY_GAME;
                    reset();
                    break;
                default:
                    break;
            }
        }
    }
    bool Game::isInRect(const Sprite& sprite) {
        bool insideX = (mouseX >= sprite.x) && (mouseX <= sprite.x + sprite.w);
        bool insideY = (mouseY >= sprite.y) && (mouseY <= sprite.y + sprite.h);
        return insideX && insideY;
    }
    void Game::getIfPause(){
        SDL_Event event;
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
                case SDL_MOUSEBUTTONDOWN:
                    SDL_GetMouseState(&mouseX,&mouseY);
                    if (mouseX >= SCREEN_WIDTH - pauseButton.w && mouseY <= pauseButton.h ){
                        if (pause) pause = false;
                        pauseButton.tick();
                    }
                    if (isInRect(resumeButton)) {
                        pause = false;
                        pauseButton.tick();
                    }
                    if (isInRect(replayButton)) reset();
                    if (isInRect(toMenuButton)){
                        reset();
                        status = MENU;
                    }
                    break;
                default:
                    break;
            }
        }
    }
    void Game::updateEventIfPause(){
        if (keyboard[SDL_SCANCODE_P]) {
            if (pause) pause = false;
            pauseButton.tick();
        }
    }
    void Game::updateEvent(){
        player.dx = player.dy = 0;
        if (keyboard[SDL_SCANCODE_UP]) player.turnUpp();
        if (keyboard[SDL_SCANCODE_DOWN]) player.turnDownn();
        if (keyboard[SDL_SCANCODE_S]) player.shootArrow();
        if (keyboard[SDL_SCANCODE_P]) {
            //if (pause) pause = false;
            if (!pause) pause = true;
            pauseButton.tick();
        }
    }
    void Game::GameshootDayArrow()
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
    void Game::GameshootNightArrow()
    {
        Sprite *arrow = new Sprite();
        arrows.push_back(arrow);

        arrow->x = player.x;
        arrow->y = player.y;
        arrow->x += player.w;
        arrow->y += (player.h / 2) - (arrow->h / 2) - 10;
        arrow->dx = ARROW_SPEED;
        arrow->randomTexture = rand() % 3;
        switch (arrow->randomTexture){
        case 0:
            arrow->texture = fireTexture;
        break;
        case 1:
            arrow->texture = blueTexture;
        break;
        case 2:
            arrow->texture = purpleTexture;
            arrow->penetrate = 1;
        break;
        }
        SDL_QueryTexture(arrowTexture, NULL, NULL, &arrow->w, &arrow->h);
    }
    bool Sprite::isCollides(Sprite* arrow) {
	    return (std::max(x, arrow->x ) < std::min(x + w, arrow->x + arrow->w))
	        && (std::max(y, arrow->y) < std::min(y + h, arrow->y + arrow->h));
	}
    bool Game::checkCollides(Sprite * arrow)
    {
        for (Zombie* zombie: zombies) {
            if (zombie->isCollides(arrow)) {
            if (zombie->nightZombie == false){
                if (zombie->health > 0) zombie->health = 0;
            }
            else {
                if (zombie->health > 0) zombie->health --;
                switch (arrow->randomTexture){
            case 0:
                if ( zombie->health > 0) zombie->health --;
                break;
            case 1:
                zombie->x += 50;
                zombie->dx = -1;
                if (zombie->health > 0){
                    zombie->currentTexture = ZOMBIE_FREEZE_TEXT;
                    zombie->currentFrame = 0;
                }
                break;
            case 2:
                zombie->dx = -6;
                if ( arrow->penetrate == 1){
                    arrow->penetrate --;
                    return false;
                }
                break;
                }
            }
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
            if ( !night ){
                    if ( score <= 20 ) decideHard = 15;
                    else if ( score <= 40) decideHard = 10;
                    else decideHard = rand() % 2 + 1;
                    zombie->dx =  -25 + ( rand() % decideHard);
                    zombie->health = 1;
                    zombie->nightZombie = false;
            }else{
                    if ( score <= 20 ) decideHard = 15;
                    else if ( score <= 40) decideHard = 10;
                    else decideHard = 3 - rand() % 3;
                    zombie->dx =  -20 + ( rand() % decideHard);
                    zombie->health = 2;
                    zombie->nightZombie = true;
            }

            zombie->ZombieTexture.push_back(zombieEnter);
            zombie->ZombieTexture.push_back(zombieWalk);
            zombie->ZombieTexture.push_back(zombieDie);
            zombie->ZombieTexture.push_back(zombieFreeze);
            zombie->ZombieTexture.push_back(zombieFreezing);

            decideHard = 0;
            if ( score <= 20 ) decideHard = 2;
            else if ( score <= 40) decideHard = 3;
            else decideHard = 6 + rand() % 3;
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
        if ( zombie->health == -1  && zombie->currentTexture == ZOMBIE_DIE_TEXT && zombie->currentFrame == 3){
            score ++;
            delete zombie;
            zombies.erase(temp);
            continue;
        }
        else if ( zombie->health == 0  ){
            zombie->isDying = true;
            zombie->currentTexture = ZOMBIE_DIE_TEXT;
            zombie->currentFrame = 0;
            zombie->health = -1;
        }
            if ( zombie->currentTexture == ZOMBIE_ENTER_TEXT && zombie->currentFrame == 4 ){
                zombie->currentTexture = ZOMBIE_WALK_TEXT;
                zombie->currentFrame = 0;
            }
            if ( zombie->currentTexture == ZOMBIE_FREEZE_TEXT && zombie->currentFrame == 4 ){
                zombie->currentTexture = ZOMBIE_FREEZING_TEXT;
                zombie->currentFrame = 0;
            }
            zombie->renderZombie(renderer);
            zombie->tick();
            if ( zombie->health == 1 && zombie->nightZombie) renderTexture(zombieHealthBar,zombie->x + 10,zombie->y - 10 ,renderer);
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
    pause = false;
    rewriteTopScore(score);
    score = 0 ;
    eraseFileData("score.txt");

    emptyZombie(zombies);
    empty(arrows);

    zombieSpawnTime = 0;
    ARROW_LOADING_TIME = 3;
    canShootFrame = ARROW_LOADING_TIME;

    night = false;
    staticBG = STATIC_BG_day;
    bg.setTexture(SCROLLING_BG_day);
    player.health = 5;
    tower.currentFrame = 0;
    bg.scrollingOffset = 0;
	}

