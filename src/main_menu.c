/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-isaac.levy-piquet
** File description:
** main_menu
*/

#include <../include/my_rpg.h>

void event_main_menu(game_t *g)
{
    while (sfRenderWindow_pollEvent(WINDOW, &EVENT)) {
        if (EVENT.type == sfEvtClosed)
            sfRenderWindow_close(WINDOW);
        if (EVENT.type == sfEvtKeyPressed && EVENT.key.code == sfKeyEnter) {
            fade_in(g);
            level1_loop(g);
        }
        update_main_menu_buttons(MAIN_MENU, g);
    }
}

void draw_main_menu(game_t *g)
{
    sfRenderWindow_clear(WINDOW, sfBlack);
    sfRenderWindow_drawSprite(WINDOW, MAIN_MENU->bg[0], NULL);
    sfRenderWindow_drawSprite(WINDOW, MAIN_MENU->bg[3], NULL);
    sfRenderWindow_drawSprite(WINDOW, MAIN_MENU->bg[1], NULL);
    sfRenderWindow_drawSprite(WINDOW, MAIN_MENU->bg[4], NULL);
    sfRenderWindow_drawSprite(WINDOW, MAIN_MENU->vehicles[1], NULL);
    sfRenderWindow_drawSprite(WINDOW, MAIN_MENU->vehicles[3], NULL);
    sfRenderWindow_drawSprite(WINDOW, MAIN_MENU->bg[2], NULL);
    sfRenderWindow_drawSprite(WINDOW, MAIN_MENU->bg[5], NULL);
    sfRenderWindow_drawSprite(WINDOW, MAIN_MENU->vehicles[0], NULL);
    sfRenderWindow_drawSprite(WINDOW, MAIN_MENU->vehicles[2], NULL);
    for (int i = 0; i < 3; i++)
        sfRenderWindow_drawText(WINDOW, MAIN_MENU->text[i], NULL);
    sfRenderWindow_display(WINDOW);
}

void update_main_menu2(game_t *g)
{
    MAIN_MENU->bg_pos[0].x -= MAIN_MENU->bg_speed[0].x;
    MAIN_MENU->bg_pos[1].x -= MAIN_MENU->bg_speed[1].x;
    MAIN_MENU->bg_pos[2].x -= MAIN_MENU->bg_speed[2].x;
    MAIN_MENU->bg_pos[3].x -= MAIN_MENU->bg_speed[0].x;
    MAIN_MENU->bg_pos[4].x -= MAIN_MENU->bg_speed[1].x;
    MAIN_MENU->bg_pos[5].x -= MAIN_MENU->bg_speed[2].x;
    sfSprite_setPosition(MAIN_MENU->bg[0], MAIN_MENU->bg_pos[0]);
    sfSprite_setPosition(MAIN_MENU->bg[1], MAIN_MENU->bg_pos[1]);
    sfSprite_setPosition(MAIN_MENU->bg[2], MAIN_MENU->bg_pos[2]);
    sfSprite_setPosition(MAIN_MENU->bg[3], MAIN_MENU->bg_pos[3]);
    sfSprite_setPosition(MAIN_MENU->bg[4], MAIN_MENU->bg_pos[4]);
    sfSprite_setPosition(MAIN_MENU->bg[5], MAIN_MENU->bg_pos[5]);
}

void update_main_menu(game_t *g)
{
    if (MAIN_MENU->bg_pos[0].x <= -1 * (float) W_WIDTH)
        MAIN_MENU->bg_pos[0].x = (float) W_WIDTH;
    if (MAIN_MENU->bg_pos[1].x <= -1 * (float) W_WIDTH)
        MAIN_MENU->bg_pos[1].x = (float) W_WIDTH;
    if (MAIN_MENU->bg_pos[2].x <= -1 * (float) W_WIDTH *
    MAIN_MENU->bg_scale[2].x)
        MAIN_MENU->bg_pos[2].x = (float) W_WIDTH * MAIN_MENU->bg_scale[2].x;
    if (MAIN_MENU->bg_pos[3].x <= -1 * (float) W_WIDTH)
        MAIN_MENU->bg_pos[3].x = (float) W_WIDTH;
    if (MAIN_MENU->bg_pos[4].x <= -1 * (float) W_WIDTH)
        MAIN_MENU->bg_pos[4].x = (float) W_WIDTH;
    if (MAIN_MENU->bg_pos[5].x <= -1 * (float) W_WIDTH *
    MAIN_MENU->bg_scale[2].x)
        MAIN_MENU->bg_pos[5].x = (float) W_WIDTH * MAIN_MENU->bg_scale[2].x;
    update_main_menu2(g);
}

void main_menu(game_t *g)
{
    sfRenderWindow_setFramerateLimit(WINDOW, 60);
    set_music(MAIN_MENU->music);
    while (sfRenderWindow_isOpen(WINDOW)) {
        MOUSE_POS = sfMouse_getPositionRenderWindow(WINDOW);
        event_main_menu(g);
        update_main_menu(g);
        update_main_menu_objects(MAIN_MENU, g);
        draw_main_menu(g);
    }
}
