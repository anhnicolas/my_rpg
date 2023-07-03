/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-isaac.levy-piquet
** File description:
** lvl3
*/

#include <enemies.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <SFML/Window.h>

#ifndef LVL3_H_
    #define LVL3_H_
    #define LVL3_BG_S level_3->bg
    #define LVL3_BG_T level_3->bg_t
    #define LVL3_BG_POS level_3->bg_pos
    #define LVL3_BG_SCALE level_3->bg_scale
    #define LVL3_BG_SIZE level_3->bg_size
    #define LVL3_BG1_ASSETS "assets/level3/bgd/back.png"
    #define LVL3_BG2_ASSETS "assets/level3/bgd/middle.png"
    #define LVL3_BG3_ASSETS "assets/level3/bgd/foreground.png"
    #define LVL3_BG4_ASSETS "assets/level3/bgd/foreground-empty.png"

typedef struct level_3_s {
    sfSprite *bg[6];
    sfTexture *bg_t[6];
    sfVector2f bg_pos[6];
    sfVector2f bg_scale[6];
    sfVector2u bg_size[6];
    enemy_t *enemy;
    sfMusic *music;
} level_3_t;


#endif /* !LVL3_H_ */
