/*
** EPITECH PROJECT, 2025
** my_strcat
** File description:
** concat str
*/

#include "mysh.h"

char *my_strcat(char *dest, char const *src)
{
    size_t i = 0;
    size_t len = 0;

    if (!src)
        return NULL;
    len = my_strlen(dest);
    for (; src[i] != '\0'; i++) {
        dest[len + i] = src[i];
    }
    dest[len + i] = '\0';
    return dest;
}
