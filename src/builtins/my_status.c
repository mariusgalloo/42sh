/*
** EPITECH PROJECT, 2026
** 42sh
** File description:
** my_echo
*/

#include <string.h>
#include <stdio.h>
#include "mysh.h"

void my_status(UNUSED char **array, shell_t *sh)
{
    list_t *curr= sh->env;

    while (curr) {
        if (strcmp(curr->var, "?") == MATCH)
            (void)printf("%s\n", curr->val);
        curr = curr->next;
    }
    return;
}
