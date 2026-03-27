/*
** EPITECH PROJECT, 2026
** minishell2
** File description:
** free_sh
*/

#include "mysh.h"

void free_list(list_t *list)
{
    list_t *curr = list;
    list_t *next = NULL;

    while (curr) {
        next = curr->next;
        free(curr->var);
        free(curr->val);
        free(curr);
        curr = next;
    }
    return;
}

void free_sh(shell_t *sh)
{
    free_list(sh->env);
    free(sh);
    return;
}
