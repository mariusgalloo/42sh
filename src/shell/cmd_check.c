/*
** EPITECH PROJECT, 2026
** minishell2
** File description:
** cmd_check
*/

#include "mysh.h"

int cmd_check(char **array, shell_t *sh)
{
    llparser(array, sh);
    return SUCCESS;
}
