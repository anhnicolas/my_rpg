/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-isaac.levy-piquet
** File description:
** initialise_main_menu_buttons
*/

#include <../include/my_rpg.h>

void create_main_menu_buttons(main_menu_t *main_menu, game_t *g)
{
    BUTTON_FONT = sfFont_createFromFile(BUTTON_FONT_PATH);
    for (int i = 0; i < 3; i++) {
        BUTTON[i] = sfText_create();
        sfText_setFont(BUTTON[i], BUTTON_FONT);
        sfText_setCharacterSize(BUTTON[i], 100);
        sfText_setColor(BUTTON[i], sfYellow);
        sfText_setOutlineColor(BUTTON[i], sfBlack);
        sfText_setOutlineThickness(BUTTON[i], 3);
    }
    sfText_setString(BUTTON[0], "PLAY");
    sfText_setString(BUTTON[1], "SETTINGS");
    sfText_setString(BUTTON[2], "QUIT");
    sfText_setPosition(BUTTON[0], (sfVector2f){W_WIDTH / 2 - 100, 400});
    sfText_setPosition(BUTTON[1], (sfVector2f){W_WIDTH / 2 - 100, 600});
    sfText_setPosition(BUTTON[2], (sfVector2f){W_WIDTH / 2 - 100, 800});
}
