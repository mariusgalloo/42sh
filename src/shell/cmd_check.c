/*
** EPITECH PROJECT, 2026
** minishell2
** File description:
** cmd_check
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "builtin.h"
#include "mysh.h"

type_t check_type(char const *input, char const *ope[])
{
    type_t type = CMD;

    for (size_t idx = 0; ope[idx] != NULL; ++idx) {
        if (strcmp(input, ope[idx]) == MATCH)
            return (type_t)idx;
    }
    return type;
}

node_t *create_node(node_t *left, node_t *right, char **array, type_t type)
{
    node_t *new_node = calloc(1, sizeof(node_t));

    if (!new_node)
        return NULL;
    new_node->left = left;
    new_node->right = right;
    new_node->cmd = array;
    new_node->type = type;
    return new_node;
}

char **arraytok(char **array, size_t start, size_t end)
{
    char **sub = NULL;
    size_t size = end - start;

    if (size == 0)
        return NULL;
    sub = calloc(size + 1, sizeof(char *));
    if (!sub)
        return NULL;
    for (size_t idx = 0; start < end; ++idx) {
        sub[idx] = strdup(array[start]);
        if (!sub[idx])
            return NULL;
        ++start;
    }
    sub[size] = NULL;
    return sub;
}

node_t *parse_cmd(char **array, char const *ope[], size_t *idx)
{
    size_t start = *idx;
    char **sub = NULL;

    while (array[*idx] && check_type(array[*idx], ope) == CMD)
        ++(*idx);
    sub = arraytok(array, start, *idx);
    if (!sub)
        return NULL;
    return create_node(NULL, NULL, sub, CMD);
}

node_t *parse_pipe(char **array, char const *ope[], size_t *idx)
{
    node_t *left = parse_cmd(array, ope, idx);
    node_t *right = NULL;

    if (!left)
        return NULL;
    if (array[*idx] && check_type(array[*idx], ope) == PIPE) {
        ++(*idx);
        right = parse_pipe(array, ope, idx);
        if (!right)
            return NULL;
        return create_node(left, right, NULL, PIPE);
    }
    return left;
}

node_t *parse_semi(char **array, char const *ope[], size_t *idx)
{
    node_t *left = parse_pipe(array, ope, idx);
    node_t *right = NULL;

    if (!left)
        return NULL;
    if (array[*idx] && check_type(array[*idx], ope) == SEMI) {
        ++(*idx);
        right = parse_semi(array, ope, idx);
        if (!right)
            return create_node(left, NULL, NULL, SEMI);
        return create_node(left, right, NULL, SEMI);
    }
    return left;
}

static void print_node(node_t *node)
{
    if (!node)
        return;
    if (node->type == SEMI)
        printf("semi:\n");
    if (node->type == PIPE)
        printf("PIPE:\n");
    if (node->type == CMD) {
        printf("CMD:\n");
        for (size_t i = 0; node->cmd[i] != NULL; i++)
            printf("%s ", node->cmd[i]);
        printf("\n");
    }
    if (node->left) {
        printf("Left:\n");
        print_node(node->left);
    }
    if (node->right) {
        printf("Right:\n");
        print_node(node->right);
    }
    return;
}

int cmd_check(char **array, shell_t *sh)
{
    char const *ope[] = {";", "|", NULL};
    size_t idx = 0;
    node_t *node = parse_semi(array, ope, &idx);

    print_node(node);
    return SUCCESS;
}
