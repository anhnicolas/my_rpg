/*
** EPITECH PROJECT, 2022
** B-CPE-100-LIL-1-1-cpoolday08-nicolas1.nguyen
** File description:
** my_str_to_word_array
*/

#include <my_utils.h>

int is_alphanumeric(char car)
{
    if ((car >= '0' && car <= '9') || (car >= 'a' && car <= 'z') ||
        (car >= 'A' && car <= 'Z') || car == '.')
        return 0;
    else
        return 1;
}

int count_cols(char const *str, int i, char separator)
{
    int count = 0;

    while (str[i] != separator) {
        count++;
        i++;
    }
    return count;
}

int count_lines(char const *str, char separator)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == separator)
            count++;
    }
    return count;
}

char **my_str_to_word_tab(char const *str, char separator)
{
    int i = 0;
    int j = 0;
    int a = 0;
    int cols = 0;
    int lines = count_lines(str, separator);
    char **tab = malloc(sizeof(char *) * (lines + 1));

    for (; a < lines; a++, i++) {
        cols = count_cols(str, i, separator);
        tab[a] = malloc(sizeof(char) * cols + 1);
        for (; str[i] != '\0' && str[i] != separator; i++, j++) {
            tab[a][j] = str[i];
        }
        tab[a][j] = '\0';
        j = 0;
        cols = 0;
    }
    tab[lines] = NULL;
    return tab;
}
