/*
** EPITECH PROJECT, 2026
** 42sh
** File description:
** check_redirection
*/

#include <string.h>
#include "mysh.h"

static redir_type_t check_redir_type(char const *input, char const *redir[])
{
    redir_type_t type = NONE;

    for (size_t idx = 0; redir[idx] != NULL; ++idx) {
        if (strcmp(input, redir[idx]) == MATCH)
            return (redir_type_t)idx;
    }
    return type;
}

static int alloc_redir(node_t *node, size_t idx, redir_type_t type)
{
    if (idx == 0 || !node->cmd[idx + 1])
        return FAIL;
    node->redirs = calloc(1, sizeof(redir_t));
    if (!node->redirs)
        return FAIL;
    node->redirs->type = type;
    return SUCCESS;
}

static int check_redir_occ(node_t *node)
{
    char const *redir[] = {"<<", "<", ">>", ">", NULL};
    redir_type_t type;
    size_t idx = 0;

    while (node->cmd[idx] != NULL) {
        type = check_redir_type(node->cmd[idx], redir);
        if (type == NONE) {
            ++idx;
            continue;
        }
        if (alloc_redir(node, idx, type) == FAIL)
            return FAIL;
        ++idx;
    }
    return SUCCESS;
}

void check_redirection(node_t *node)
{
    if (!node)
        return;
    if (node->type == CMD)
        if (check_redir_occ(node) == FAIL)
            return;
    if (node->left)
        check_redirection(node->left);
    if (node->right)
        check_redirection(node->right);
}
