/*
** EPITECH PROJECT, 2023
** COLLISION .h
** File description:
** .h FOR CLODDISOIN
*/

#ifndef COLLISION_H_


typedef struct enemies_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfRectangleShape *rect;
    sfIntRect texture_rect;
    sfVector2f pos;
    sfClock *clock;
    sfTime time;
    int *nb_frame;
    int anim_speed;
    int frame_data;
    float seconds;
    int move;
    int direction;
    int life;
    int velocity;
    int attack;
    int attack2;
} enemies_t;

    #define COLLISION_H_


#endif /* !COLLISION_H_ */
