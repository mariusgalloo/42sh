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

node_t *create_node(node_t *left, node_t *right, char **cmd, type_t type)
{
    node_t *new_node = calloc(1, sizeof(node_t));

    if (!new_node)
        return NULL;
    new_node->left = left;
    new_node->right = right;
    new_node->cmd = cmd;
    new_node->type = type;
    return new_node;
}

node_t *parse_cmd(char const *cmd, size_t *idx)
{
    type_t type = CMD;

    for (; cmd[*idx] != '\0'; ++idx) {
        type = check_type();
        if (type != CMD)
            break;
    }
    return create_node(NULL, NULL, my_str_to_word_array(cmd + *idx, DELIM, spe), type);
}

node_t *parse_semi(node_t *node)
{
    node_t *left = parse_pipe();
    node_t *right = NULL;

    ;
}

static bool parse_separator()
{
    for (size_t i = 0; OPERATORS[i] != '\0'; ++i) {
        if (OPERATORS[i] == *cmd)
            return true;
    }; OPERATORS[i] != '\0'; ++i) {
        if (OPERATORS[i] == *cmd)
            return true;
    }
    return false;
}

int cmd_check(char *cmd, shell_t *sh)
{
    node_t node;

    while (*cmd != '\0') {
        if (parse_separator() == FAIL)
            return FAIL;
    }
    parse_semi(&node);
    return SUCCESS;
}
