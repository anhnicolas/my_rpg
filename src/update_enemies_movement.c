/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-isaac.levy-piquet
** File description:
** enemy_creation
*/

#include "../include/my_rpg.h"

void update_enemy_movement_cop(enemy_t *enemy, float deltatime)
{
    if (enemy->type == COP && enemy->direction == 0 &&
    (enemy->current_image.x != 10 && enemy->current_image.x != 11 &&
    enemy->current_image.x != 12))
        enemy->pos.x -= enemy->velocity * (deltatime / 2);
}

void update_enemy_movement_drone(enemy_t *enemy, float deltatime)
{
    if (enemy->type == DRONE && enemy->offset <= enemy->offset_max &&
    enemy->direction == 0) {
        if (enemy->offset == enemy->offset_max) {
            enemy->offset = 0;
            enemy->direction = 1;
        }
        enemy->pos.x += enemy->velocity * (deltatime / 2);
        enemy->offset++;
    }
    if (enemy->type == DRONE && enemy->offset <= enemy->offset_max &&
    enemy->direction == 1) {
        if (enemy->offset == enemy->offset_max) {
            enemy->offset = 0;
            enemy->direction = 0;
        }
        enemy->pos.x -= enemy->velocity * (deltatime / 2);
        enemy->offset++;
    }
}
