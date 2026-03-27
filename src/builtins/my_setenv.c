/*
** EPITECH PROJECT, 2026
** mysh
** File description:
** my_setenv
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mysh.h"

size_t size_array(char **array)
{
    size_t i = 0;

    for (; array[i] != NULL; ++i);
    return i;
}

int check_nb_of_args(char **array, shell_t *sh)
{
    size_t size = size_array(array);

    if (size > 3) {
        (void)fprintf(stderr, "setenv: Too many arguments.\n");
        return FAIL;
    }
    if (size == 1) {
        print_list(sh->env);
        return FAIL;
    }
    return SUCCESS;
}

bool my_strisalpha(char const *str)
{
    for (size_t i = 0; str[i] != '\0'; ++i) {
        if (!(str[i] >= 'A' && str[i] <= 'Z')
            && !(str[i] >= 'a' && str[i] <= 'z')
            && !(str[i] >= '0' && str[i] <= '9')
            && str[i] != '_')
            return false;
    }
    return true;
}

int check_policy(char **array)
{
    if (!(array[1][0] >= 'A' && array[1][0] <= 'Z')
        && !(array[1][0] >= 'a' && array[1][0] <= 'z')) {
        (void)fprintf(stderr,
            "setenv: Variable name must begin with a letter.\n");
    }
    if (my_strisalpha(array[1]) == false) {
        (void)fprintf(stderr,
            "setenv: Variable name must contain alphanumeric characters.\n");
        return FAIL;
    }
    return SUCCESS;
}

static void replace_env(char **array, char *val, shell_t *sh)
{
    list_t *curr = sh->env;

    while (curr && strcmp(array[1], curr->var) != 0)
        curr = curr->next;
    if (curr) {
        free(curr->val);
        curr->val = val;
    } else {
        if (push_back(array[1], val, sh) == FAIL)
            sh->error = true;
        free(val);
    }
    return;
}

void my_setenv(char **array, shell_t *sh)
{
    char *val = NULL;

    if (check_nb_of_args(array, sh) == FAIL
        || check_policy(array) == FAIL)
        return;
    if (array[2])
        val = strdup(array[2]);
    else
        val = strdup("");
    if (!val) {
        sh->error = true;
        return;
    }
    replace_env(array, val, sh);
    return;
}
