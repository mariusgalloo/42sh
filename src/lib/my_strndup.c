/*
** EPITECH PROJECT, 2026
** mysh
** File description:
** my_strndup
*/

#include "mysh.h"

char *my_strndup(char const *src, size_t size)
{
    char *str = NULL;
    size_t i = 0;

    if (!src)
        return NULL;
    str = malloc(sizeof(char) * (size + 1));
    if (!str)
        return NULL;
    for (; src[i] != '\0' && i < size; ++i)
        str[i] = src[i];
    str[i] = '\0';
    return str;
}
