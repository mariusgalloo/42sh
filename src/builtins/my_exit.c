/*
** EPITECH PROJECT, 2026
** mysh
** File description:
** my_exit
*/

#include "mysh.h"

void my_exit(char **array, shell_t *sh)
{
    if (array[1] && array[2]) {
        my_dprintf(2, "exit: Expression Syntax.\n");
        return;
    }
    if (array[1] && !is_nbr(array[1])) {
        my_dprintf(2, "exit: Expression Syntax.\n");
        return;
    }
    sh->exit = true;
    if (array[1] && is_nbr(array[1]))
        sh->exit_status = my_getnbr(array[1]);
    return;
}
