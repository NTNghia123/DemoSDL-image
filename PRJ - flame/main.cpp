
#include "defs.h"
#include "sprite_player.h"
#include "background.h"
#include "gameloop.h"
using namespace std;

int main(int argc, char *argv[])
{
    srand(time(0));

    Game game;
	game.initGame();

    game.play();


//    SDL_DestroyTexture( birdTexture );
//    birdTexture = NULL;

    //quitLoop(renderer,window);
    return 0;
}
