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

typedef struct pipe_s {
    size_t len;
    pid_t *pids;
    int (*pipes)[2];
    char ***tab;
    int wstatus;
} pipe_t;

#endif
