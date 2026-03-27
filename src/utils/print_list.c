/*
** EPITECH PROJECT, 2026
** minishell2
** File description:
** print_list
*/

#include <stdio.h>
#include "mysh.h"

void print_list(list_t *env)
{
    list_t *curr = env;

    while (curr) {
        (void)fprintf(stdout, "%s=%s\n", curr->var, curr->val);
        curr = curr->next;
    }
    return;
}
