/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-isaac.levy-piquet
** File description:
** initialise_main_menu
*/

#include <../include/my_rpg.h>

void set_main_menu(main_menu_t *main_menu, game_t *g)
{
    BG_SIZE[0] = sfTexture_getSize(BG_TEXTURE[0]);
    BG_SIZE[1] = sfTexture_getSize(BG_TEXTURE[1]);
    BG_SIZE[2] = sfTexture_getSize(BG_TEXTURE[2]);
    BG_SCALE[0] = (sfVector2f){(float) g->w->size.x / BG_SIZE[0].x,
    (float) g->w->size.y / BG_SIZE[0].y};
    BG_SCALE[1] = (sfVector2f){(float) g->w->size.x / BG_SIZE[1].x,
    (float) g->w->size.y / BG_SIZE[1].y};
    BG_SCALE[2] = (sfVector2f){4, (float) g->w->size.y / BG_SIZE[2].y};
    BG_POS[0] = (sfVector2f){0, 0};
    BG_POS[1] = (sfVector2f){0, 0};
    BG_POS[2] = (sfVector2f){0, 0};
    BG_POS[3] = (sfVector2f){BG_SIZE[0].x * BG_SCALE[0].x, 0};
    BG_POS[4] = (sfVector2f){BG_SIZE[1].x * BG_SCALE[1].x, 0};
    BG_POS[5] = (sfVector2f){BG_SIZE[2].x * BG_SCALE[2].x, 0};
    BG_SPEED[0] = (sfVector2f){0.2, 0};
    BG_SPEED[1] = (sfVector2f){1, 0};
    BG_SPEED[2] = (sfVector2f){1.6, 0};
}

void set_main_menu2(main_menu_t *main_menu, game_t *g)
{
    sfSprite_setTexture(BG[0], BG_TEXTURE[0], sfTrue);
    sfSprite_setTexture(BG[1], BG_TEXTURE[1], sfTrue);
    sfSprite_setTexture(BG[2], BG_TEXTURE[2], sfTrue);
    sfSprite_setTexture(BG[3], BG_TEXTURE[0], sfTrue);
    sfSprite_setTexture(BG[4], BG_TEXTURE[1], sfTrue);
    sfSprite_setTexture(BG[5], BG_TEXTURE[2], sfTrue);
    sfSprite_setTexture(TITLE, TITLE_TEXTURE, sfTrue);
    sfSprite_setTexture(PRESS_ENTER, PRESS_ENTER_TEXTURE, sfTrue);
    sfSprite_setScale(BG[0], BG_SCALE[0]);
    sfSprite_setScale(BG[1], BG_SCALE[1]);
    sfSprite_setScale(BG[2], BG_SCALE[2]);
    sfSprite_setScale(BG[3], BG_SCALE[0]);
    sfSprite_setScale(BG[4], BG_SCALE[1]);
    sfSprite_setScale(BG[5], BG_SCALE[2]);
}

void set_main_menu3(main_menu_t *main_menu, game_t *g)
{
    TITLE_SIZE = sfTexture_getSize(TITLE_TEXTURE);
    TITLE_POS.x = (float) (g->w->size.x / 2) - TITLE_SIZE.x * 5 / 2;
    PRESS_ENTER_SIZE = sfTexture_getSize(PRESS_ENTER_TEXTURE);
    PRESS_ENTER_POS.x = (float) (g->w->size.x / 2) - PRESS_ENTER_SIZE.x * 4 / 2;
    sfSprite_setScale(TITLE, (sfVector2f){5, 5});
    sfSprite_setScale(PRESS_ENTER, (sfVector2f){4, 4});
    sfSprite_setPosition(TITLE, (sfVector2f){TITLE_POS.x, 200});
    sfSprite_setPosition(PRESS_ENTER, (sfVector2f){PRESS_ENTER_POS.x, 800});
}

void create_main_menu_background(main_menu_t *main_menu)
{
    BG[0] = sfSprite_create();
    BG[1] = sfSprite_create();
    BG[2] = sfSprite_create();
    BG[3] = sfSprite_create();
    BG[4] = sfSprite_create();
    BG[5] = sfSprite_create();
    BG_TEXTURE[0] = sfTexture_createFromFile(BG1_ASSETS, NULL);
    BG_TEXTURE[1] = sfTexture_createFromFile(BG2_ASSETS, NULL);
    BG_TEXTURE[2] = sfTexture_createFromFile(BG3_ASSETS, NULL);
    PRESS_ENTER = sfSprite_create();
    PRESS_ENTER_TEXTURE = sfTexture_createFromFile(ENTER_ASSETS, NULL);
    TITLE = sfSprite_create();
    TITLE_TEXTURE = sfTexture_createFromFile(TITLE_ASSETS, NULL);
}

main_menu_t *create_main_menu(game_t *g)
{
    main_menu_t *main_menu = malloc(sizeof(main_menu_t));

    if (!main_menu)
        return NULL;
    create_main_menu_background(main_menu);
    create_main_menu_objects(main_menu);
    create_main_menu_buttons(main_menu, g);
    set_main_menu(main_menu, g);
    set_main_menu2(main_menu, g);
    set_main_menu3(main_menu, g);
    set_main_menu4(main_menu, g);
    set_main_menu5(main_menu, g);
    MUSIC = sfMusic_createFromFile(MUSIC_MENU);
    return main_menu;
}
