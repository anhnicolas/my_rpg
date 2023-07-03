/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-minishell2-nicolas1.nguyen
** File description:
** my_strcmp
*/

#include <my_utils.h>

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i])
            return (1);
        i++;
    }
    if (s1[i] != s2[i])
        return (1);
    return (0);
}
