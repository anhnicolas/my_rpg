/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-isaac.levy-piquet
** File description:
** initialise_level3
*/

#include <../include/my_rpg.h>

void set_level3_background(level_3_t *level_3, game_t *g)
{
    for (int i = 0; i < 6; i++)
        LVL3_BG_SIZE[i] = sfTexture_getSize(LVL3_BG_T[i]);
    LVL3_BG_SCALE[0] = (sfVector2f){10, (float) W_HEIGHT / LVL3_BG_SIZE[0].y};
    LVL3_BG_SCALE[1] = (sfVector2f){10, (float) W_HEIGHT / LVL3_BG_SIZE[1].y};
    LVL3_BG_SCALE[2] = (sfVector2f){5, (float) W_HEIGHT / LVL3_BG_SIZE[2].y};
    LVL3_BG_SCALE[3] = (sfVector2f){5, (float) W_HEIGHT / LVL3_BG_SIZE[3].y};
    LVL3_BG_SCALE[4] = (sfVector2f){4, (float) W_HEIGHT / LVL3_BG_SIZE[4].y};
    LVL3_BG_SCALE[5] = (sfVector2f){4, (float) W_HEIGHT / LVL3_BG_SIZE[5].y};
    for (int i = 0; i < 6; i++) {
        sfSprite_setTexture(LVL3_BG_S[i], LVL3_BG_T[i], sfTrue);
        sfSprite_setScale(LVL3_BG_S[i], LVL3_BG_SCALE[i]);
    }
}

void create_level3_background(level_3_t *level_3, game_t *g)
{
    LVL3_BG_S[0] = sfSprite_create();
    LVL3_BG_S[1] = sfSprite_create();
    LVL3_BG_S[2] = sfSprite_create();
    LVL3_BG_S[3] = sfSprite_create();
    LVL3_BG_S[4] = sfSprite_create();
    LVL3_BG_S[5] = sfSprite_create();
    LVL3_BG_T[0] = sfTexture_createFromFile(LVL3_BG1_ASSETS, NULL);
    LVL3_BG_T[1] = sfTexture_createFromFile(LVL3_BG1_ASSETS, NULL);
    LVL3_BG_T[2] = sfTexture_createFromFile(LVL3_BG2_ASSETS, NULL);
    LVL3_BG_T[3] = sfTexture_createFromFile(LVL3_BG2_ASSETS, NULL);
    LVL3_BG_T[4] = sfTexture_createFromFile(LVL3_BG3_ASSETS, NULL);
    LVL3_BG_T[5] = sfTexture_createFromFile(LVL3_BG4_ASSETS, NULL);
}

void add_enemies_level_3(level_3_t *level3, game_t *g)
{
    enemy_t *cop_1 = create_enemies(COP, (sfVector2f){3000, 760}, 1000);
    enemy_t *cop_2 = create_enemies(COP, (sfVector2f){4000, 760}, 1000);
    enemy_t *cop_3 = create_enemies(COP, (sfVector2f){5000, 760}, 1000);
    enemy_t *cop_4 = create_enemies(COP, (sfVector2f){6000, 760}, 1000);

    level3->enemy = NULL;
    add_enemy_to_list(cop_1, &level3->enemy);
    add_enemy_to_list(cop_2, &level3->enemy);
    add_enemy_to_list(cop_3, &level3->enemy);
    add_enemy_to_list(cop_4, &level3->enemy);
}

level_3_t *create_level_3(game_t *g)
{
    level_3_t *level_3 = malloc(sizeof(level_3_t));

    if (!level_3)
        return NULL;
    create_level3_background(level_3, g);
    set_level3_background(level_3, g);
    add_enemies_level_3(level_3, g);
    level_3->music = sfMusic_createFromFile(MUSIC_LVL3);
    return level_3;
}
