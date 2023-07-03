/*
** EPITECH PROJECT, 2023
** INIT BACKGRUND
** File description:
** create dtruct for back
*/
#include <../include/my_rpg.h>

background_t *create_background(char *path, game_t *g)
{
    background_t *background = malloc(sizeof(background_t));

    if (!background)
        return NULL;
    background->pos = (sfVector2f){0, 0};
    background->sprite = sfSprite_create();
    background->texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(background->sprite, background->texture, sfFalse);
    sfSprite_setPosition(background->sprite, background->pos);
    background->size = sfTexture_getSize(background->texture);
    background->scale = (sfVector2f){2, 2};
    sfSprite_setScale(background->sprite, background->scale);
    sfVector2u window_size = sfRenderWindow_getSize(g->w->window);
    return background;
}

backelement_t *create_map(char *path, game_t *g)
{
    backelement_t *background = malloc(sizeof(backelement_t));

    if (!background)
        return NULL;
    background->texture = sfTexture_createFromFile(path, NULL);
    background->image = sfTexture_copyToImage(background->texture);
    return background;
}
