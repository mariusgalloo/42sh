/*
** EPITECH PROJECT, 2026
** minishell2
** File description:
** is_nbr
*/

#include "mysh.h"

bool is_nbr(char const *str)
{
    for (size_t i = 0; str[i] != '\0'; ++i) {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return false;
    }
    return true;
}
