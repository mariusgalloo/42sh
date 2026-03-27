/*
** EPITECH PROJECT, 2026
** G-PSU-200-PAR-2-1-minishell2-11
** File description:
** free_tab
*/

#include "mysh.h"

void free_tab(char ***tab)
{
    if (!tab)
        return;
    for (size_t i = 0; tab[i] != NULL; ++i) {
        free(tab[i]);
    }
    free(tab);
    return;
}
