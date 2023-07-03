/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-isaac.levy-piquet
** File description:
** player_movement
*/

#include <../include/my_rpg.h>

void jump_ability(game_t *g)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace) && !PLAYER->isJumping) {
        PLAYER->isJumping = true;
        PLAYER->velocity.y = PLAYER->jumpSpeed;
    }
}

int mobility(game_t *g)
{
    int i = 0;
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        PLAYER->pos.x -= PLAYER->velocity.x * (g->deltatime / 2);
        PLAYER->frame_data = 4;
        i = 1;
    }
    return (i);
}

void player_movement(game_t *g)
{
    int i;

    jump_ability(g);
    i = mobility(g);
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        PLAYER->pos.x += PLAYER->velocity.x * (g->deltatime / 2);
        PLAYER->frame_data = 3;
        i = 1;
    }
    if (i == 0) {
        PLAYER->frame_data = 2;
        PLAYER->anim_speed = 30;
    }
    player_attack(g);
    if (i == 1)
        PLAYER->anim_speed = 10;
    sfRectangleShape_setPosition(PLAYER->rect, PLAYER->pos);
    sfSprite_setPosition(PLAYER->sprite, PLAYER->pos);
}

void update_jump(game_t *g, float groundHeight)
{

    if (PLAYER->isJumping) {
        PLAYER->velocity.y += PLAYER->gravity * (g->deltatime / 2);
        PLAYER->pos.y += PLAYER->velocity.y * (g->deltatime / 2);
        if (PLAYER->velocity.y >= PLAYER->maxFallSpeed) {
            PLAYER->velocity.y = PLAYER->maxFallSpeed;
        }
        if (PLAYER->pos.y >= groundHeight) {
            PLAYER->isJumping = false;
            PLAYER->pos.y = groundHeight;
            PLAYER->velocity.y = 0;
        }
        sfClock_restart(PLAYER->gclock);
    }
    if (PLAYER->isJumping) {
        PLAYER->frame_data = 5;
        PLAYER->anim_speed = 10;
    }
    falling(g);
}

void update_player(game_t *g)
{
    int time;
    int anim_speed = PLAYER->anim_speed;

    PLAYER->time = sfClock_getElapsedTime(PLAYER->clock);
    time = PLAYER->time.microseconds / 10000.0;
    sfIntRect texture_rect = PLAYER->texture_rect;
    texture_rect.top = 12 + ((PLAYER->frame_data) * 77);
    texture_rect.left = 13 + (71 * (time / anim_speed));
    if (time / anim_speed >= PLAYER->nb_frame[PLAYER->frame_data]) {
        sfClock_restart(PLAYER->clock);
    }
    PLAYER->texture_rect = texture_rect;
    sfSprite_setTextureRect(PLAYER->sprite, texture_rect);
}
