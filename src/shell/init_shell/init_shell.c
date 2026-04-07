/*
** EPITECH PROJECT, 2026
** 42sh
** File description:
** init_shell.c
*/

#include "mysh.h"

static int set_home(shell_t *sh)
{
    size_t len = 0;
    char *home = NULL;;
    const char *user = my_getenv("USER", sh);

    if (!user)
        return FAIL;
    len = strlen(user) + strlen("/home/");
    home = malloc(sizeof(char) * len + 1);
    if (!home)
        return FAIL;
    home = strcpy(home, "/home/");
    if (!home)
        return FAIL;
    home = strcat(home, user);
    if (!home)
        return FAIL;
    if (push_env(HOME, home, sh) == FAIL)
        return FAIL;
    return SUCCESS;
}

int init_env(shell_t *sh)
{
    char *hostname = get_hostname();

    if (!hostname)
        return FAIL;
    if (push_env(NLSPATH, NLS_PATH, sh) == FAIL)
        return FAIL;
    if (push_env(PATH, CMD_PATH, sh) == FAIL)
        return FAIL;
    if (push_env(HOST, hostname, sh) == FAIL)
        return FAIL;
    if (!my_getenv(USER, sh)) {
        if (push_env(USER, get_user(), sh) == FAIL)
            return FAIL;
    }
    if (!my_getenv(PWD, sh)) {
        if (push_env(PWD, getcwd(NULL, 0), sh) == FAIL)
            return FAIL;
    }
    if (!my_getenv(HOME, sh)) {
        if (set_home(sh) == FAIL)
            return FAIL;
    }
    return SUCCESS;
}
