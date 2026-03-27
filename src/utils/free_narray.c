/*
** EPITECH PROJECT, 2026
** minishell2
** File description:
** free_narray
*/

#include "mysh.h"

void free_narray(char **array, size_t end)
{
    if (!array)
        return;
    for (size_t i = 0; i < end; ++i)
        free(array[i]);
    free(array);
    return;
}
