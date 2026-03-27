/*
** EPITECH PROJECT, 2026
** G-PSU-200-PAR-2-1-minishell1-11
** File description:
** free_array
*/

#include "mysh.h"

void free_array(char **array)
{
    if (!array)
        return;
    for (size_t i = 0; array[i] != NULL; ++i)
        free(array[i]);
    free(array);
    return;
}
