/*
** EPITECH PROJECT, 2026
** minishell2
** File description:
** push_back
*/

#include <string.h>
#include <unistd.h>
#include "mysh.h"

static list_t *init_node(char const *var, char const *val)
{
    list_t *new_node = malloc(sizeof(list_t));

    if (!new_node)
        return NULL;
    new_node->var = strdup(var);
    if (!new_node->var) {
        free(new_node);
        return NULL;
    }
    new_node->val = strdup(val);
    if (!new_node->val) {
        free(new_node->var);
        free(new_node);
        return NULL;
    }
    new_node->next = NULL;
    return new_node;
}

int push_back(char const *var, char const *val, shell_t *sh)
{
    list_t *prev = NULL;
    list_t *curr = sh->env;
    list_t *new_node = init_node(var, val);

    if (!new_node) {
        sh->error = true;
        return FAIL;
    }
    while (curr) {
        prev = curr;
        curr = curr->next;
    }
    if (!prev)
        sh->env = new_node;
    else
        prev->next = new_node;
    return SUCCESS;
}
