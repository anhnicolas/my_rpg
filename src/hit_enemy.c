/*
** EPITECH PROJECT, 2023
** HIT ENEMY
** File description:
** function to handle collison with enemy
*/

#include "../include/my_rpg.h"

bool check_collisions(sfIntRect rect, enemy_t *enemy)
{
    sfFloatRect enemy_rect;
    sfIntRect int_rect;
    int top;
    int left;
    int width;
    int height;


    enemy_rect = sfRectangleShape_getGlobalBounds(enemy->rect);
    top = enemy_rect.top;
    left = enemy_rect.left;
    width = enemy_rect.width;
    height = enemy_rect.height;

    int_rect = (sfIntRect){left, top, width, height};
    if (sfIntRect_intersects(&rect, &int_rect, NULL)) {
        return true;
    }
    return false;
}

void earn_xp(game_t *g, enemy_t *enemy)
{
    if (enemy->life <= 0) {
        PLAYER->xp += 10;
    }
    if (PLAYER->xp >= 40) {
        PLAYER->xp = 0;
        PLAYER->level += 1;
    }
    PLAYER->hp_max = 3 + PLAYER->level;
}

void shoot_enemy(game_t *g, enemy_t *list)
{
    enemy_t *tmp = list;
    sfFloatRect spriteRect;
    sfIntRect int_rect;
    int top; int left; int width; int height;

    spriteRect = sfSprite_getGlobalBounds(PLAYER->projectile);
    top = spriteRect.top;
    left = spriteRect.left;
    width = spriteRect.width;
    height = spriteRect.height;
    int_rect = (sfIntRect){left, top, width, height};
    while (tmp != NULL) {
        if (check_collisions(int_rect, tmp)) {
            tmp->life -= 10;
            PLAYER->projectilePos.x = 10000;
        }
        tmp = tmp->next;
    }

}
void collide_enemy(game_t *g, enemy_t *list)
{
    enemy_t *tmp = list;

    PLAYER->crect.top = PLAYER->pos.y;
    PLAYER->crect.left = PLAYER->pos.x + (22 * 4);
    while (tmp != NULL) {
        if (check_collisions(PLAYER->crect, tmp)) {
            PLAYER->life -= 1;
        }
        tmp = tmp->next;
    }
}
