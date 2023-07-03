/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-isaac.levy-piquet
** File description:
** enemy_creation
*/

#include "../include/my_rpg.h"

void set_enemy(enemy_t *enemy, int offset_max)
{
    enemy->scale = (sfVector2f){3, 3};
    enemy->size = sfTexture_getSize(enemy->texture);
    sfSprite_setTexture(enemy->sprite, enemy->texture, sfTrue);
    sfSprite_setPosition(enemy->sprite, enemy->pos);
    sfRectangleShape_setSize(enemy->rect, (sfVector2f){150, 220});
    sfRectangleShape_setPosition(enemy->rect, enemy->pos);
    enemy->velocity = 100;
    if (enemy->type == DRONE)
        enemy->life = 20;
    if (enemy->type == EGG_TURRET)
        enemy->life = 10;
    if (enemy->type == COP) {
        enemy->life = 30;
        enemy->velocity = 200;
        enemy->scale = (sfVector2f){4, 4};
    }
    sfSprite_setScale(enemy->sprite, enemy->scale);
    enemy->attack = 0; enemy->offset = 0;
    enemy->offset_max = offset_max;
    enemy->direction = 0;
}

void update_enemey_movement(enemy_t *enemy, float deltatime)
{
    if (enemy->type == DRONE)
        update_enemy_movement_drone(enemy, deltatime);
    if (enemy->type == COP)
        update_enemy_movement_cop(enemy, deltatime);
    sfRectangleShape_setPosition(enemy->rect, enemy->pos);
    sfSprite_setPosition(enemy->sprite, enemy->pos);
}

void update_enemy(enemy_t *enemy, int row, float deltatime)
{
    enemy->current_image.y = row;
    enemy->total_time += deltatime;

    if (enemy->total_time >= enemy->switch_time) {
        enemy->total_time -= enemy->switch_time;
        enemy->current_image.x++;
        if (enemy->current_image.x >= enemy->image_count.x)
            enemy->current_image.x = 0;
    }
    enemy->texture_rect.left = enemy->current_image.x *
            enemy->texture_rect.width;
    enemy->texture_rect.top = enemy->current_image.y *
        enemy->texture_rect.height;
    update_enemey_movement(enemy, deltatime);
    sfSprite_setTextureRect(enemy->sprite, enemy->texture_rect);
}

void anim_enemy_for_type(enemy_t *enemy, enemy_type_t type)
{
    if (type == DRONE) {
        enemy->type = DRONE;
        enemy->img_size[0] = 440;
        enemy->img_size[1] = 52;
        enemy->image_count = (sfVector2u){8, 1};
        enemy->switch_time = 0.3f;
    }
    if (type == EGG_TURRET) {
        enemy->type = EGG_TURRET;
        enemy->img_size[0] = 352; enemy->img_size[1] = 62;
        enemy->image_count = (sfVector2u) {8, 1};
        enemy->switch_time = 0.3f;
    }
    if (type == COP) {
        enemy->type = COP;
        enemy->img_size[0] = 793;
        enemy->img_size[1] = 64;
        enemy->image_count = (sfVector2u) {13, 1};
        enemy->switch_time = 0.1f;
    }
}

enemy_t *create_enemies(enemy_type_t type, sfVector2f pos, int offset_max)
{
    enemy_t *enemy = malloc(sizeof(enemy_t));

    if (!enemy)
        return NULL;
    enemy->pos = pos;
    enemy->sprite = sfSprite_create();
    if (type == DRONE)
        enemy->texture = sfTexture_createFromFile(DRONE_ASSET, NULL);
    if (type == EGG_TURRET)
        enemy->texture = sfTexture_createFromFile(EGG_TURRET_ASSET, NULL);
    if (type == COP)
        enemy->texture = sfTexture_createFromFile(COP_RUN_ASSET, NULL);
    enemy->rect = sfRectangleShape_create();
    anim_enemy_for_type(enemy, type);
    set_enemy(enemy, offset_max);
    enemy->total_time = 0.0f;
    enemy->current_image.x = 0;
    enemy->texture_rect.width = enemy->img_size[0] / enemy->image_count.x;
    enemy->texture_rect.height = enemy->img_size[1] / enemy->image_count.y;
    return enemy;
}
