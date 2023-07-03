/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-isaac.levy-piquet
** File description:
** fade_function
*/

#include <../include/my_rpg.h>

void fade_in(game_t *g)
{
    int fadeSpeed = 2;

    for (int i = 0; i < 255; i+= fadeSpeed) {
        g->fadeAlpha = i;
        sfRectangleShape_setFillColor(g->fadeRect,
                            sfColor_fromRGBA(0, 0, 0, g->fadeAlpha));
        sfRenderWindow_drawRectangleShape(WINDOW, g->fadeRect, NULL);
        sfRenderWindow_display(WINDOW);
    }
}
