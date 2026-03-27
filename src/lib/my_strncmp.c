/*
** EPITECH PROJECT, 2026
** G-PSU-200-PAR-2-1-minishell2-11
** File description:
** my_strncmp
*/

#include "mysh.h"

int my_strncmp(char const *s1, char const *s2, size_t n)
{
    size_t i = 0;

    if (!s1 || !s2)
        return FAIL;
    while (i < n && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
        i++;
    if (i == n)
        return SUCCESS;
    return s1[i] - s2[i];
}
