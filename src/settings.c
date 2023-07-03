/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-isaac.levy-piquet
** File description:
** settings
*/

#include "my_rpg.h"

settings_t *initsettings2(settings_t *settings)
{
    settings->quest = sfSprite_create();
    settings->mark = sfSprite_create();
    settings->sprite = sfSprite_create();
    settings->textmark = sfTexture_createFromFile("assets/set/mark.png",NULL);
    settings->phone1 = sfTexture_createFromFile("assets/set/phone.png", NULL);
    settings->phone2 = sfTexture_createFromFile("assets/set/phoneb.png", NULL);
    settings->textinv = sfTexture_createFromFile("assets/set/inv.png", NULL);
    sfSprite_setTexture(settings->inv, settings->textinv, sfTrue);
    sfSprite_setTexture(settings->mark, settings->textmark, sfTrue);
    sfSprite_setTexture(settings->sprite, settings->phone1, sfTrue);
    return settings;
}

int fullscreen_launch(sfFloatRect rect, game_t *g)
{
    game_t *game;

    if (g->event.type == sfEvtMouseButtonPressed){
        MOUSE_POS = sfMouse_getPositionRenderWindow(WINDOW);
        rect = sfText_getGlobalBounds(g->settings->fullscreen);
        if (sfFloatRect_contains(&rect, MOUSE_POS.x, MOUSE_POS.y)){
            sfRenderWindow_close(WINDOW);
            game = create_game_fullscreen();
            main_menu(game);
            destroy_all(game);
            return 1;
        }
        return 0;
    }
}

int windowed_launch(sfFloatRect rect, game_t *g)
{
    game_t *game;

    rect = sfText_getGlobalBounds(g->settings->windowed);
    if (g->event.type == sfEvtMouseButtonPressed){
        if (sfFloatRect_contains(&rect, MOUSE_POS.x, MOUSE_POS.y)){
            sfRenderWindow_close(WINDOW);
            game = create_game();
            main_menu(game);
            destroy_all(game);
            return 1;
        }
    }
    return 0;
}

int event_setting(sfFloatRect rect, game_t *g)
{
    while (sfRenderWindow_pollEvent(g->w->window, &g->event)) {
        if (g->event.type == sfEvtClosed){
            sfRenderWindow_close(g->w->window);
            return 1;
        }
        if (fullscreen_launch(rect, g) == 1)
            return 1;
        if (windowed_launch(rect, g) == 1)
            return 1;
    }
    return 0;
}

void settings_loop(game_t *g)
{
    sfVector2f tmp = {920.F , 500.F};
    sfFloatRect rect;
    tmp.x -= 400;
    tmp.y -= 300;
    sfText_setString(g->settings->fullscreen, "Fullscreen");
    sfText_setString(g->settings->windowed, "Windowed");
    sfText_setPosition(g->settings->fullscreen, tmp);
    sfText_setFillColor(g->settings->fullscreen, sfWhite);
    sfText_setFillColor(g->settings->windowed, sfWhite);
    tmp.x += 600;
    sfText_setPosition(g->settings->windowed, tmp);
    sfRenderWindow_drawText(WINDOW, g->settings->fullscreen, NULL);
    sfRenderWindow_drawText(WINDOW, g->settings->windowed, NULL);
    while (1){
        if (event_setting(rect, g) == 1)
            return;
        sfRenderWindow_display(WINDOW);
    }
}
