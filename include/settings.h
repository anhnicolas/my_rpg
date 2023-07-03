/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** settings
*/

#ifndef SETTINGS_H_
    #define SETTINGS_H_

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Config.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include <stdlib.h>

typedef struct settings{
    sfSprite *sprite;
    sfSprite *mark;
    sfSprite *inv;
    sfSprite *quest;
    sfTexture *textquest;
    sfTexture *phone1;
    sfTexture *phone2;
    sfTexture *textmark;
    sfTexture *textinv;
    sfFont *font;
    sfText *fullscreen;
    sfText *windowed;
    sfText *attack;
    int state;
} settings_t;

#endif /* !SETTINGS_H_ */
