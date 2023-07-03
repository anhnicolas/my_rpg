/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-isaac.levy-piquet
** File description:
** lvl1
*/

#include <enemies.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include "map.h"

#ifndef LVL1_H_
    #define LVL1_H_
    #define LVL1_BG_S level_1->bg
    #define LVL1_BG_T level_1->bg_t
    #define LVL1_BG_POS level_1->bg_pos
    #define LVL1_BG_SCALE level_1->bg_scale
    #define LVL1_BG_SIZE level_1->bg_size
    #define LVL1_OBJ level_1->vehicles
    #define LVL1_OBJ_TEXTURE level_1->vehicles_texture
    #define LVL1_OBJ_POS level_1->vehicles_pos
    #define LVL1_OBJ_SCALE level_1->vehicles_scale
    #define LVL1_OBJ_SIZE level_1->vehicles_size
    #define LVL1_OBJ_SPEED level_1->vehicles_speed
    #define LVL1_BG1_ASSETS "assets/level1/background/skyline-a.png"
    #define LVL1_BG2_ASSETS "assets/level1/background/skyline-b.png"
    #define LVL1_BG3_ASSETS "assets/level1/background/buildings-bg.png"
    #define LVL1_BG4_ASSETS "assets/level1/background/near-buildings-bg.png"

typedef struct level_1_s {
    sfSprite *bg[5];
    sfTexture *bg_t[5];
    sfVector2f bg_pos[5];
    sfVector2f bg_scale[5];
    sfVector2u bg_size[5];
    enemy_t *enemy;
    background_t *background;
    backelement_t *map;
    sfSprite *vehicles[4];
    sfTexture *vehicles_texture[4];
    sfVector2f vehicles_pos[4];
    sfVector2f vehicles_scale[4];
    sfVector2u vehicles_size[4];
    sfVector2f vehicles_speed[4];
    sfMusic *music;
} level_1_t;

#endif /* !LVL1_H_ */
