/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** settings
*/
#include "../include/my_rpg.h"

char *int_to_str(int num)
{
    int temp = num, i = 0, j = 0;
    int len = 0;
    char* str;
    while (temp > 0) {
        len++;
        temp /= 10;
    }
    str = malloc((len + 1) * sizeof(char));
    str[len] = '\0';
    while (num > 0) {
        str[i++] = (num % 10) + '0';
        num /= 10;
    }
    while (j < i / 2) {
        char temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = temp;
        j++;
    }
    return str;
}

settings_t *initsettings(void)
{
    settings_t *settings = malloc(sizeof(settings_t));
    settings->font = sfFont_createFromFile("assets/set/arial.ttf");
    settings->state = 0;
    settings->attack = sfText_create();
    sfText_setCharacterSize(settings->attack, 70);
    sfText_setFillColor(settings->attack, sfBlack);
    sfText_setFont(settings->attack, settings->font);
    settings->fullscreen = sfText_copy(settings->attack);
    settings->windowed = sfText_copy(settings->attack);
    settings->font = sfFont_createFromFile(BUTTON_FONT_PATH);
    sfText_setFont(settings->fullscreen, settings->font);
    sfText_setFont(settings->windowed, settings->font);
    settings->inv = sfSprite_create();
    return initsettings2(settings);
}

int evtsubmenu(game_t *g, int a, sfFloatRect rect, sfVector2i pos)
{
    sfVector2f opos;
    if (g->event.type == sfEvtMouseButtonPressed){
        pos = sfMouse_getPositionRenderWindow(g->w->window);
        opos = sfRenderWindow_mapPixelToCoords(g->w->window,pos,g->view);
        if (sfFloatRect_contains(&rect,opos.x,opos.y) == sfTrue)
            a = 0;
    }
    while (sfRenderWindow_pollEvent(g->w->window, &g->event)){
        if (g->event.type == sfEvtClosed){
            sfRenderWindow_close(g->w->window);
            a = 0;
            g->settings->state = 0;
        }
    }
    return a;
}

int check_item_inv1(game_t *g, sfVector2f pos, int tmp)
{
    if (g->items->boolheal1 == false && tmp > 0){
        sfSprite_setPosition(g->items->heal1, pos);
        sfRenderWindow_drawSprite(WINDOW, g->items->heal1, NULL);
        tmp -= 1;
    }
    pos.x += 120;
    if (g->items->boolheal2 == false && tmp > 0){
        sfSprite_setPosition(g->items->heal2, pos);
        sfRenderWindow_drawSprite(WINDOW, g->items->heal2, NULL);
        tmp -= 1;
    }
    pos.x -= 120;
    pos.y += 110;
    if (g->items->boolheal3 == false && tmp > 0){
        sfSprite_setPosition(g->items->heal3, pos);
        sfRenderWindow_drawSprite(WINDOW, g->items->heal3, NULL);
        tmp -= 1;
    }
    return tmp;
}

int check_item_inv2(game_t *g, sfVector2f pos, int tmp)
{
    if (g->items->boolheal4 == false && tmp > 0){
        sfSprite_setPosition(g->items->heal4, pos);
        sfRenderWindow_drawSprite(WINDOW, g->items->heal4, NULL);
        tmp -= 1;
    }
    pos.x -= 120;
    pos.y += 110;
    if (g->items->boolheal5 == false && tmp > 0){
        sfSprite_setPosition(g->items->heal5, pos);
        sfRenderWindow_drawSprite(WINDOW, g->items->heal5, NULL);
        tmp -= 1;
    }
    pos.x += 120;
    if (g->items->boolheal6 == false && tmp > 0){
        sfSprite_setPosition(g->items->heal6, pos);
        sfRenderWindow_drawSprite(WINDOW, g->items->heal6, NULL);
        tmp -= 1;
    }
    return tmp;
}
