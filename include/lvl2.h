/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-isaac.levy-piquet
** File description:
** lvl2
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <SFML/Window.h>

#ifndef LVL2_H_
    #define LVL2_H_
    #define LVL2_BG_S level_2->bg
    #define LVL2_BG_T level_2->bg_t
    #define LVL2_BG_POS level_2->bg_pos
    #define LVL2_BG_SCALE level_2->bg_scale
    #define LVL2_BG_SIZE level_2->bg_size
    #define LVL2_PNJ level_2->pnj
    #define LVL2_PNJ_T level_2->pnj_t
    #define LVL2_PNJ_POS level_2->pnj_pos
    #define LVL2_PNJ_SCALE level_2->pnj_scale
    #define LVL2_PNJ_SIZE level_2->pnj_size
    #define LVL2_PNJ_ASSETS1 "assets/level2/Idle1.png"
    #define LVL2_PNJ_ASSETS2 "assets/level2/Idle2.png"
    #define LVL2_PNJ_ASSETS3 "assets/level2/Idle3.png"
    #define LVL2_PNJ_ASSETS4 "assets/level2/Idle4.png"
    #define LVL2_BG1_ASSETS "assets/level2/far-buildings.png"
    #define LVL2_BG2_ASSETS "assets/level2/back-buildings.png"
    #define LVL2_BG3_ASSETS "assets/level2/foreground.png"
    #define LVL2_QUEST_ASSETS "assets/level2/quest.png"

typedef struct level_2_s {
    sfSprite *bg[3];
    sfTexture *bg_t[3];
    sfVector2f bg_pos[3];
    sfVector2f bg_scale[3];
    sfVector2u bg_size[3];
    sfSprite *pnj;
    sfTexture *pnj_t[4];
    sfVector2f pnj_pos;
    sfVector2f pnj_scale;
    sfVector2u pnj_size;
    sfText *press_f;
    sfSprite *quest;
    sfTexture *quest_t;
    sfClock *clock;
    sfTime elapsed;
    int currentFrame;
    sfMusic *music;
} level_2_t;


#endif /* !LVL2_H_ */
