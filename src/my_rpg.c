/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-isaac.levy-piquet
** File description:
** my_rpg
*/

#include <../include/my_rpg.h>

void game(void)
{
    game_t *g = create_game();

    main_menu(g);
    destroy_all(g);
}

int main(int ac, char **av, char **env)
{
    if (env[0] == NULL)
        return 84;
    else if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        write(1,
        "my_rpg game : \n"
        , 16);
    } else {
        game();
    }
    return 0;
}
