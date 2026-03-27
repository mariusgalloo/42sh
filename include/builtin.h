/*
** EPITECH PROJECT, 2026
** minishell2
** File description:
** builtins
*/

#ifndef BUILTIN_H_
    #define BUILTIN_H_

    #include "mysh.h"

    #define BUILTIN_COUNT sizeof(built) / sizeof(built[0])

typedef struct builtins_s {
    char *cmd;
    void (*ptr)(char **array, shell_t *sh);
} builtins_t;

static const builtins_t built[] = {
    {"exit", &my_exit},
    {"env", &my_env},
    {"setenv", &my_setenv},
    {"unsetenv", &my_unsetenv},
    {"cd", &my_cd}
};

#endif
