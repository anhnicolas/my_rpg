/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-isaac.levy-piquet
** File description:
** settings2
*/

#include "my_rpg.h"

void submenu1(game_t *g)
{
    int a = 1;
    sfVector2i pos;
    sfFloatRect rect;
    sfVector2f tmp = VIEW_POS;
    char *str = NULL;

    while (a == 1){
        tmp = VIEW_POS;
        tmp.x -= 570;
        tmp.y -= 200;
        sfSprite_setPosition(g->settings->inv,tmp);
        tmp.x += 200;
        tmp.y += 300;
        submenu2(g, str, tmp, rect);
        rect = sfSprite_getGlobalBounds(g->settings->mark);
        a = evtsubmenu(g, a, rect, pos);
    }
}

void setbutpressed1(game_t *g, sfVector2f pos, sfFloatRect rect)
{
    int a = rect.height / 3;
    rect.left -= 50;
    rect.height = rect.height / 3;
    if (sfFloatRect_contains(&rect,pos.x,pos.y) == sfTrue)
        submenu1(g);
    rect.top += a;
    if (sfFloatRect_contains(&rect,pos.x,pos.y) == sfTrue)
        return;
    rect.top += a;
    if (sfFloatRect_contains(&rect,pos.x,pos.y) == sfTrue){
        sfRenderWindow_close(WINDOW);
        g->settings->state = 0;
    }
    rect = sfSprite_getGlobalBounds(g->settings->mark);
    if (sfFloatRect_contains(&rect,pos.x,pos.y) == sfTrue)
        g->settings->state = 0;
}

void event_loop_in_game1(game_t *g)
{
    sfVector2i pos;
    sfVector2f opos;
    sfFloatRect rect;

    while (sfRenderWindow_pollEvent(g->w->window, &g->event)) {
        if (g->event.type == sfEvtClosed){
            sfRenderWindow_close(g->w->window);
            g->settings->state = 0;
        }
        if (g->event.type == sfEvtMouseButtonPressed){
            rect = sfSprite_getGlobalBounds(g->settings->sprite);
            pos = sfMouse_getPositionRenderWindow(g->w->window);
            opos = sfRenderWindow_mapPixelToCoords(g->w->window, pos, g->view);
            setbutpressed1(g, opos, rect);
        }
    }
}

void open_in_game_menu1(game_t *g)
{
    sfVector2f tmp = VIEW_POS;
    sfSprite_setPosition(g->settings->sprite, tmp);
    tmp.x += 230;
    sfSprite_setPosition(g->settings->mark, tmp);
    sfSprite_setTexture(g->settings->sprite, g->settings->phone2, sfTrue);
    while (g->settings->state == 1){
        event_loop_in_game1(g);
        sfRenderWindow_drawSprite(g->w->window,g->settings->sprite, NULL);
        sfRenderWindow_drawSprite(g->w->window,g->settings->mark, NULL);
        sfRenderWindow_display(g->w->window);
    }
    sfSprite_setTexture(g->settings->sprite, g->settings->phone1, sfTrue);
}

void event_phone(game_t *g)
{
    sfFloatRect rect;
    sfVector2f mouse_pos;
    if (g->event.type == sfEvtMouseButtonPressed){
        rect = sfSprite_getGlobalBounds(g->settings->sprite);
        mouse_pos = (sfVector2f){g->event.mouseButton.x,g->event.mouseButton.y};
        rect.top = 0.F;
        rect.left = 1970.F - rect.width;
        rect.width = 100;
        rect.height = 100;
        if (sfFloatRect_contains(&rect,mouse_pos.x,mouse_pos.y) == sfTrue){
            g->settings->state = 1;
            open_in_game_menu1(g);
        }
    }
    if (g->event.key.code == sfKeyEscape){
        g->settings->state = 1;
        open_in_game_menu1(g);
    }
}
