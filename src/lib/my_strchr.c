/*
** EPITECH PROJECT, 2026
** G-PSU-200-PAR-2-1-minishell1-11
** File description:
** my_strchr
*/

#include "mysh.h"

char *my_strchr(char *str, char c)
{
    size_t i = 0;

    if (!str)
        return NULL;
    for (; str[i] != '\0'; ++i) {
        if (str[i] == c)
            return str + i;
    }
    if (c == '\0')
        return str + i;
    return NULL;
}
