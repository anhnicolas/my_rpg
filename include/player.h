/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-isaac.levy-piquet
** File description:
** player
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <SFML/Window.h>

#ifndef PLAYER_H_
    #define PLAYER_H_
    #define PROJECTILE player->projectile
    #define PROJECTILE_SPEED player->projectileSpeed
    #define PROJECTILE_POS player->projectilePos
    #define PROJECTILE_TEXTURE player->projectileTexture
    #define PROJECTILE_SOUND player->projectileSound
    #define PROJECTILE_CLOCK player->projectileClock
    #define PROJECTILE_TIME player->projectileTime
    #define PROJECTILE_FRAME player->projectileFrame
    #define SHOOT_ASSET1 "assets/player/cyber_player/shot/shot-1.png"
    #define SHOOT_ASSET2 "assets/player/cyber_player/shot/shot-2.png"
    #define SHOOT_ASSET3 "assets/player/cyber_player/shot/shot-3.png"

typedef struct player_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfRectangleShape *rect;
    sfIntRect texture_rect;
    sfIntRect crect;
    sfVector2f pos;
    sfVector2f scale;
    sfVector2u size;
    sfClock *clock;
    sfClock *gclock;
    sfTime time;
    sfVector2f velocity;
    sfSprite *projectile;
    sfTexture *projectileTexture[3];
    sfVector2f projectilePos;
    sfMusic *projectileSound;
    sfClock *projectileClock;
    sfTime projectileTime;
    int projectileFrame;
    bool canShoot;
    float projectileSpeed;
    int *nb_frame;
    int anim_speed;
    int frame_data;
    int gravity;
    float isaac;
    float jumpSpeed;
    bool isJumping;
    bool island;
    float maxFallSpeed;
    float seconds;
    int move;
    int direction;
    int life;
    int life_max;
    int attack;
    int attack2;
    int xp;
    int level;
    int hp_max;
} player_t;

#endif /* !PLAYER_H_ */
