/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-isaac.levy-piquet
** File description:
** enemies_death
*/

#include "../include/my_rpg.h"

void enemy_death_animation(enemy_t *enemy)
{
    if (enemy->explosion->total_time >= enemy->explosion->switch_time) {
        enemy->total_time -= enemy->switch_time;
        enemy->explosion->current_image.x++;
    }
    enemy->texture_rect.left = enemy->current_image.x *
                               enemy->texture_rect.width;
    enemy->texture_rect.top = enemy->current_image.y *
                              enemy->texture_rect.height;
    sfSprite_setTextureRect(enemy->sprite, enemy->texture_rect);
}

void enemies_death_drone(enemy_t *enemy)
{
    enemy->scale = (sfVector2f){3, 3};
    sfSprite_setScale(enemy->sprite, enemy->scale);
    enemy->img_size[0] = 330;
    enemy->img_size[1] = 52;
    enemy->image_count = (sfVector2u){6, 1};
    enemy->switch_time = 0.1f;
    enemy->total_time = 0.6f;
    enemy->current_image.x = 0;
    enemy->current_image.y = 0;
    enemy->texture_rect.width = enemy->img_size[0] / enemy->image_count.x;
    enemy->texture_rect.height = enemy->img_size[1] / enemy->image_count.y;;
}

enemy_explosion_t *set_explosion_struct(enemy_t *enemy)
{
    enemy_explosion_t *tmp = malloc(sizeof(enemy_explosion_t));

    tmp->type = enemy->type;
    tmp->pos = enemy->pos;
    tmp->sprite = sfSprite_create();
    if (tmp->type == DRONE)
        enemy->texture = sfTexture_createFromFile(DRONE_EXPLOSION, NULL);
    if (tmp->type == EGG_TURRET)
        enemy->texture = sfTexture_createFromFile(EGG_TURRET_EXPLOSION, NULL);
    /*if (type == COP)
        enemy->texture = sfTexture_createFromFile(COP_EXPLOSION, NULL);*/
    tmp->size = sfTexture_getSize(tmp->texture);
    sfSprite_setTexture(tmp->sprite, tmp->texture, sfTrue);
    sfSprite_setPosition(tmp->sprite, tmp->pos);
    return tmp;
}

void enemies_death(enemy_t *enemy)
{
    enemy->explosion = set_explosion_struct(enemy);
    if (enemy->type == DRONE)
        enemies_death_drone(enemy);
}
