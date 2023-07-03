/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-isaac.levy-piquet
** File description:
** destroy2
*/

#include <../include/my_rpg.h>

void destroy_level_1(game_t *g)
{
    for (int i = 0; i < 5; i++) {
        sfTexture_destroy(LEVEL_1->bg_t[i]);
        sfSprite_destroy(LEVEL_1->bg[i]);
    }
    for (int i = 0; i < 4; i++) {
        sfTexture_destroy(LEVEL_1->vehicles_texture[i]);
        sfSprite_destroy(LEVEL_1->vehicles[i]);
    }
    free_enemy_list(LEVEL_1->enemy);
    sfMusic_destroy(LEVEL_1->music);
    free(LEVEL_1);
}

void destroy_level_2(game_t *g)
{
    for (int i = 0; i < 3; i++) {
        sfTexture_destroy(LEVEL_2->bg_t[i]);
        sfSprite_destroy(LEVEL_2->bg[i]);
    }
    for (int i = 0; i < 4; i++)
        sfTexture_destroy(LEVEL_2->pnj_t[i]);
    sfSprite_destroy(LEVEL_2->pnj);
    sfClock_destroy(LEVEL_2->clock);
    sfMusic_destroy(LEVEL_2->music);
    sfText_destroy(LEVEL_2->press_f);
    sfSprite_destroy(LEVEL_2->quest);
    sfTexture_destroy(LEVEL_2->quest_t);
    free(LEVEL_2);
}

void destroy_level_3(game_t *g)
{
    for (int i = 0; i < 6; i++) {
        sfTexture_destroy(LEVEL_3->bg_t[i]);
        sfSprite_destroy(LEVEL_3->bg[i]);
    }
    sfMusic_destroy(LEVEL_3->music);
    free(LEVEL_3);
}

void destroy_level_4(game_t *g)
{
    for (int i = 0; i < 6; i++) {
        sfTexture_destroy(LEVEL_4->thunder_t[i]);
    }
    sfSprite_destroy(LEVEL_4->thunder);
    sfSprite_destroy(LEVEL_4->bg[0]);
    sfTexture_destroy(LEVEL_4->bg_t[0]);
    sfSprite_destroy(LEVEL_4->bg[1]);
    sfTexture_destroy(LEVEL_4->bg_t[1]);
    sfSprite_destroy(LEVEL_4->map);
    sfTexture_destroy(LEVEL_4->map_t);
    sfClock_destroy(LEVEL_4->clock);
    sfMusic_destroy(LEVEL_4->music);
    free(LEVEL_4);
}
