/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-isaac.levy-piquet
** File description:
** initialise_main_menu2
*/

#include <../include/my_rpg.h>

void set_main_menu4(main_menu_t *main_menu, game_t *g)
{
    OBJ_SIZE[0] = sfTexture_getSize(OBJ_TEXTURE[0]);
    OBJ_SIZE[1] = sfTexture_getSize(OBJ_TEXTURE[1]);
    OBJ_SIZE[2] = sfTexture_getSize(OBJ_TEXTURE[2]);
    OBJ_SIZE[3] = sfTexture_getSize(OBJ_TEXTURE[3]);
    OBJ_SCALE[0] = (sfVector2f){2, 2};
    OBJ_SCALE[1] = (sfVector2f){2, 2};
    OBJ_SCALE[2] = (sfVector2f){2, 2};
    OBJ_SCALE[3] = (sfVector2f){2, 2};
    OBJ_SPEED[0] = (sfVector2f){-4, 0};
    OBJ_SPEED[1] = (sfVector2f){-3.5, 0};
    OBJ_SPEED[2] = (sfVector2f){-5, 0};
    OBJ_SPEED[3] = (sfVector2f){-2.5, 0};
    OBJ_POS[0].x = OBJ_SIZE[0].x * OBJ_SCALE[0].x - 1500;
    OBJ_POS[1].x = OBJ_SIZE[1].x * OBJ_SCALE[1].x - 1500;
    OBJ_POS[2].x = OBJ_SIZE[2].x * OBJ_SCALE[2].x - 1500;
    OBJ_POS[3].x = OBJ_SIZE[3].x * OBJ_SCALE[3].x - 1500;
}

void set_main_menu5(main_menu_t *main_menu, game_t *g)
{
    sfSprite_setTexture(OBJ[0], OBJ_TEXTURE[0], sfTrue);
    sfSprite_setTexture(OBJ[1], OBJ_TEXTURE[1], sfTrue);
    sfSprite_setTexture(OBJ[2], OBJ_TEXTURE[2], sfTrue);
    sfSprite_setTexture(OBJ[3], OBJ_TEXTURE[3], sfTrue);
    sfSprite_setScale(OBJ[0], OBJ_SCALE[0]);
    sfSprite_setScale(OBJ[1], OBJ_SCALE[1]);
    sfSprite_setScale(OBJ[2], OBJ_SCALE[2]);
    sfSprite_setScale(OBJ[3], OBJ_SCALE[3]);
    sfSprite_setPosition(OBJ[0], OBJ_POS[0]);
    sfSprite_setPosition(OBJ[1], OBJ_POS[1]);
    sfSprite_setPosition(OBJ[2], OBJ_POS[2]);
    sfSprite_setPosition(OBJ[3], OBJ_POS[3]);
}

void create_main_menu_objects(main_menu_t *main_menu)
{
    OBJ[0] = sfSprite_create();
    OBJ[1] = sfSprite_create();
    OBJ[2] = sfSprite_create();
    OBJ[3] = sfSprite_create();
    OBJ_TEXTURE[0] = sfTexture_createFromFile(CAR1_ASSETS, NULL);
    OBJ_TEXTURE[1] = sfTexture_createFromFile(CAR2_ASSETS, NULL);
    OBJ_TEXTURE[2] = sfTexture_createFromFile(CAR3_ASSETS, NULL);
    OBJ_TEXTURE[3] = sfTexture_createFromFile(CAR4_ASSETS, NULL);
}
