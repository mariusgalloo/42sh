/*
** EPITECH PROJECT, 2026
** minishell2
** File description:
** concat_paths
*/

#include <string.h>
#include "mysh.h"

char *concat_paths(const char *s1, const char *s2, const char *c)
{
    char *str = NULL;
    size_t len = 0;

    if (!s1 || !s2 || !c)
        return NULL;
    len = strlen(s1) + strlen(c) + strlen(s2) + 1;
    str = malloc(len);
    if (!str)
        return NULL;
    strcpy(str, s1);
    strcat(str, c);
    strcat(str, s2);
    return str;
}
