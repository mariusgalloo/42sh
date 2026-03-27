/*
** EPITECH PROJECT, 2026
** minishell2
** File description:
** mysh
*/

#include "mysh.h"

int mysh(char **env)
{
    shell_t *sh = malloc(sizeof(shell_t));
    int status = 0;

    if (!sh)
        return EXIT_FAIL;
    init_sh(sh);
    if (fill_env(env, sh) == FAIL
        || shell_loop(sh) == FAIL) {
        free(sh);
        return EXIT_FAIL;
    }
    status = sh->exit_status;
    free_sh(sh);
    return status;
}
