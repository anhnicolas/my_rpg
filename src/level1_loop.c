/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-isaac.levy-piquet
** File description:
** main_loop
*/

#include <../include/my_rpg.h>

void event_loop_level1(game_t *g)
{
    while (sfRenderWindow_pollEvent(WINDOW, &g->event)) {
        if (g->event.type == sfEvtClosed)
            sfRenderWindow_close(WINDOW);
        if (EVENT.type == sfEvtKeyPressed && EVENT.key.code == sfKeyEnter) {
            fade_in(g);
            PLAYER->isJumping = false;
            PLAYER->pos.y = 825;
            PLAYER->velocity.y = 0;
            PLAYER->island = true;
            level2_loop(g);
        }
        if (g->event.type == sfEvtKeyPressed)
            use_heal(g);
    }
}

void draw_objects_level1(game_t *g)
{
    sfVector2f tmp = VIEW_POS;

    tmp.x += 850;
    tmp.y = 200;
    sfRenderWindow_clear(WINDOW, sfBlack);
    for (int i = 0; i < 5; i++)
        sfRenderWindow_drawSprite(WINDOW, LEVEL_1->bg[i], NULL);
    for (int i = 0; i < 4; i++)
        sfRenderWindow_drawSprite(WINDOW, LEVEL_1->vehicles[i], NULL);
    sfRenderWindow_drawSprite(WINDOW, g->level_1->background->sprite, NULL);
    display_enemies(LEVEL_1->enemy, g);
    sfRenderWindow_drawRectangleShape(WINDOW, PLAYER->rect, NULL);
    sfRenderWindow_drawSprite(WINDOW, PLAYER->sprite, NULL);
    sfRenderWindow_drawSprite(WINDOW, PLAYER->projectile, NULL);
    sfSprite_setPosition(g->settings->sprite,tmp);
    draw_items1(g);
    sfRenderWindow_drawSprite(WINDOW, g->settings->sprite, NULL);
    sfRenderWindow_display(WINDOW);
}

void get_elapsed_time(game_t *g)
{
    g->elapsedtime = sfClock_getElapsedTime(g->clock);
    sfClock_restart(g->clock);
    g->deltatime = sfTime_asSeconds(g->elapsedtime);
}

void set_view(game_t *g)
{
    VIEW_POS = (sfVector2f){VIEW_SIZE.x / 2 + PLAYER->pos.x - 600,
    VIEW_SIZE.y / 2 + 200};
    sfView_setCenter(g->view, VIEW_POS);
    sfView_setSize(g->view, g->view_size);
    sfRenderWindow_setView(WINDOW, g->view);
}

void level1_loop(game_t *g)
{
    sfMusic_stop(MAIN_MENU->music);
    set_music(LEVEL_1->music);
    PLAYER->pos = (sfVector2f){250, 900};
    sfClock_restart(PLAYER->gclock);
    while (sfRenderWindow_isOpen(WINDOW)) {
        event_loop_level1(g);
        get_elapsed_time(g);
        set_view(g);
        update_level_1_all(g);
        draw_objects_level1(g);
    }
}
