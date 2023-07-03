/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-isaac.levy-piquet
** File description:
** main_menu
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <SFML/Window.h>

#ifndef MAIN_MENU_H_
    #define MAIN_MENU_H_
    #define BG main_menu->bg
    #define BG_TEXTURE main_menu->bg_texture
    #define BG_POS main_menu->bg_pos
    #define BG_SCALE main_menu->bg_scale
    #define BG_SIZE main_menu->bg_size
    #define BG_SPEED main_menu->bg_speed
    #define PRESS_ENTER main_menu->press_enter_button
    #define PRESS_ENTER_TEXTURE main_menu->press_enter_texture
    #define PRESS_ENTER_POS main_menu->press_enter_pos
    #define PRESS_ENTER_SCALE main_menu->press_enter_scale
    #define PRESS_ENTER_SIZE main_menu->press_enter_size
    #define TITLE main_menu->title
    #define TITLE_TEXTURE main_menu->title_texture
    #define TITLE_POS main_menu->title_pos
    #define TITLE_SCALE main_menu->title_scale
    #define TITLE_SIZE main_menu->title_size
    #define BUTTON main_menu->text
    #define BUTTON_FONT main_menu->font
    #define BUTTON_COLOR main_menu->text_color
    #define BUTTON_RECT main_menu->text_rect
    #define OBJ main_menu->vehicles
    #define OBJ_TEXTURE main_menu->vehicles_texture
    #define OBJ_POS main_menu->vehicles_pos
    #define OBJ_SCALE main_menu->vehicles_scale
    #define OBJ_SIZE main_menu->vehicles_size
    #define OBJ_SPEED main_menu->vehicles_speed
    #define MUSIC main_menu->music
    #define BG1_ASSETS "assets/main_menu/bg-1.png"
    #define BG2_ASSETS "assets/main_menu/bg-2.png"
    #define BG3_ASSETS "assets/main_menu/bg-3.png"
    #define ENTER_ASSETS "assets/main_menu/enter.png"
    #define TITLE_ASSETS "assets/main_menu/title.png"
    #define CAR1_ASSETS "assets/main_menu/vehicles/v-police.png"
    #define CAR2_ASSETS "assets/main_menu/vehicles/v-red.png"
    #define CAR3_ASSETS "assets/main_menu/vehicles/v-yellow.png"
    #define CAR4_ASSETS "assets/main_menu/vehicles/v-truck.png"
    #define BUTTON_FONT_PATH "assets/main_menu/Paskowy.ttf"

typedef struct main_menu_s {
    sfSprite *bg[6];
    sfTexture *bg_texture[3];
    sfVector2f bg_pos[6];
    sfVector2f bg_scale[3];
    sfVector2u bg_size[3];
    sfVector2f bg_speed[3];
    sfText *text[3];
    sfFont *font;
    sfColor text_color[3];
    sfVector2f text_pos[3];
    sfVector2f text_scale[3];
    sfVector2u text_size[3];
    sfFloatRect text_rect[3];
    sfSprite *vehicles[4];
    sfTexture *vehicles_texture[4];
    sfVector2f vehicles_pos[4];
    sfVector2f vehicles_scale[4];
    sfVector2u vehicles_size[4];
    sfVector2f vehicles_speed[4];
    sfSprite *press_enter_button;
    sfTexture *press_enter_texture;
    sfVector2f press_enter_pos;
    sfVector2f *press_enter_scale;
    sfVector2u press_enter_size;
    sfSprite *title;
    sfTexture *title_texture;
    sfVector2f title_pos;
    sfVector2f *title_scale;
    sfVector2u title_size;
    sfMusic *music;
} main_menu_t;

#endif /* !MAIN_MENU_H_ */
