/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-isaac.levy-piquet
** File description:
** initialise_player
*/

#include <../include/my_rpg.h>

int *create_frametable(int *nb_frame, int size)
{
    int *frametable = malloc(sizeof(int) * size);
    int i;
    for (i = 0; i < size; i++) {
        frametable[i] = nb_frame[i];
    }

    return frametable;
}

void create_attack(player_t *player)
{
    PROJECTILE = sfSprite_create();
    PROJECTILE_TEXTURE[0] = sfTexture_createFromFile(SHOOT_ASSET1, NULL);
    PROJECTILE_TEXTURE[1] = sfTexture_createFromFile(SHOOT_ASSET2, NULL);
    PROJECTILE_TEXTURE[2] = sfTexture_createFromFile(SHOOT_ASSET3, NULL);
    PROJECTILE_SPEED = 1500;
    sfSprite_setScale(PROJECTILE, (sfVector2f){10, 10});
    sfSprite_setTexture(PROJECTILE, PROJECTILE_TEXTURE[0], sfTrue);
    PROJECTILE_SOUND = sfMusic_createFromFile("assets/sound/beam.ogg");
    PROJECTILE_CLOCK = sfClock_create();
    PROJECTILE_FRAME = 0;
}

void set_player(player_t *player)
{
    player->scale = (sfVector2f){4, 4};
    player->size = sfTexture_getSize(player->texture);
    sfSprite_setTexture(player->sprite, player->texture, sfTrue);
    sfSprite_setPosition(player->sprite, player->pos);
    sfSprite_setScale(player->sprite, player->scale);
    player->life = 100;
    player->attack = 10;
    player->attack2 = 20;
    player->velocity = (sfVector2f){600, 0};
    player->direction = 0;
    player->isJumping = false;
    player->jumpSpeed = -1600;
    player->gravity = 4000;
    player->maxFallSpeed = 3500;
}

void set_param(player_t *player)
{
    player->frame_data = 2;
    player->anim_speed = 25;
    player->clock = sfClock_create();
    player->gclock = sfClock_create();
    player->time = sfClock_getElapsedTime(player->clock);
    player->seconds = player->time.microseconds / 1000000.0;
    sfIntRect texture_rect = {12, 12 + ((player->frame_data ) * 81) , 51, 51};
    sfIntRect rect = {player->pos.x, player->pos.y, 20, 45};
    player->crect = rect;
    sfRectangleShape_setPosition(player->rect, player->pos);
    player->texture_rect = texture_rect;
    sfSprite_setTextureRect(player->sprite, player->texture_rect);
}

player_t *create_player(game_t *g)
{
    player_t *player = malloc(sizeof(player_t));
    if (!player)
        return NULL;
    player->sprite = sfSprite_create();
    player->texture = sfTexture_createFromFile("assets/player/players.png",
    NULL);
    player->rect = sfRectangleShape_create();
    int nb_frame[6] = {0, 0, 3, 7, 7, 3};
    set_player(player);
    player->island = false;
    player->nb_frame = create_frametable(nb_frame, 6);
    set_param(player);
    create_attack(player);
    player->xp = 0;
    player->level = 1;
    player->life_max = 3;
    return player;
}
