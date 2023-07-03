/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-isaac.levy-piquet
** File description:
** player
*/

#ifndef BACKGROUND_H_
    #define BACKGROUND_H_

typedef struct background_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f scale;
    sfVector2u size;
    sfClock *clock;
    sfTime time;
    float seconds;
} background_t;

typedef struct backelement_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfImage* image;
    sfVector2f pos;
    sfClock *clock;
    sfTime time;
    bool top_collide;
    bool bot_collide;
    bool left_collide;
    bool right_collide;
    float seconds;
} backelement_t;

#endif /* !BACKGROUND_H_ */
