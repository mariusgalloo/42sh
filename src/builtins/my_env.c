/*
** EPITECH PROJECT, 2026
** mysh
** File description:
** my_env
*/

#include <unistd.h>
#include <stdio.h>
#include "mysh.h"

void my_env(char **array, shell_t *sh)
{
    if (array[1]) {
        if (access(array[1], F_OK) == 0)
            (void)fprintf(stderr,
                "env: ‘%s’: Permission denied\n", array[1]);
        else
            (void)fprintf(stderr,
                "env: ‘%s’: No such file or directory\n", array[1]);
        return;
    }
    print_list(sh->env);
    return;
}
