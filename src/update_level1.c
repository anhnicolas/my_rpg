/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-isaac.levy-piquet
** File description:
** level1
*/

#include <../include/my_rpg.h>

void update_level_1(game_t *g)
{
    LEVEL_1->bg_pos[0] = (sfVector2f){VIEW_POS.x - VIEW_SIZE.x / 2,
    VIEW_POS.y - VIEW_SIZE.y / 2};
    LEVEL_1->bg_pos[1] = (sfVector2f){VIEW_POS.x - VIEW_SIZE.x / 2
    - PLAYER->pos.x * 0.2, VIEW_POS.y - VIEW_SIZE.y / 2};
    LEVEL_1->bg_pos[2] = (sfVector2f){VIEW_POS.x - VIEW_SIZE.x / 2
    - PLAYER->pos.x * 0.2 + LEVEL_1->bg_size[2].x * LEVEL_1->bg_scale[2].x,
    VIEW_POS.y - VIEW_SIZE.y / 2};
    LEVEL_1->bg_pos[3] = (sfVector2f){VIEW_POS.x - VIEW_SIZE.x / 2
    - PLAYER->pos.x * 0.8, VIEW_POS.y - VIEW_SIZE.y / 2};
    LEVEL_1->bg_pos[4] = (sfVector2f){VIEW_POS.x - VIEW_SIZE.x / 2
    - PLAYER->pos.x * 0.8 + LEVEL_1->bg_size[4].x * LEVEL_1->bg_scale[4].x,
    VIEW_POS.y - VIEW_SIZE.y / 2};
    for (int i = 0; i < 5; i++)
        sfSprite_setPosition(LEVEL_1->bg[i], LEVEL_1->bg_pos[i]);
}

void update_level_1_objects(level_1_t *level_1, game_t *g)
{
    for (int i = 0; i < 4; i++) {
        if (LVL1_OBJ_POS[i].x + LVL1_OBJ_SIZE[i].x
        * LVL1_OBJ_SCALE[i].x < -1300) {
            LVL1_OBJ_POS[i].x = 2.5 * VIEW_SIZE.x + LVL1_OBJ_SIZE[i].x
            * LVL1_OBJ_SCALE[i].x;
            LVL1_OBJ_POS[i].y = VIEW_SIZE.y / 2 - LVL1_OBJ_SIZE[i].y *
            LVL1_OBJ_SCALE[i].y / 2 + rand() % 600 + 100;
        }
        sfSprite_setPosition(LVL1_OBJ[i], LVL1_OBJ_POS[i]);
        LVL1_OBJ_POS[i].x += LVL1_OBJ_SPEED[i].x;
    }
}

void end_level1(game_t *g)
{
    if (PLAYER->pos.x > 4300 && PLAYER->pos.y < 220) {
        fade_in(g);
        level2_loop(g);
    }
}

void update_level_1_all(game_t *g)
{
    player_movement(g);
    update_jump(g, 2000);
    update_player(g);
    move_projectile(g);
    update_genemy(LEVEL_1->enemy, g);
    update_level_1(g);
    update_level_1_objects(g->level_1, g);
    update_collision(g, g->level_1);
    collide_enemy(g, LEVEL_1->enemy);
    shoot_enemy(g, LEVEL_1->enemy);
    check_item_coli1(g);
    event_phone(g);
    fall_lose(g);
    end_level1(g);
}
