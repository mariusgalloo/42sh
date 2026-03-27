/*
** EPITECH PROJECT, 2026
** minishell2
** File description:
** fill_end
*/

#include "mysh.h"

static int envtok(char const *str, char **var, char **val, char const delim)
{
    size_t i = 0;

    for (; str[i] != '\0'; ++i) {
        if (str[i] == delim)
            break;
    }
    *var = my_strndup(str, i);
    if (!*var)
        return FAIL;
    *val = my_strdup(str + (i + 1));
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
    if (push_env(NLSPATH, NLS_PATH, sh) == FAIL)
        return FAIL;
    return SUCCESS;
}
