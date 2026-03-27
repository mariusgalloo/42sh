/*
** EPITECH PROJECT, 2026
** mysh
** File description:
** my_env
*/

#include <unistd.h>
#include "mysh.h"

void my_env(char **array, shell_t *sh)
{
    if (array[1]) {
        if (access(array[1], F_OK) == 0)
            my_dprintf(2,
                "env: ‘%s’: Permission denied\n", array[1]);
        else
            my_dprintf(2,
                "env: ‘%s’: No such file or directory\n", array[1]);
        return;
    }
    print_list(sh->env);
    return;
}
