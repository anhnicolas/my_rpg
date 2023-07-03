/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-isaac.levy-piquet
** File description:
** enemies
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <SFML/Window.h>

#ifndef ENEMIES_H_
    #define ENEMIES_H_
    #define DRONE_ASSET "assets/level1/enemy1/drone/drone.png"
    #define EGG_TURRET_ASSET "assets/level1/enemy2/egg_turret/egg_turret.png"
    #define COP_IDLE_ASSET "assets/level3/enemy1/cop/idle/cop_idle.png"
    #define COP_RUN_ASSET "assets/level3/enemy1/cop/run/cop_run.png"
    #define BOSS_HEAD "assets/level4/Boss/boss_head.png"
    #define BOSS_TORSO "assets/level4/Boss/boss_torso.png"
    #define BOSS_BACK_ARM "assets/level4/Boss/arm_front.png"
    #define BOSS_FRONT_ARM "assets/level4/Boss/arm_front.png"

typedef enum enemy_type_e {
    DRONE, EGG_TURRET, COP
} enemy_type_t;

typedef struct enemy_s {
    enemy_type_t type;
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect texture_rect;
    sfVector2f pos;
    sfRectangleShape *rect;
    sfVector2f scale;
    sfVector2u size;
    sfVector2u image_count;
    sfVector2u current_image;
    int life;
    int attack;
    int velocity;
    int offset;
    int offset_max;
    int direction;
    float switch_time;
    float total_time;
    int img_size[2];
    struct enemy_s *next;
} enemy_t;

typedef struct boss_torso_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect texture_rect;
    sfVector2f pos;
    sfRectangleShape *rect;
    sfVector2f scale;
    sfVector2u size;
    sfVector2u image_count;
    sfVector2u current_image;
    int velocity;
    int direction;
    int img_size[2];
} boss_torso_t;

typedef struct boss_head_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect texture_rect;
    sfVector2f scale;
    sfVector2u size;
    sfVector2f pos;
    sfRectangleShape *rect;
    sfVector2u image_count;
    sfVector2u current_image;
    int velocity;
    int direction;
    int img_size[2];
} boss_head_t;

typedef struct boss_back_arm_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect texture_rect;
    sfVector2f scale;
    sfVector2u size;
    sfVector2f pos;
    int velocity;
    int direction;
    int img_size[2];
} boss_back_arm_t;

typedef struct boss_front_arm_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect texture_rect;
    sfVector2f scale;
    sfVector2u size;
    sfVector2f pos;
    int velocity;
    int direction;
    int img_size[2];
} boss_front_arm_t;

typedef struct boss_s {
    boss_head_t *head;
    boss_torso_t *torso;
    boss_back_arm_t *back_arm;
    boss_front_arm_t *fron_arm;
} boss_t;

#endif //ENNEMIES_H_
