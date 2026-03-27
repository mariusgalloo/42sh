/*
** EPITECH PROJECT, 2026
** minishell2
** File description:
** concat_paths
*/

#include "mysh.h"

char *concat_paths(const char *s1, const char *s2, const char *c)
{
    char *str = NULL;
    size_t len = 0;

    if (!s1 || !s2 || !c)
        return NULL;
    len = my_strlen(s1) + my_strlen(c) + my_strlen(s2) + 1;
    str = malloc(len);
    if (!str)
        return NULL;
    my_strcpy(str, s1);
    my_strcat(str, c);
    my_strcat(str, s2);
    return str;
}
