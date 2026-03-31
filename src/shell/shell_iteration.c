/*
** EPITECH PROJECT, 2026
** minishell2
** File description:
** shell_iteration
*/

#include "mysh.h"

int shell_iteration(shell_t *sh)
{
    char *cmd = NULL;
    char **array = NULL;

    if (get_input(&cmd, &array) == FAIL) {
        sh->exit = true;
        free(cmd);
        return SUCCESS;
    }
    free(cmd);
    if (!array)
        return SUCCESS;
    if (cmd_check(array, sh) == FAIL) {
        free_array(array);
        return FAIL;
    }
    free_array(array);
    return SUCCESS;
}
