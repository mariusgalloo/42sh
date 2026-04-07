/*
** EPITECH PROJECT, 2026
** minishell2
** File description:
** fill_end
*/

#include <string.h>
#include <stdlib.h>
#include "mysh.h"

static int envtok(char const *str, char **var, char **val, char const delim)
{
    size_t i = 0;

    for (; str[i] != '\0'; ++i) {
        if (str[i] == delim)
            break;
    }
    *var = strndup(str, i);
    if (!*var)
        return FAIL;
    *val = strdup(str + (i + 1));
    if (!*val) {
        free(*var);
        return FAIL;
    }
    return SUCCESS;
}

int fill_env(char **env, shell_t *sh)
{
    char *var = NULL;
    char *val = NULL;

    for (size_t i = 0; env[i] != NULL; ++i) {
        if (envtok(env[i], &var, &val, '=') == FAIL) {
            sh->error = true;
            return FAIL;
        }
        if (push_back(var, val, sh) == FAIL) {
            free(var);
            free(val);
            return FAIL;
        }
        free(var);
        free(val);
    }
    if (init_env(sh) == FAIL)
        return FAIL;
    if (push_env("?", "", sh) == FAIL)
        return FAIL;
    return SUCCESS;
}
