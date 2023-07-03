/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-isaac.levy-piquet
** File description:
** items
*/
#include "my_rpg.h"

items_t *inititems2(items_t *item)
{
    item->posheal1 = (sfVector2f){1813.F, 550.F};
    item->posheal2 = (sfVector2f){2813.F, 450.F};
    item->posheal3 = (sfVector2f){4263.F, 320.F};
    item->posheal4 = (sfVector2f){3560.F, 750.F};
    item->posheal5 = (sfVector2f){2000.F, 700.F};
    item->posheal6 = (sfVector2f){1200.F, 500.F};
    sfSprite_setPosition(item->heal1, item->posheal1);
    sfSprite_setPosition(item->heal2, item->posheal2);
    sfSprite_setPosition(item->heal3, item->posheal3);
    sfSprite_setPosition(item->heal4, item->posheal4);
    sfSprite_setPosition(item->heal5, item->posheal5);
    sfSprite_setPosition(item->heal6, item->posheal6);
    item->boolheal1 = true;
    item->boolheal2 = true;
    item->boolheal3 = true;
    item->boolheal4 = true;
    item->boolheal5 = true;
    item->boolheal6 = true;
}

items_t *inititems(void)
{
    items_t *item = malloc(sizeof(items_t));
    item->heal1 = sfSprite_create();
    item->heal2 = sfSprite_create();
    item->heal3 = sfSprite_create();
    item->heal4 = sfSprite_create();
    item->heal5 = sfSprite_create();
    item->heal6 = sfSprite_create();
    item->potion = sfTexture_createFromFile("assets/set/heal.png", NULL);
    sfSprite_setTexture(item->heal1, item->potion, sfTrue);
    sfSprite_setTexture(item->heal2, item->potion, sfTrue);
    sfSprite_setTexture(item->heal3, item->potion, sfTrue);
    sfSprite_setTexture(item->heal4, item->potion, sfTrue);
    sfSprite_setTexture(item->heal5, item->potion, sfTrue);
    sfSprite_setTexture(item->heal6, item->potion, sfTrue);
    item->nb_potion = 0;
    inititems2(item);
    return item;
}

void draw_items1(game_t *g)
{
    if (g->items->boolheal1 == true)
        sfRenderWindow_drawSprite(WINDOW, g->items->heal1, NULL);
    if (g->items->boolheal2 == true)
        sfRenderWindow_drawSprite(WINDOW, g->items->heal2, NULL);
    if (g->items->boolheal3 == true)
        sfRenderWindow_drawSprite(WINDOW, g->items->heal3, NULL);
}

void check_item_coli1(game_t *g)
{
    sfFloatRect rect1 = sfSprite_getGlobalBounds(g->items->heal1);
    sfFloatRect rect2 = sfSprite_getGlobalBounds(g->player->sprite);
    if (g->items->boolheal1 == true)
        if (sfFloatRect_intersects(&rect1, &rect2, NULL) == sfTrue){
            g->items->nb_potion += 1;
            g->items->boolheal1 = false;
        }
    rect1 = sfSprite_getGlobalBounds(g->items->heal2);
    if (g->items->boolheal2 == true)
        if (sfFloatRect_intersects(&rect1, &rect2, NULL) == sfTrue){
            g->items->nb_potion += 1;
            g->items->boolheal2 = false;
        }
    rect1 = sfSprite_getGlobalBounds(g->items->heal3);
    if (g->items->boolheal3 == true)
        if (sfFloatRect_intersects(&rect1, &rect2, NULL) == sfTrue){
                g->items->nb_potion += 1;
                g->items->boolheal3 = false;
        }
}

void check_item_coli2(game_t *g)
{
    sfFloatRect rect1 = sfSprite_getGlobalBounds(g->items->heal4);
    sfFloatRect rect2 = sfSprite_getGlobalBounds(g->player->sprite);
    if (g->items->boolheal4 == true)
        if (sfFloatRect_intersects(&rect1, &rect2, NULL) == sfTrue){
            g->items->nb_potion += 1;
            g->items->boolheal4 = false;
        }
    rect1 = sfSprite_getGlobalBounds(g->items->heal5);
    if (g->items->boolheal5 == true)
        if (sfFloatRect_intersects(&rect1, &rect2, NULL) == sfTrue){
            g->items->nb_potion += 1;
            g->items->boolheal5 = false;
        }
    rect1 = sfSprite_getGlobalBounds(g->items->heal6);
    if (g->items->boolheal6 == true)
        if (sfFloatRect_intersects(&rect1, &rect2, NULL) == sfTrue){
                g->items->nb_potion += 1;
                g->items->boolheal6 = false;
        }
}
