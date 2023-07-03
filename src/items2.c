/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-isaac.levy-piquet
** File description:
** items2
*/
#include "my_rpg.h"
void draw_items2(game_t *g)
{
    if (g->items->boolheal4 == true)
        sfRenderWindow_drawSprite(WINDOW, g->items->heal4, NULL);
    if (g->items->boolheal5 == true)
        sfRenderWindow_drawSprite(WINDOW, g->items->heal5, NULL);
    if (g->items->boolheal6 == true)
        sfRenderWindow_drawSprite(WINDOW, g->items->heal6, NULL);
}
