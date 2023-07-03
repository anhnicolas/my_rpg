/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-isaac.levy-piquet
** File description:
** main_menu2
*/

#include <../include/my_rpg.h>

void update_main_menu_objects(main_menu_t *main_menu, game_t *g)
{
    for (int i = 0; i < 4; i++) {
        if (OBJ_POS[i].x + OBJ_SIZE[i].x * OBJ_SCALE[i].x < -1300) {
            OBJ_POS[i].x = g->w->size.x + OBJ_SIZE[i].x * OBJ_SCALE[i].x;
            OBJ_POS[i].y = g->w->size.y / 2 - OBJ_SIZE[i].y *
            OBJ_SCALE[i].y / 2 + rand() % 200 + 100;
        }
        sfSprite_setPosition(OBJ[i], OBJ_POS[i]);
        OBJ_POS[i].x += OBJ_SPEED[i].x;
    }
}

void pressed(game_t *g)
{
    for (int i = 0; i < 3; i++) {
        MAIN_MENU->text_rect[i] = sfText_getGlobalBounds(MAIN_MENU->text[i]);
        if (sfFloatRect_contains(&MAIN_MENU->text_rect[i], MOUSE_POS.x,
        MOUSE_POS.y))
            sfText_setColor(MAIN_MENU->text[i], sfRed);
    }
}

void moved(game_t *g)
{
    for (int i = 0; i < 3; i++) {
        MAIN_MENU->text_rect[i] = sfText_getGlobalBounds(MAIN_MENU->text[i]);
        if (sfFloatRect_contains(&MAIN_MENU->text_rect[i], MOUSE_POS.x,
        MOUSE_POS.y))
            sfText_setColor(MAIN_MENU->text[i], sfWhite);
        else
            sfText_setColor(MAIN_MENU->text[i], sfYellow);
    }
}

void released(game_t *g)
{
    for (int i = 0; i < 3; i++)
        MAIN_MENU->text_rect[i] = sfText_getGlobalBounds(MAIN_MENU->text[i]);
    if (sfFloatRect_contains(&MAIN_MENU->text_rect[0], MOUSE_POS.x,
    MOUSE_POS.y)) {
        fade_in(g);
        level1_loop(g);
    }
    if (sfFloatRect_contains(&MAIN_MENU->text_rect[2], MOUSE_POS.x,
    MOUSE_POS.y))
        sfRenderWindow_close(WINDOW);
}

void update_main_menu_buttons(main_menu_t *main_menu, game_t *g)
{
    if (EVENT.type == sfEvtMouseButtonPressed)
        pressed(g);
    if (EVENT.type == sfEvtMouseButtonReleased)
        released(g);
    if (EVENT.type == sfEvtMouseMoved)
        moved(g);
}
