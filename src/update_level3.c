/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-isaac.levy-piquet
** File description:
** update_level3
*/

#include <../include/my_rpg.h>

void update_level_3(game_t *g)
{
    float bg_posX = VIEW_POS.x - VIEW_SIZE.x / 2;
    float bg_posY = VIEW_POS.y - VIEW_SIZE.y / 2;
    LEVEL_3->bg_pos[0] = (sfVector2f){bg_posX, bg_posY};
    LEVEL_3->bg_pos[1] = (sfVector2f){bg_posX + LEVEL_3->bg_size[1].x
    * LEVEL_3->bg_scale[1].x, bg_posY};
    LEVEL_3->bg_pos[2] = (sfVector2f){bg_posX - PLAYER->pos.x * 0.2, bg_posY};
    LEVEL_3->bg_pos[3] = (sfVector2f){bg_posX - PLAYER->pos.x * 0.2
    + LEVEL_3->bg_size[3].x * LEVEL_3->bg_scale[3].x, bg_posY};
    LEVEL_3->bg_pos[4] = (sfVector2f){0, 0};
    LEVEL_3->bg_pos[5] = (sfVector2f){LEVEL_3->bg_size[5].x
    * LEVEL_3->bg_scale[5].x, 0};
    for (int i = 0; i < 6; i++) {
        sfSprite_setPosition(LEVEL_3->bg[i], LEVEL_3->bg_pos[i]);
    }
}

// void end_of_level3(game_t *g)
// {
//     if (PLAYER->pos.x > 1722 && PLAYER->pos.y <= 825 && ) {
//         fade_in(g);
//     }
// }

void update_level_3_all(game_t *g)
{
    player_movement(g);
    update_jump(g, 825);
    update_player(g);
    move_projectile(g);
    update_genemy(LEVEL_3->enemy, g);
    collide_enemy(g, LEVEL_3->enemy);
    shoot_enemy(g, LEVEL_3->enemy);
    update_level_3(g);
    event_phone(g);
    check_item_coli2(g);
}
