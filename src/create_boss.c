/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-isaac.levy-piquet
** File description:
** create_boss.c
*/

#include "../include/my_rpg.h"

boss_back_arm_t *create_boss_back_arm()
{
    boss_back_arm_t *torso = malloc(sizeof(boss_torso_t));

    if (!torso)
        return NULL;
    torso->pos = (sfVector2f){3200, 400};
    torso->sprite = sfSprite_create();
    torso->texture = sfTexture_createFromFile(BOSS_BACK_ARM, NULL);
    torso->img_size[0] = 183;
    torso->img_size[1] = 50;
    torso->scale = (sfVector2f){4, 4};
    torso->size = sfTexture_getSize(torso->texture);
    sfSprite_setTexture(torso->sprite, torso->texture, sfTrue);
    sfSprite_setPosition(torso->sprite, torso->pos);
    torso->velocity = 50;
    torso->direction = 0;
    return torso;
}

boss_front_arm_t *create_boss_front_arm()
{
    boss_front_arm_t *torso = malloc(sizeof(boss_torso_t));

    if (!torso)
        return NULL;
    torso->pos = (sfVector2f){3700, 400};
    torso->sprite = sfSprite_create();
    torso->texture = sfTexture_createFromFile(BOSS_FRONT_ARM, NULL);
    torso->img_size[0] = 183;
    torso->img_size[1] = 50;
    torso->scale = (sfVector2f){4, 4};
    torso->size = sfTexture_getSize(torso->texture);
    sfSprite_setTexture(torso->sprite, torso->texture, sfTrue);
    sfSprite_setPosition(torso->sprite, torso->pos);
    torso->velocity = 50;
    torso->direction = 0;
    return torso;
}

boss_head_t *create_boss_head()
{
    boss_head_t *torso = malloc(sizeof(boss_torso_t));

    if (!torso)
        return NULL;
    torso->pos = (sfVector2f){3500, 250};
    torso->sprite = sfSprite_create();
    torso->rect = sfRectangleShape_create();
    torso->texture = sfTexture_createFromFile(BOSS_HEAD, NULL);
    torso->img_size[0] = 183; torso->img_size[1] = 50;
    torso->image_count = (sfVector2u) {3, 1}; torso->scale = (sfVector2f){4, 4};
    torso->size = sfTexture_getSize(torso->texture);
    sfSprite_setTexture(torso->sprite, torso->texture, sfTrue);
    sfSprite_setPosition(torso->sprite, torso->pos);
    sfRectangleShape_setSize(torso->rect, (sfVector2f){150, 220});
    sfRectangleShape_setPosition(torso->rect, torso->pos);
    torso->velocity = 50; torso->direction = 0;
    torso->current_image.x = 0;
    torso->texture_rect.width = torso->img_size[0] / torso->image_count.x;
    torso->texture_rect.height = torso->img_size[1] / torso->image_count.y;
    return torso;
}

boss_torso_t *create_boss_torso()
{
    boss_torso_t *torso = malloc(sizeof(boss_torso_t));

    if (!torso)
        return NULL;
    torso->pos = (sfVector2f){3500, 400};
    torso->sprite = sfSprite_create();
    torso->rect = sfRectangleShape_create();
    torso->texture = sfTexture_createFromFile(BOSS_TORSO, NULL);
    torso->img_size[0] = 183; torso->img_size[1] = 50;
    torso->image_count = (sfVector2u) {3, 1}; torso->scale = (sfVector2f){4, 4};
    torso->size = sfTexture_getSize(torso->texture);
    sfSprite_setTexture(torso->sprite, torso->texture, sfTrue);
    sfSprite_setPosition(torso->sprite, torso->pos);
    sfRectangleShape_setSize(torso->rect, (sfVector2f){150, 220});
    sfRectangleShape_setPosition(torso->rect, torso->pos);
    torso->velocity = 50; torso->direction = 0;
    torso->current_image.x = 0;
    torso->texture_rect.width = torso->img_size[0] / torso->image_count.x;
    torso->texture_rect.height = torso->img_size[1] / torso->image_count.y;
    return torso;
}
