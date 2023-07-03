/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-isaac.levy-piquet
** File description:
** level4_loop
*/

#include <../include/my_rpg.h>

void event_loop_level4(game_t *g)
{
    while (sfRenderWindow_pollEvent(WINDOW, &g->event)) {
        if (g->event.type == sfEvtClosed)
            sfRenderWindow_close(WINDOW);
        if (g->event.type == sfEvtKeyPressed)
            use_heal(g);
    }
}

void draw_objects_level4(game_t *g)
{
    sfVector2f tmp = VIEW_POS;

    tmp.x += 850;
    tmp.y = 0;
    sfRenderWindow_clear(WINDOW, sfBlack);
    sfRenderWindow_drawSprite(WINDOW, LEVEL_4->thunder, NULL);
    sfRenderWindow_drawSprite(WINDOW, LEVEL_4->bg[0], NULL);
    sfRenderWindow_drawSprite(WINDOW, LEVEL_4->bg[1], NULL);
    sfRenderWindow_drawSprite(WINDOW, LEVEL_4->map, NULL);
    sfRenderWindow_drawRectangleShape(WINDOW, PLAYER->rect, NULL);
    sfRenderWindow_drawSprite(WINDOW, PLAYER->sprite, NULL);
    sfRenderWindow_drawSprite(WINDOW, PLAYER->projectile, NULL);
    sfRenderWindow_drawSprite(WINDOW, LEVEL_4->boss->torso->sprite, NULL);
    sfRenderWindow_drawSprite(WINDOW, LEVEL_4->boss->head->sprite, NULL);
    sfRenderWindow_drawSprite(WINDOW, LEVEL_4->boss->back_arm->sprite, NULL);
    sfRenderWindow_drawSprite(WINDOW, LEVEL_4->boss->fron_arm->sprite, NULL);
    sfSprite_setPosition(g->settings->sprite,tmp);
    sfRenderWindow_drawSprite(g->w->window,g->settings->sprite, NULL);
    sfRenderWindow_display(WINDOW);
}

void set_view_level4(game_t *g)
{
    VIEW_POS = (sfVector2f){VIEW_SIZE.x / 2 + PLAYER->pos.x - 400,
    VIEW_SIZE.y / 2};
    sfView_setCenter(VIEW, VIEW_POS);
    sfRenderWindow_setView(WINDOW, VIEW);
}

void level4_loop(game_t *g)
{
    sfMusic_stop(LEVEL_3->music);
    set_music(LEVEL_4->music);
    PLAYER->pos = (sfVector2f){70, 800};
    PLAYER->island = true;
    PLAYER->isJumping = false;
    while (sfRenderWindow_isOpen(WINDOW)) {
        event_loop_level4(g);
        get_elapsed_time(g);
        set_view_level4(g);
        update_level_4_all(g);
        draw_objects_level4(g);
    }
}
