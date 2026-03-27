/*
** EPITECH PROJECT, 2026
** minishell2
** File description:
** cmd_check
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "builtin.h"
#include "mysh.h"

bool builtins_func(char **array, shell_t *sh)
{
    for (size_t i = 0; i < BUILTIN_COUNT; ++i) {
        if (strcmp(array[0], built[i].cmd) == 0) {
            built[i].ptr(array, sh);
            return true;
        }
    }
    return false;
}

static int check_loop_cmd(char **array, shell_t *sh)
{
    if (builtins_func(array, sh)) {
        if (sh->error)
            return FAIL;
        return SUCCESS;
    } else {
        exec_cmd(array, sh);
        if (sh->error)
            return FAIL;
    }
    return SUCCESS;
}

int cmd_check(char **array, shell_t *sh)
{
    check_loop_cmd(array, sh);
    return SUCCESS;
}
