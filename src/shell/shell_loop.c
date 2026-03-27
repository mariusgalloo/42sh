/*
** EPITECH PROJECT, 2026
** minishell2
** File description:
** shell_loop
*/

#include <unistd.h>
#include "mysh.h"

int shell_loop(shell_t *sh)
{
    if (isatty(0) && write(1, "$> ", 3) == FAIL)
        return FAIL;
    while (true) {
        if (sh->exit)
            return SUCCESS;
        if (shell_iteration(sh) == FAIL)
            return FAIL;
        if (isatty(0) && !sh->exit && write(1, "$> ", 3) == FAIL)
            return FAIL;
    }
    return SUCCESS;
}
