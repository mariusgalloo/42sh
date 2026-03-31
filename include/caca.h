#ifndef AST_H
#define AST_H

#include <stdlib.h>

/*
** =========================
** ENUMS
** =========================
*/

typedef enum e_node_type {
    NODE_COMMAND,
    NODE_PIPE,
    NODE_AND,
    NODE_OR,
    NODE_SEQUENCE,
    NODE_SUBSHELL
} node_type_t;

typedef enum e_redir_type {
    REDIR_IN,        // <
    REDIR_OUT,       // >
    REDIR_APPEND,    // >>
    REDIR_HEREDOC    // <<
} redir_type_t;

/*
** =========================
** REDIRECTIONS
** =========================
*/

typedef struct s_redir {
    redir_type_t type;
    char *filename;
    int fd;                  // 0 stdin, 1 stdout, 2 stderr
    struct s_redir *next;
} redir_t;

/*
** =========================
** WORD (optionnel mais recommandé)
** =========================
*/

typedef struct s_word {
    char *value;
    int quoted;              // 1 si entre quotes
    struct s_word *next;
} word_t;

/*
** =========================
** COMMAND
** =========================
*/

typedef struct s_cmd {
char **argv;             // NULL-terminated
redir_t *redirs;         // liste de redirections
} cmd_t;

/*
** =========================
** AST NODE
** =========================
*/

typedef struct s_node {
node_type_t type;


struct s_node *left;
struct s_node *right;

union {
    cmd_t *cmd;          // utilisé si NODE_COMMAND
};


} node_t;

/*
** =========================
** HELPERS (optionnels)
** =========================
*/

#endif
