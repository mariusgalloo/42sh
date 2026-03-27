/*
** EPITECH PROJECT, 2026
** mysh
** File description:
** my_strcmp
*/

#include "mysh.h"

int my_strcmp(char const *s1, char const *s2)
{
    size_t i = 0;

    if (!s1 || !s2)
        return -1;
    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
        ++i;
    return s1[i] - s2[i];
}
