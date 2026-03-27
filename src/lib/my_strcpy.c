/*
** EPITECH PROJECT, 2025
** my_strcpy
** File description:
** str copy
*/

#include "mysh.h"

char *my_strcpy(char *dest, char const *src)
{
    size_t i = 0;

    if (!src)
        return NULL;
    for (; src[i] != '\0'; ++i) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}
