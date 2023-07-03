/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-isaac.levy-piquet
** File description:
** update_level2
*/

#include <../include/my_rpg.h>

void update_level_2(game_t *g)
{
    LEVEL_2->bg_pos[0] = (sfVector2f){VIEW_POS.x - VIEW_SIZE.x / 2,
    VIEW_POS.y - VIEW_SIZE.y / 2};
    LEVEL_2->bg_pos[1] = (sfVector2f){VIEW_POS.x - VIEW_SIZE.x / 2,
    VIEW_POS.y - VIEW_SIZE.y / 2};
    LEVEL_2->bg_pos[2] = (sfVector2f){VIEW_POS.x - VIEW_SIZE.x / 2,
    VIEW_POS.y - VIEW_SIZE.y / 2};
    for (int i = 0; i < 3; i++)
        sfSprite_setPosition(LEVEL_2->bg[i], LEVEL_2->bg_pos[i]);
    LEVEL_2->elapsed = sfClock_getElapsedTime(LEVEL_2->clock);
    if (sfTime_asMilliseconds(LEVEL_2->elapsed) > 100) {
        LEVEL_2->currentFrame = (LEVEL_2->currentFrame + 1) % 4;
        sfSprite_setTexture(LEVEL_2->pnj,
        LEVEL_2->pnj_t[LEVEL_2->currentFrame], sfTrue);
        sfClock_restart(LEVEL_2->clock);
    }
}

void end_of_level2(game_t *g)
{
    if (PLAYER->pos.x > 1722 && PLAYER->pos.y <= 825) {
        fade_in(g);
        level3_loop(g);
    }
}

void interact_pnj(game_t *g)
{
    if (sfKeyboard_isKeyPressed(sfKeyF)) {
        if (PLAYER->pos.x >= 1300 && PLAYER->pos.x <= 1800) {
            sfRenderWindow_drawSprite(WINDOW, LEVEL_2->quest, NULL);
        }
    }
}

void update_level_2_all(game_t *g)
{
    player_movement(g);
    update_jump(g, 825);
    update_player(g);
    move_projectile(g);
    update_level_2(g);
    event_phone(g);
    end_of_level2(g);
}
