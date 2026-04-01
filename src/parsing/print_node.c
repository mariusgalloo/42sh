/*
** EPITECH PROJECT, 2026
** 42sh
** File description:
** print_node
*/

#include "mysh.h"

static void print_type(node_t *node)
{
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
}

void print_node(node_t *node)
{
    if (!node)
        return;
    print_type(node);
    if (node->left) {
        printf("Left:\n");
        print_node(node->left);
    }
    if (node->right) {
        printf("Right:\n");
        print_node(node->right);
    }
}
