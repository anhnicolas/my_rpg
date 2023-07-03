/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-isaac.levy-piquet
** File description:
** lvl4
*/

#include <enemies.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <SFML/Window.h>

#ifndef LVL4_H_
    #define LVL4_H_
    #define LVL4_THUNDER level_4->thunder
    #define LVL4_THUNDER_T level_4->thunder_t
    #define LVL4_BG_S level_4->bg
    #define LVL4_BG_T level_4->bg_t
    #define LVL4_BG_POS level_4->bg_pos
    #define LVL4_BG_SCALE level_4->bg_scale
    #define LVL4_BG_SIZE level_4->bg_size
    #define LVL4_BG_ASSETS "assets/level4/bgd/city.png"
    #define LVL4_THUNDER_ASSETS1 "assets/level4/bgd/thunders-sky1.png"
    #define LVL4_THUNDER_ASSETS2 "assets/level4/bgd/thunders-sky2.png"
    #define LVL4_THUNDER_ASSETS3 "assets/level4/bgd/thunders-sky3.png"
    #define LVL4_THUNDER_ASSETS4 "assets/level4/bgd/thunders-sky4.png"
    #define LVL4_THUNDER_ASSETS5 "assets/level4/bgd/thunders-sky5.png"
    #define LVL4_THUNDER_ASSETS6 "assets/level4/bgd/thunders-sky6.png"
    #define LVL4_MAP_ASSETS "assets/level4/maplvl4.png"

typedef struct level_4_s {
    sfSprite *thunder;
    sfSprite *bg[2];
    sfTexture *thunder_t[6];
    sfTexture *bg_t[2];
    sfVector2f bg_pos[3];
    sfVector2f bg_scale[2];
    sfVector2u bg_size[2];
    sfSprite *map;
    sfTexture *map_t;
    backelement_t *mapa;
    sfVector2f map_pos;
    sfVector2f map_scale;
    sfVector2u map_size;
    sfClock *clock;
    sfTime elapsed;
    int currentFrame;
    boss_t *boss;
    sfMusic *music;
} level_4_t;

#endif /* !LVL4_H_ */
