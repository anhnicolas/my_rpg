/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-isaac.levy-piquet
** File description:
** initialise_level1_objects
*/

#include <../include/my_rpg.h>

void set_level1_objects(level_1_t *level_1)
{
    LVL1_OBJ_SIZE[0] = sfTexture_getSize(LVL1_OBJ_TEXTURE[0]);
    LVL1_OBJ_SIZE[1] = sfTexture_getSize(LVL1_OBJ_TEXTURE[1]);
    LVL1_OBJ_SIZE[2] = sfTexture_getSize(LVL1_OBJ_TEXTURE[2]);
    LVL1_OBJ_SIZE[3] = sfTexture_getSize(LVL1_OBJ_TEXTURE[3]);
    LVL1_OBJ_SCALE[0] = (sfVector2f){4, 4};
    LVL1_OBJ_SCALE[1] = (sfVector2f){4, 4};
    LVL1_OBJ_SCALE[2] = (sfVector2f){4, 4};
    LVL1_OBJ_SCALE[3] = (sfVector2f){4, 4};
    LVL1_OBJ_SPEED[0] = (sfVector2f){-16, 0};
    LVL1_OBJ_SPEED[1] = (sfVector2f){-14, 0};
    LVL1_OBJ_SPEED[2] = (sfVector2f){-20, 0};
    LVL1_OBJ_SPEED[3] = (sfVector2f){-10, 0};
    LVL1_OBJ_POS[0] = (sfVector2f){4000, 700};
    LVL1_OBJ_POS[1] = (sfVector2f){4000, 1000};
    LVL1_OBJ_POS[2] = (sfVector2f){4000, 1300};
    LVL1_OBJ_POS[3] = (sfVector2f){4000, 1500};
}

void set_level1_objects2(level_1_t *level_1)
{
    sfSprite_setTexture(LVL1_OBJ[0], LVL1_OBJ_TEXTURE[0], sfTrue);
    sfSprite_setTexture(LVL1_OBJ[1], LVL1_OBJ_TEXTURE[1], sfTrue);
    sfSprite_setTexture(LVL1_OBJ[2], LVL1_OBJ_TEXTURE[2], sfTrue);
    sfSprite_setTexture(LVL1_OBJ[3], LVL1_OBJ_TEXTURE[3], sfTrue);
    sfSprite_setScale(LVL1_OBJ[0], LVL1_OBJ_SCALE[0]);
    sfSprite_setScale(LVL1_OBJ[1], LVL1_OBJ_SCALE[1]);
    sfSprite_setScale(LVL1_OBJ[2], LVL1_OBJ_SCALE[2]);
    sfSprite_setScale(LVL1_OBJ[3], LVL1_OBJ_SCALE[3]);
    sfSprite_setPosition(LVL1_OBJ[0], LVL1_OBJ_POS[0]);
    sfSprite_setPosition(LVL1_OBJ[1], LVL1_OBJ_POS[1]);
    sfSprite_setPosition(LVL1_OBJ[2], LVL1_OBJ_POS[2]);
    sfSprite_setPosition(LVL1_OBJ[3], LVL1_OBJ_POS[3]);
}

void create_level1_objects(level_1_t *level_1)
{
    LVL1_OBJ[0] = sfSprite_create();
    LVL1_OBJ[1] = sfSprite_create();
    LVL1_OBJ[2] = sfSprite_create();
    LVL1_OBJ[3] = sfSprite_create();
    LVL1_OBJ_TEXTURE[0] = sfTexture_createFromFile(CAR1_ASSETS, NULL);
    LVL1_OBJ_TEXTURE[1] = sfTexture_createFromFile(CAR2_ASSETS, NULL);
    LVL1_OBJ_TEXTURE[2] = sfTexture_createFromFile(CAR3_ASSETS, NULL);
    LVL1_OBJ_TEXTURE[3] = sfTexture_createFromFile(CAR4_ASSETS, NULL);
    set_level1_objects(level_1);
    set_level1_objects2(level_1);
}
