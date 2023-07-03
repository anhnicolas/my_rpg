/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-isaac.levy-piquet
** File description:
** items
*/

#ifndef ITEMS_H_
    #define ITEMS_H_
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Config.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include <stdlib.h>

typedef struct items{
    sfSprite *heal1;
    sfSprite *heal2;
    sfSprite *heal3;
    sfSprite *heal4;
    sfSprite *heal5;
    sfSprite *heal6;
    sfVector2f posheal1;
    sfVector2f posheal2;
    sfVector2f posheal3;
    sfVector2f posheal4;
    sfVector2f posheal5;
    sfVector2f posheal6;
    bool boolheal1;
    bool boolheal2;
    bool boolheal3;
    bool boolheal4;
    bool boolheal5;
    bool boolheal6;
    sfTexture *potion;
    int nb_potion;
} items_t;

#endif /* !ITEMS_H_ */
