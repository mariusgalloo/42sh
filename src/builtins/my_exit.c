/*
** EPITECH PROJECT, 2026
** mysh
** File description:
** my_exit
*/

#include <stdio.h>
#include "mysh.h"

void my_exit(char **array, shell_t *sh)
{
    if (array[1] && array[2]) {
        (void)fprintf(stderr, "exit: Expression Syntax.\n");
        return;
    }
    if (array[1] && !is_nbr(array[1])) {
        (void)fprintf(stderr, "exit: Expression Syntax.\n");
        return;
    }
    sh->exit = true;
    if (array[1] && is_nbr(array[1]))
        sh->exit_status = my_getnbr(array[1]);
    return;
}
