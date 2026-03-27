/*
** EPITECH PROJECT, 2026
** mysh
** File description:
** my_unsetenv
*/

#include "mysh.h"

static void free_node(list_t *node)
{
    free(node->var);
    free(node->val);
    free(node);
    return;
}

static void delete_node(list_t *prev, list_t *curr, shell_t *sh)
{
    if (!prev) {
        sh->env = sh->env->next;
        free_node(curr);
    } else {
        prev->next = curr->next;
        free_node(curr);
    }
    return;
}

static void unset_env(char const *var, shell_t *sh)
{
    list_t *curr = sh->env;
    list_t *prev = NULL;

    while (curr && my_strcmp(var, curr->var) != 0) {
        prev = curr;
        curr = curr->next;
    }
    if (curr) {
        delete_node(prev, curr, sh);
        return;
    }
    return;
}

void my_unsetenv(char **array, shell_t *sh)
{
    if (!array[1]) {
        my_dprintf(2, "unsetenv: Too few arguments.\n");
        return;
    }
    for (size_t i = 1; array[i] != NULL; ++i)
        unset_env(array[i], sh);
    return;
}
