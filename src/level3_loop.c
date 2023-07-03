/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-isaac.levy-piquet
** File description:
** level3_loop
*/

#include <../include/my_rpg.h>

void event_loop_level3(game_t *g)
{
    while (sfRenderWindow_pollEvent(WINDOW, &g->event)) {
        if (g->event.type == sfEvtClosed)
            sfRenderWindow_close(WINDOW);
        if (EVENT.type == sfEvtKeyPressed && EVENT.key.code == sfKeyEnter) {
            fade_in(g);
            PLAYER->isJumping = false;
            PLAYER->pos.y = 2000;
            PLAYER->velocity.y = 0;
            PLAYER->island = true;
            level4_loop(g);
        }
        if (g->event.type == sfEvtKeyPressed)
            use_heal(g);
    }
}

void draw_objects_level3(game_t *g)
{
    sfVector2f tmp = VIEW_POS;

    tmp.x += 850;
    tmp.y = 0;
    sfRenderWindow_clear(WINDOW, sfBlack);
    for (int i = 0; i < 6; i++)
        sfRenderWindow_drawSprite(WINDOW, LEVEL_3->bg[i], NULL);
    sfRenderWindow_drawRectangleShape(WINDOW, PLAYER->rect, NULL);
    sfRenderWindow_drawSprite(WINDOW, PLAYER->sprite, NULL);
    sfRenderWindow_drawSprite(WINDOW, PLAYER->projectile, NULL);
    display_enemies(LEVEL_3->enemy, g);
    draw_items2(g);
    sfSprite_setPosition(g->settings->sprite,tmp);
    sfRenderWindow_drawSprite(g->w->window,g->settings->sprite, NULL);
    sfRenderWindow_display(WINDOW);
}

void set_view_level3(game_t *g)
{
    VIEW_POS = (sfVector2f){VIEW_SIZE.x / 2 + PLAYER->pos.x - 400,
    VIEW_SIZE.y / 2};
    sfView_setCenter(VIEW, VIEW_POS);
    sfRenderWindow_setView(WINDOW, VIEW);
}

void level3_loop(game_t *g)
{
    sfMusic_stop(LEVEL_2->music);
    set_music(LEVEL_3->music);
    PLAYER->pos = (sfVector2f){400, 800};
    while (sfRenderWindow_isOpen(WINDOW)) {
        event_loop_level3(g);
        get_elapsed_time(g);
        set_view_level3(g);
        update_level_3_all(g);
        draw_objects_level3(g);
    }
}
