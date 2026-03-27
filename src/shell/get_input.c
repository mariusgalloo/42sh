/*
** EPITECH PROJECT, 2026
** minishell2
** File description:
** get_input
*/

#include <stdio.h>
#include "mysh.h"

int get_input(char **cmd, char ***array)
{
    char const *spe[] = {"<<", ">>", "|", ";", "<", ">", NULL};
    size_t size = 0;

    if (getline(cmd, &size, stdin) == FAIL)
        return FAIL;
    *array = my_str_to_word_array(*cmd, DELIM, spe);
    return SUCCESS;
}
