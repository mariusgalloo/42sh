/*
** EPITECH PROJECT, 2026
** minishell2
** File description:
** list_to_array
*/

#include <stdlib.h>
#include <string.h>
#include "mysh.h"

size_t get_size_list(list_t *list)
{
    list_t *curr = list;
    size_t i = 0;

    while (curr) {
        ++i;
        curr = curr->next;
    }
    return i;
}

static int fill_env_array(char **array, list_t *curr, size_t *i, shell_t *sh)
{
    char *env_line = NULL;

    env_line = concat_paths(curr->var, curr->val, "=");
    if (!env_line) {
        free_narray(array, *i);
        sh->error = true;
        return FAIL;
    }
    array[*i] = strdup(env_line);
    if (!array[*i]) {
        free_narray(array, *i);
        free(env_line);
        sh->error = true;
        return FAIL;
    }
    free(env_line);
    ++(*i);
    return SUCCESS;
}

char **list_to_array(shell_t *sh)
{
    char **array = NULL;
    list_t *curr = sh->env;
    size_t size = get_size_list(sh->env);
    size_t i = 0;

    array = malloc(sizeof(char *) * (size + 1));
    if (!array) {
        sh->error = true;
        return NULL;
    }
    while (curr) {
        if (fill_env_array(array, curr, &i, sh) == FAIL)
            return NULL;
        curr = curr->next;
    }
    array[i] = NULL;
    return array;
}
