/*
** EPITECH PROJECT, 2026
** mysh
** File description:
** my_strdup
*/

#include "mysh.h"

char *my_strdup(char const *str)
{
    char *new_str = NULL;
    size_t i = 0;

    if (!str)
        return NULL;
    new_str = malloc(sizeof(char) * (my_strlen(str) + 1));
    if (!new_str)
        return NULL;
    for (; str[i] != '\0'; ++i)
        new_str[i] = str[i];
    new_str[i] = '\0';
    return new_str;
}
