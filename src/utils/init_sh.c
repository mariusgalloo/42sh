/*
** EPITECH PROJECT, 2026
** minishell2
** File description:
** init_sh
*/

#include "mysh.h"

void init_sh(shell_t *sh)
{
    sh->env = NULL;
    sh->error = false;
    sh->exit = false;
    sh->exit_status = 0;
    return;
}
