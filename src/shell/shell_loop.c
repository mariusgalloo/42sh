/*
** EPITECH PROJECT, 2026
** minishell2
** File description:
** shell_loop
*/

#include <unistd.h>
#include "mysh.h"
#include <stdio.h>
#include <string.h>

static int fill_value(list_t *curr, int exit_status)
{
    char tmp[12];

    if (strcmp(curr->var, "?") == MATCH) {
        if (curr->val)
            free(curr->val);
        sprintf(tmp, "%d", exit_status);
        curr->val = strdup(tmp);
        if (!curr->val) {
            return FAIL;
        }
    }
    return SUCCESS;
}

static int fill_status(shell_t *sh)
{
    list_t *curr = sh->env;

    while (curr) {
        if (fill_value(curr, sh->exit_status) == FAIL)
            return FAIL;
        curr = curr->next;
    }
    return SUCCESS;
}

int shell_loop(shell_t *sh)
{
    if (isatty(0) && write(1, "$> ", 3) == FAIL)
        return FAIL;
    while (true) {
        if (sh->exit)
            return SUCCESS;
        if (shell_iteration(sh) == FAIL)
            return FAIL;
        if (fill_status(sh) == FAIL)
            return FAIL;
        if (isatty(0) && !sh->exit && write(1, "$> ", 3) == FAIL)
            return FAIL;
    }
    return SUCCESS;
}
