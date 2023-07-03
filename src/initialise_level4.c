/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-isaac.levy-piquet
** File description:
** initialise_level4
*/

#include <../include/my_rpg.h>

void set_level4_background(level_4_t *level_4, game_t *g)
{
    LVL4_BG_SIZE[0] = sfTexture_getSize(LVL4_THUNDER_T[0]);
    LVL4_BG_SIZE[1] = sfTexture_getSize(LVL4_BG_T[0]);
    LVL4_BG_SCALE[0] = (sfVector2f){(float) W_WIDTH / LVL4_BG_SIZE[0].x,
    (float) W_HEIGHT / LVL4_BG_SIZE[0].y};
    LVL4_BG_SCALE[1] = (sfVector2f){(float) W_WIDTH / LVL4_BG_SIZE[1].x,
    (float) W_HEIGHT / LVL4_BG_SIZE[1].y};
    sfSprite_setTexture(LVL4_THUNDER, LVL4_THUNDER_T[0], sfTrue);
    sfSprite_setScale(LVL4_THUNDER, LVL4_BG_SCALE[0]);
    sfSprite_setTexture(LVL4_BG_S[0], LVL4_BG_T[0], sfTrue);
    sfSprite_setScale(LVL4_BG_S[0], LVL4_BG_SCALE[1]);
    sfSprite_setTexture(LVL4_BG_S[1], LVL4_BG_T[1], sfTrue);
    sfSprite_setScale(LVL4_BG_S[1], LVL4_BG_SCALE[1]);
}

void create_level4_background(level_4_t *level_4, game_t *g)
{
    LVL4_THUNDER = sfSprite_create();
    LVL4_BG_S[0] = sfSprite_create();
    LVL4_BG_S[1] = sfSprite_create();
    LVL4_THUNDER_T[0] = sfTexture_createFromFile(LVL4_THUNDER_ASSETS1, NULL);
    LVL4_THUNDER_T[1] = sfTexture_createFromFile(LVL4_THUNDER_ASSETS2, NULL);
    LVL4_THUNDER_T[2] = sfTexture_createFromFile(LVL4_THUNDER_ASSETS3, NULL);
    LVL4_THUNDER_T[3] = sfTexture_createFromFile(LVL4_THUNDER_ASSETS4, NULL);
    LVL4_THUNDER_T[4] = sfTexture_createFromFile(LVL4_THUNDER_ASSETS5, NULL);
    LVL4_THUNDER_T[5] = sfTexture_createFromFile(LVL4_THUNDER_ASSETS6, NULL);
    LVL4_BG_T[0] = sfTexture_createFromFile(LVL4_BG_ASSETS, NULL);
    LVL4_BG_T[1] = sfTexture_createFromFile(LVL4_BG_ASSETS, NULL);

}

void create_map_level4(level_4_t *level_4, game_t *g)
{
    level_4->map = sfSprite_create();
    level_4->map_t = sfTexture_createFromFile(LVL4_MAP_ASSETS, NULL);
    level_4->map_size = sfTexture_getSize(level_4->map_t);
    sfSprite_setTexture(level_4->map, level_4->map_t, sfTrue);
    sfSprite_setScale(level_4->map, (sfVector2f){2, 2});
}

void add_boss(level_4_t *level_4, game_t *g)
{
    boss_t *boss = malloc(sizeof(boss_t));

    boss->torso = create_boss_torso();
    boss->head = create_boss_head();
    boss->fron_arm = create_boss_front_arm();
    boss->back_arm = create_boss_back_arm();
    level_4->boss = boss;
}

level_4_t *create_level_4(game_t *g)
{
    level_4_t *level_4 = malloc(sizeof(level_4_t));

    if (!level_4)
        return NULL;
    create_level4_background(level_4, g);
    set_level4_background(level_4, g);
    create_map_level4(level_4, g);
    add_boss(level_4, g);
    level_4->clock = sfClock_create();
    level_4->currentFrame = 0;
    level_4->music = sfMusic_createFromFile(MUSIC_BOSS);
    level_4->mapa = create_map("assets/level4/collvl4.png", g);
    return level_4;
}
