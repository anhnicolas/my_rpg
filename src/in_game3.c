/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-isaac.levy-piquet
** File description:
** in_game3
*/

#include "my_rpg.h"

void draw_items_in_inv(game_t *g)
{
    int tmp = g->items->nb_potion;
    sfVector2f pos = VIEW_POS;

    pos.x -= 100;
    pos.y -= 70;
    tmp = check_item_inv1(g, pos, tmp);
    pos.x += 120;
    pos.y += 110;
    tmp = check_item_inv2(g, pos, tmp);
}

void submenu2(game_t *g, char *str, sfVector2f tmp, sfFloatRect rect)
{
    str = int_to_str(g->player->attack);
    sfText_setString(g->settings->attack, str);
    free(str);
    sfText_setPosition(g->settings->attack, tmp);
    sfRenderWindow_drawSprite(g->w->window, g->settings->inv, NULL);
    draw_items_in_inv(g);
    sfRenderWindow_drawSprite(g->w->window, g->settings->mark, NULL);
    sfRenderWindow_drawText(g->w->window,g->settings->attack,NULL);
    str = int_to_str(g->player->life);
    sfText_setString(g->settings->attack, str);
    free(str);
    tmp.y += 200;
    sfText_setPosition(g->settings->attack, tmp);
    sfRenderWindow_drawText(g->w->window,g->settings->attack,NULL);
    sfRenderWindow_display(g->w->window);
}

void use_heal(game_t *g)
{
    if (g->event.key.code == sfKeyA && g->items->nb_potion > 0){
        g->player->life = 50;
        g->items->nb_potion -= 1;
    }
}
