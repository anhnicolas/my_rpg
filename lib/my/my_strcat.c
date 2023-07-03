/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-minishell2-nicolas1.nguyen
** File description:
** my_strcat
*/

#include <my_utils.h>

void my_strcat(char *dest, const char *src)
{
    while (*dest != '\0')
        dest++;
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}
