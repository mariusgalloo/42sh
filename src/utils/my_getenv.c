/*
** EPITECH PROJECT, 2026
** minishell2
** File description:
** my_getenv
*/

#include "mysh.h"

char *my_getenv(char const *var, shell_t *sh)
{
    char *val = NULL;
    list_t *curr = sh->env;

    while (curr && my_strcmp(var, curr->var) != 0)
        curr = curr->next;
    if (curr) {
        val = my_strdup(curr->val);
        if (!val) {
            sh->error = true;
            return NULL;
        }
    }
    return val;
}
