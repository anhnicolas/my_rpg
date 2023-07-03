/*
** EPITECH PROJECT, 2023
** GRAVITY
** File description:
** fucntion that hable gravity
*/

#include "../include/my_rpg.h"

void falling(game_t *g)
{
    sfTime time;
    int dseconds;

    if (!PLAYER->island && !PLAYER->isJumping) {
        time = sfClock_getElapsedTime(PLAYER->gclock);
        dseconds = sfTime_asMilliseconds(time) / 10;
        PLAYER->isaac = 0.0981 * dseconds * 140;
        PLAYER->pos.y += PLAYER->isaac * (g->deltatime / 2);
        if (PLAYER->pos.y > 1350)
            PLAYER->pos.y = 0;
    }
}

void fall_lose(game_t *g)
{

    if (PLAYER->pos.y > 1350) {
        my_printf("YOU LOSE\n");
        sfRenderWindow_close(WINDOW);
    }
}
