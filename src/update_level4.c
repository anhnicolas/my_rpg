/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-isaac.levy-piquet
** File description:
** update_level4
*/

#include <../include/my_rpg.h>

void update_level_4(game_t *g)
{
    LEVEL_4->bg_pos[0] = (sfVector2f){VIEW_POS.x - VIEW_SIZE.x / 2,
    VIEW_POS.y - VIEW_SIZE.y / 2};
    LEVEL_4->bg_pos[1] = (sfVector2f){VIEW_POS.x - VIEW_SIZE.x / 2
    - PLAYER->pos.x * 0.2, VIEW_POS.y - VIEW_SIZE.y / 2};
    LEVEL_4->bg_pos[2] = (sfVector2f){VIEW_POS.x - VIEW_SIZE.x / 2
    - PLAYER->pos.x * 0.2 + LEVEL_4->bg_size[1].x * LEVEL_4->bg_scale[1].x,
    VIEW_POS.y - VIEW_SIZE.y / 2};
    sfSprite_setPosition(LEVEL_4->thunder, LEVEL_4->bg_pos[0]);
    sfSprite_setPosition(LEVEL_4->bg[0], LEVEL_4->bg_pos[1]);
    sfSprite_setPosition(LEVEL_4->bg[1], LEVEL_4->bg_pos[2]);
    LEVEL_4->elapsed = sfClock_getElapsedTime(LEVEL_4->clock);
    if (sfTime_asMilliseconds(LEVEL_4->elapsed) > 100) {
        LEVEL_4->currentFrame = (LEVEL_4->currentFrame + 1) % 6;
        sfSprite_setTexture(LEVEL_4->thunder,
        LEVEL_4->thunder_t[LEVEL_4->currentFrame], sfTrue);
        sfClock_restart(LEVEL_4->clock);
    }
}

void update_level_4_all(game_t *g)
{
    player_movement(g);
    update_jump(g, 2000);
    update_player(g);
    move_projectile(g);
    update_level_4(g);
    collision_lvl4(g, g->level_4);
    event_phone(g);
    fall_lose(g);
}
