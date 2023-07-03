/*
** EPITECH PROJECT, 2023
** GROUPE ENNEMIES
** File description:
** create and manage ennemies groupe
*/

#include "../include/my_rpg.h"

void add_enemy_to_list(enemy_t *enemy, enemy_t **list)
{
    if (*list == NULL) {
        *list = enemy;
        enemy->next = NULL;
        return;
    }
    enemy_t *current_enemy = *list;
    while (current_enemy->next != NULL) {
        current_enemy = current_enemy->next;
    }
    current_enemy->next = enemy;
    enemy->next = NULL;
}

void display_enemies(enemy_t *list, game_t *g)
{
    enemy_t *current;

    current = list;
    while (current != NULL) {
        if (current->life > 0)
            sfRenderWindow_drawSprite(WINDOW, current->sprite, NULL);
        current = current->next;
    }
}

void update_genemy(enemy_t *list, game_t *g)
{
    enemy_t *current;

    current = list;
    while (current != NULL) {
        update_enemy(current, 0, g->deltatime);
        current = current->next;
    }
}

void free_enemy_list(enemy_t *list)
{
    enemy_t *current = list;
    while (current != NULL) {
        enemy_t *next = current->next;
        sfSprite_destroy(current->sprite);
        sfTexture_destroy(current->texture);
        sfRectangleShape_destroy(current->rect);
        free(current);
        current = next;
    }
}
