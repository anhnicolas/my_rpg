/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-isaac.levy-piquet
** File description:
** initialise
*/

#include <../include/my_rpg.h>

window_t *create_window(void)
{
    window_t *window = malloc(sizeof(window_t));

    if (!window)
        return NULL;
    window->mode = (sfVideoMode){1920, 1080, 32};
    window->title = "my_rpg";
    window->style = sfResize | sfClose;
    window->window = sfRenderWindow_create(window->mode, window->title,
                                                    window->style, NULL);
    window->size = sfRenderWindow_getSize(window->window);
    return window;
}

window_t *create_window_fullscreen(void)
{
    window_t *window = malloc(sizeof(window_t));

    if (!window)
        return NULL;
    window->mode = (sfVideoMode){1920, 1080, 32};
    window->title = "my_rpg";
    window->style = sfFullscreen | sfClose;
    window->window = sfRenderWindow_create(window->mode, window->title,
                                                    window->style, NULL);
    window->size = sfRenderWindow_getSize(window->window);
    return window;
}

game_t *create_game(void)
{
    game_t *game = malloc(sizeof(game_t));

    if (!game)
        return NULL;
    game->w = create_window();
    game->items = inititems();
    game->settings = initsettings();
    game->main_menu = create_main_menu(game);
    game->player = create_player(game);
    game->level_1 = create_level_1(game);
    game->level_2 = create_level_2(game);
    game->level_3 = create_level_3(game);
    game->level_4 = create_level_4(game);
    game->clock = sfClock_create();
    game->view = sfView_create();
    game->view_size = (sfVector2f){1920, 1080};
    game->fadeRect = sfRectangleShape_create();
    sfRectangleShape_setSize(game->fadeRect, (sfVector2f){8000, 2000});
    sfRectangleShape_setPosition(game->fadeRect, (sfVector2f){-1000, 0});
    return game;
}

game_t *create_game_fullscreen(void)
{
    game_t *game = malloc(sizeof(game_t));

    if (!game)
        return NULL;
    game->w = create_window_fullscreen();
    game->items = inititems();
    game->settings = initsettings();
    game->main_menu = create_main_menu(game);
    game->player = create_player(game);
    game->level_1 = create_level_1(game);
    game->level_2 = create_level_2(game);
    game->level_3 = create_level_3(game);
    game->level_4 = create_level_4(game);
    game->clock = sfClock_create();
    game->view = sfView_create();
    game->view_size = (sfVector2f){1920, 1080};
    game->fadeRect = sfRectangleShape_create();
    sfRectangleShape_setSize(game->fadeRect, (sfVector2f){8000, 2000});
    sfRectangleShape_setPosition(game->fadeRect, (sfVector2f){-1000, 0});
    return game;
}
