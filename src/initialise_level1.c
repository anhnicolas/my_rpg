/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-isaac.levy-piquet
** File description:
** initialise_levl1
*/

#include <../include/my_rpg.h>

void set_level1_background(level_1_t *level_1, game_t *g)
{
    for (int i = 0; i < 5; i++)
        LVL1_BG_SIZE[i] = sfTexture_getSize(LVL1_BG_T[i]);
    for (int i = 0; i < 3; i++)
        LVL1_BG_SCALE[i] = (sfVector2f){(float) W_WIDTH / LVL1_BG_SIZE[i].x,
        (float) W_HEIGHT / LVL1_BG_SIZE[i].y};
    LVL1_BG_SCALE[3] = (sfVector2f){4, (float) W_HEIGHT / LVL1_BG_SIZE[3].y};
    LVL1_BG_SCALE[4] = (sfVector2f){4, (float) W_HEIGHT / LVL1_BG_SIZE[4].y};
    for (int i = 0; i < 5; i++) {
        sfSprite_setTexture(LVL1_BG_S[i], LVL1_BG_T[i], sfTrue);
        sfSprite_setScale(LVL1_BG_S[i], LVL1_BG_SCALE[i]);
    }
}

void create_level1_background(level_1_t *level_1, game_t *g)
{
    LVL1_BG_S[0] = sfSprite_create();
    LVL1_BG_S[1] = sfSprite_create();
    LVL1_BG_S[2] = sfSprite_create();
    LVL1_BG_S[3] = sfSprite_create();
    LVL1_BG_S[4] = sfSprite_create();
    LVL1_BG_T[0] = sfTexture_createFromFile(BG1_ASSETS, NULL);
    LVL1_BG_T[1] = sfTexture_createFromFile(BG2_ASSETS, NULL);
    LVL1_BG_T[2] = sfTexture_createFromFile(BG2_ASSETS, NULL);
    LVL1_BG_T[3] = sfTexture_createFromFile(LVL1_BG4_ASSETS, NULL);
    LVL1_BG_T[4] = sfTexture_createFromFile(LVL1_BG4_ASSETS, NULL);
}

void add_enemies_level_1(level_1_t *level_1, game_t *g)
{
    enemy_t *drone_1 = create_enemies(DRONE, (sfVector2f){1500, 850}, 500);
    enemy_t *egg_turret_1 = create_enemies(EGG_TURRET,
                                           (sfVector2f){2100, 470}, 0);
    enemy_t *drone_2 = create_enemies(DRONE, (sfVector2f){2350, 590}, 500);
    enemy_t *egg_turret_2 = create_enemies(EGG_TURRET,
                                           (sfVector2f){3100, 890}, 0);
    enemy_t *drone_3 = create_enemies(DRONE, (sfVector2f){3900, 890}, 500);
    enemy_t *egg_turret_3 = create_enemies(EGG_TURRET,
                                           (sfVector2f){4460, 520}, 0);

    add_enemy_to_list(drone_1, &level_1->enemy);
    add_enemy_to_list(egg_turret_1, &level_1->enemy);
    add_enemy_to_list(drone_2, &level_1->enemy);
    add_enemy_to_list(egg_turret_2, &level_1->enemy);
    add_enemy_to_list(drone_3, &level_1->enemy);
    add_enemy_to_list(egg_turret_3, &level_1->enemy);
}

level_1_t *create_level_1(game_t *g)
{
    level_1_t *level_1 = malloc(sizeof(level_1_t));

    if (!level_1)
        return NULL;
    create_level1_background(level_1, g);
    set_level1_background(level_1, g);
    create_level1_objects(level_1);
    level_1->enemy = NULL;
    add_enemies_level_1(level_1, g);
    level_1->background = create_background("assets/level1/backlvl1.png", g);
    level_1->map = create_map("assets/level1/maplvl1.png", g);
    level_1->music = sfMusic_createFromFile(MUSIC_LVL1);
    return level_1;
}
