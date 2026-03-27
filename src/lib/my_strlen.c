/*
** EPITECH PROJECT, 2026
** mysh
** File description:
** my_strlen
*/

#include "mysh.h"

size_t my_strlen(char const *str)
{
    size_t i = 0;

    if (!str)
        return 0;
    for (; str[i] != '\0'; ++i);
    return i;
}
