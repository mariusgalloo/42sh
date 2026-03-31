/*
** EPITECH PROJECT, 2026
** minishell2
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    #include <sys/wait.h>

typedef struct list_s {
    char *var;
    char *val;
    struct list_s *next;
} list_t;

typedef struct shell_s {
    list_t *env;
    bool error;
    bool exit;
    int exit_status;
} shell_t;

typedef struct cd_s {
    char *path;
    bool flag_l;
    bool flag_p;
} cd_t;

typedef struct cmd_s {
    char *cmd;
    char **array;
    char **env;
    pid_t pid;
    int wstatus;
} cmd_t;

typedef struct memory_s {
    char *response;
    size_t size;
} memory_t;

typedef struct redir_s {
    char *target;
    struct redir_s *next;
    redir_type_t type;
} redir_t;

typedef struct node_s {
    struct node_s *left;
    struct node_s *right;
    char **cmd;
    type_t type;
    redir_t *redirs;
} node_t;

#endif
