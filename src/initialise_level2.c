/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-isaac.levy-piquet
** File description:
** initialise_level2
*/

#include <../include/my_rpg.h>

void set_level2_background(level_2_t *level_2, game_t *g)
{
    LVL2_BG_SIZE[0] = sfTexture_getSize(LVL2_BG_T[0]);
    LVL2_BG_SIZE[1] = sfTexture_getSize(LVL2_BG_T[1]);
    LVL2_BG_SIZE[2] = sfTexture_getSize(LVL2_BG_T[2]);
    LVL2_BG_SCALE[0] = (sfVector2f){(float) W_WIDTH / LVL2_BG_SIZE[0].x,
    (float) W_HEIGHT / LVL2_BG_SIZE[0].y};
    LVL2_BG_SCALE[1] = (sfVector2f){(float) W_WIDTH / LVL2_BG_SIZE[1].x,
    ((float) W_HEIGHT) / LVL2_BG_SIZE[1].y};
    LVL2_BG_SCALE[2] = (sfVector2f){(float) W_WIDTH / LVL2_BG_SIZE[2].x,
    (float) W_HEIGHT / LVL2_BG_SIZE[2].y};
    for (int i = 0; i < 3; i++) {
        sfSprite_setTexture(LVL2_BG_S[i], LVL2_BG_T[i], sfTrue);
        sfSprite_setScale(LVL2_BG_S[i], LVL2_BG_SCALE[i]);
    }
}

void create_level2_background(level_2_t *level_2, game_t *g)
{
    LVL2_BG_S[0] = sfSprite_create();
    LVL2_BG_S[1] = sfSprite_create();
    LVL2_BG_S[2] = sfSprite_create();
    LVL2_BG_T[0] = sfTexture_createFromFile(LVL2_BG1_ASSETS, NULL);
    LVL2_BG_T[1] = sfTexture_createFromFile(LVL2_BG2_ASSETS, NULL);
    LVL2_BG_T[2] = sfTexture_createFromFile(LVL2_BG3_ASSETS, NULL);
}

void create_pnj(level_2_t *level_2)
{
    LVL2_PNJ = sfSprite_create();
    LVL2_PNJ_T[0] = sfTexture_createFromFile(LVL2_PNJ_ASSETS1, NULL);
    LVL2_PNJ_T[1] = sfTexture_createFromFile(LVL2_PNJ_ASSETS2, NULL);
    LVL2_PNJ_T[2] = sfTexture_createFromFile(LVL2_PNJ_ASSETS3, NULL);
    LVL2_PNJ_T[3] = sfTexture_createFromFile(LVL2_PNJ_ASSETS4, NULL);
    LVL2_PNJ_SIZE = sfTexture_getSize(LVL2_PNJ_T[0]);
    LVL2_PNJ_SCALE = (sfVector2f){-4, 4};
    sfSprite_setTexture(LVL2_PNJ, LVL2_PNJ_T[0], sfTrue);
    sfSprite_setScale(LVL2_PNJ, LVL2_PNJ_SCALE);
    sfSprite_setPosition(LVL2_PNJ, (sfVector2f){1500, 650});
}

void create_quest(level_2_t *level_2, game_t *g)
{
    level_2->press_f = sfText_create();
    sfText_setFont(level_2->press_f, g->main_menu->font);
    sfText_setString(level_2->press_f, "Press F to talk to the PNJ");
    sfText_setPosition(level_2->press_f, (sfVector2f){1300, 600});
    sfText_setCharacterSize(level_2->press_f, 90);
    sfText_setColor(level_2->press_f, sfWhite);
    level_2->quest = sfSprite_create();
    level_2->quest_t = sfTexture_createFromFile(LVL2_QUEST_ASSETS, NULL);
    sfSprite_setTexture(level_2->quest, level_2->quest_t, sfTrue);
    sfSprite_setPosition(level_2->quest, (sfVector2f){0, 0});
    sfSprite_setScale(level_2->quest, (sfVector2f){0.5, 0.5});
}

level_2_t *create_level_2(game_t *g)
{
    level_2_t *level_2 = malloc(sizeof(level_2_t));

    if (!level_2)
        return NULL;
    create_level2_background(level_2, g);
    set_level2_background(level_2, g);
    create_pnj(level_2);
    level_2->clock = sfClock_create();
    level_2->music = sfMusic_createFromFile(MUSIC_LVL2);
    create_quest(level_2, g);
    return level_2;
}
