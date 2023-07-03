/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-isaac.levy-piquet
** File description:
** destroy
*/

#include <../include/my_rpg.h>

void destroy_main_menu(game_t *g)
{
    for (int i = 0; i < 3; i++) {
        sfTexture_destroy(MAIN_MENU->bg_texture[i]);
        sfText_destroy(MAIN_MENU->text[i]);
    }
    for (int i = 0; i < 4; i++) {
        sfTexture_destroy(MAIN_MENU->vehicles_texture[i]);
        sfSprite_destroy(MAIN_MENU->vehicles[i]);
    }
    for (int i = 0; i < 6; i++)
        sfSprite_destroy(MAIN_MENU->bg[i]);
    sfTexture_destroy(MAIN_MENU->title_texture);
    sfSprite_destroy(MAIN_MENU->title);
    sfTexture_destroy(MAIN_MENU->press_enter_texture);
    sfSprite_destroy(MAIN_MENU->press_enter_button);
    sfFont_destroy(MAIN_MENU->font);
    sfMusic_destroy(MAIN_MENU->music);
    free(MAIN_MENU);
}

void destroy_settings(game_t *g)
{
    sfText_destroy(g->settings->attack);
    sfSprite_destroy(g->settings->sprite);
    sfSprite_destroy(g->settings->inv);
    sfSprite_destroy(g->settings->mark);
    sfSprite_destroy(g->settings->quest);
    sfTexture_destroy(g->settings->phone1);
    sfTexture_destroy(g->settings->phone2);
    sfTexture_destroy(g->settings->textinv);
    sfTexture_destroy(g->settings->textmark);
    sfFont_destroy(g->settings->font);
    free(g->settings);
}

void destroy_all(game_t *g)
{
    sfRectangleShape_destroy(g->fadeRect);
    sfClock_destroy(g->clock);
    sfView_destroy(g->view);
    sfClock_destroy(PLAYER->clock);
    sfTexture_destroy(PLAYER->texture);
    sfSprite_destroy(PLAYER->sprite);
    sfRectangleShape_destroy(PLAYER->rect);
    sfMusic_destroy(PLAYER->projectileSound);
    sfSprite_destroy(PLAYER->projectile);
    sfClock_destroy(PLAYER->projectileClock);
    sfRenderWindow_destroy(g->w->window);
    destroy_main_menu(g);
    destroy_settings(g);
    destroy_level_1(g);
    destroy_level_2(g);
    destroy_level_3(g);
    destroy_level_4(g);
    free(PLAYER);
    free(g->w);
    free(g);
}
