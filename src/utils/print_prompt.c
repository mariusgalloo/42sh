/*
** EPITECH PROJECT, 2026
** 42sh
** File description:
** print_prompt.c
*/

#include "mysh.h"

int print_prompt(shell_t *sh)
{
    char *pwd = my_getenv(PWD, sh);
    char *user = NULL;
    char *host = NULL;
    size_t len = 0;

    if (!pwd)
        return FAIL;
    user = my_getenv(USER, sh);
    if (!user)
        return FAIL;
    len = strlen(user) + strlen(PATH_HOME);
    host = my_getenv(HOST, sh);
    if (!host)
        return FAIL;
    (void)printf("%s:~%s> ", host, pwd + len);
    return SUCCESS;
}
