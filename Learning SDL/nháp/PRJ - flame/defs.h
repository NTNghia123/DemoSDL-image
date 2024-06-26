#ifndef _DEFS__H
#define _DEFS__H

#define BG_DAY "img\\sky_crop.jpg" // cho scroll
#define BG_NIGHT "img\\night_sky.jpg"
//#define STATIC_BG_DAY "img\\grass_field_resize_afterAse.jpg"
//#define STATIC_BG_DAY "img\\bg_day.jpg"
#define STATIC_BG_DAY "img\\new_bg (1).jpg"
#define STATIC_BG_NIGHT "img\\red_night - rs.png"
#define WINDOW_TITLE "Hello World!"
#define TOWER_FILE "img\\tower_exploding_new.png"

#define PLAYER_NORMAL_IMG "img\\normal.png"
#define PLAYER_JUMPING_IMG "img\\jumpp.png"
#define PLAYER_SHOOTING_IMG "img\\shoot1.png"

#define ARROW_IMG "img\\arrow.png"
#define HEALTH_BAR "img\\health_bar.png"

#define ZOMBIE_ENTER "img\\zombie_enter.png"
#define ZOMBIE_WALK "img\\zombie_walk.png"
#define ZOMBIE_DIE "img\\zombie_die.png"
#define ZOMBIE_HEALTHBAR "img\\zhealthbar.png"
#define COMBO_LOADING_TIME 7

#define ZOMBIE_DEFAULT "img\\zombie.png"

#define PLAYER_DEFAULT "img\\shoot2.png"


const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 500;


const int MAX_KEYBOARD_KEYS = 350;
const int INIT_X = 130;
const int INIT_Y = 165;


const int TOWER_CLIPS[][4] ={
    {1476,663,492,663},
    {0,0,492,663},
    {492,0,492,663},
    {984,0,492,663},
    {1476,0,492,663},
    {0,663,492,663},
    {492,663,492,663},
    {984,663,492,663},
    {1476,663,492,663}
};
const int TOWER_FRAMES = 8;

const int HEALTH_BAR_CLIPS[][4] = {
    {0,0,224,83},
    {0,83,224,83},
    {0,166,224,83},
    {0,250,224,83},
    {0,333,224,83},
    {0,416,224,83}
};
const int HEALTH_BAR_FRAMES = 6;

const int PLAYER_CLIPS[][4] = {
    {0,0,119,119},
    {119,0,119,119},
    {238,0,119,119},
    {357,0,119,119}
};
const int PLAYER_FRAMES = sizeof(PLAYER_CLIPS)/sizeof(int)/4;

const int ZOMBIE_CLIPS[][4] = {
    {0,0,91,62},
    {91,0,91,62},
    {182,0,91,62},
    {273,0,91,62},
    {364,0,91,62}
};
const int ZOMBIE_FRAMES = sizeof(ZOMBIE_CLIPS)/sizeof(int)/4;

const int PAUSE_CLIPS[][4] = {
    {0,0,63,64},
    {63,0,63,64}
};
const int PAUSE_FRAMES = sizeof(PAUSE_CLIPS)/sizeof(int)/4;

const int BOOM_CLIPS[][4] = {
    {0,0,148,180},
    {148,0,148,180},
    {297,0,148,180},
    {445,0,148,180},
    {594,0,148,180},
    {742,0,148,180}
};
const int BOOM_FRAMES = sizeof(BOOM_CLIPS)/sizeof(int)/4 ;

const int FLAME_CLIPS[][4] = {
    {0,0,46,130},
    {0,130,46,130},
    {0,260,46,130},
    {0,390,46,130},
    {0,520,46,130},
    {0,650,46,130},
    {0,780,46,130}
};
const int FLAME_FRAMES = sizeof(FLAME_CLIPS)/sizeof(int)/4;


#endif

