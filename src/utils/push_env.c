/*
** EPITECH PROJECT, 2026
** minishell2
** File description:
** push_env
*/

#include <stdlib.h>
#include <string.h>
#include "mysh.h"

int push_env(const char *var, const char *val, shell_t *sh)
{
    list_t *curr = sh->env;

    while (curr && strcmp(var, curr->var) != 0)
        curr = curr->next;
    if (!curr)
        return push_back(var, val, sh);
    free(curr->val);
    curr->val = strdup(val);
    if (!curr->val) {
        sh->error = true;
        return FAIL;
    }
    return SUCCESS;
}
