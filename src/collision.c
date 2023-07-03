/*
** EPITECH PROJECT, 2023
** COLLISION
** File description:
** FUNTIOJ TO COLLIDE
*/

#include <../include/my_rpg.h>

void touch_floor(game_t *g, int bot, int left, sfColor pixelColor)
{
    if (pixelColor.r == 255 && pixelColor.g == 0 && pixelColor.b == 0) {
        PLAYER->island = true;
        PLAYER->isJumping = false;
        PLAYER->velocity.y = 0;
        sfClock_restart(g->player->gclock);
    } else
        PLAYER->island = false;
}

void update_collision(game_t *g, level_1_t *l1)
{
    int bot;
    int left;
    int i;
    sfVector2f pos = g->player->pos;
    sfIntRect t_rect = g->player->texture_rect;
    bot = (pos.y + (t_rect.height * 4)) / 2;
    left = pos.x / 2;
    if (bot < 0)
        bot = 0;
    for (i = 0; i < t_rect.width * 4; i ++) {
            sfColor pixelColor = sfImage_getPixel(l1->map->image, left, bot);
            touch_floor(g, bot, left, pixelColor);
    }
}

void collision_stair(game_t *g, int bot, int left, sfColor pixelColor)
{
    if (pixelColor.r == 0 && pixelColor.g == 255 && pixelColor.b == 0) {
        PLAYER->pos.y -= 4 * (g->deltatime / 2);
        PLAYER->island = true;
        PLAYER->isJumping = false;
        PLAYER->velocity.y = 0;
        sfClock_restart(g->player->gclock);
    }
}

void collision_lvl4(game_t *g, level_4_t *l4)
{
    int bot;
    int left;
    int i;
    sfVector2f pos = g->player->pos;
    sfIntRect t_rect = g->player->texture_rect;
    bot = (pos.y + (t_rect.height * 4)) / 2;
    left = pos.x / 2;
    if (bot < 0)
        bot = 0;
    for (i = 0; i < t_rect.width * 4; i ++) {
            sfColor pixelColor = sfImage_getPixel(l4->mapa->image, left, bot);
            touch_floor(g, bot, left, pixelColor);
            collision_stair(g, bot, left, pixelColor);
    }
}
