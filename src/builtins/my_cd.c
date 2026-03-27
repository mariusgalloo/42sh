/*
** EPITECH PROJECT, 2026
** mysh
** File description:
** my_cd
*/

#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "mysh.h"

static void push_pwd(char **pwd, shell_t *sh)
{
    push_env("OLDPWD", *pwd, sh);
    free(*pwd);
    *pwd = getcwd(NULL, 0);
    push_env("PWD", *pwd, sh);
    free(*pwd);
    return;
}

static bool check_flags(char const *line, bool *flags, cd_t *cd)
{
    if (my_strcmp(line, "-l") == 0) {
        flags[0] = true;
        cd->flag_l = true;
        return true;
    }
    if (my_strcmp(line, "-p") == 0) {
        flags[1] = true;
        cd->flag_p = true;
        return true;
    }
    return false;
}

static int parse_cmd(char **array, cd_t *cd)
{
    bool flags[2] = {false, false};

    for (size_t i = 1; array[i] != NULL; ++i) {
        if (check_flags(array[i], flags, cd))
            continue;
        if (!cd->path) {
            cd->path = my_strdup(array[i]);
        } else {
            free(cd->path);
            my_dprintf(2, "cd: Too many arguments.\n");
            return FAIL;
        }
    }
    return SUCCESS;
}

static void home_error(char *home, char *pwd, cd_t *cd)
{
    if (!cd->path)
        my_dprintf(2, "cd: Can't change to home directory.\n");
    else {
        my_dprintf(2, "%s/%s", pwd, home);
        my_dprintf(2, ": No such file or directory.\n");
    }
    free(home);
    free(pwd);
    return;
}

static void go_home(cd_t *cd, shell_t *sh)
{
    char *pwd = NULL;
    char *home = my_getenv("HOME", sh);

    if (!home) {
        if (!cd->path)
            my_dprintf(2, "cd: No home directory.\n");
        else
            my_dprintf(2, "No $home variable set.\n");
        return;
    }
    pwd = getcwd(NULL, 0);
    if (chdir(home) == FAIL) {
        home_error(home, pwd, cd);
        return;
    }
    push_pwd(&pwd, sh);
    free(home);
    return;
}

static bool is_home(cd_t *cd, shell_t *sh)
{
    if (!cd->path || my_strcmp(cd->path, "~") == 0) {
        go_home(cd, sh);
        return true;
    }
    return false;
}

static int check_path(cd_t *cd, shell_t *sh)
{
    if (my_strcmp(cd->path, "-") == 0) {
        free(cd->path);
        cd->path = my_getenv("OLDPWD", sh);
        if (!cd->path) {
            my_dprintf(2, ": No such file or directory.\n");
            return FAIL;
        }
    }
    return SUCCESS;
}

static void go_path(cd_t *cd, shell_t *sh)
{
    char *pwd = NULL;

    if (check_path(cd, sh) == FAIL)
        return;
    pwd = getcwd(NULL, 0);
    if (chdir(cd->path) == FAIL) {
        my_dprintf(2, "%s: %s.\n", cd->path, strerror(errno));
        free(pwd);
        return;
    }
    push_pwd(&pwd, sh);
    return;
}

static void make_path(cd_t *cd, shell_t *sh)
{
    if (is_home(cd, sh))
        return;
    else
        go_path(cd, sh);
    return;
}

void my_cd(char **array, shell_t *sh)
{
    cd_t cd;

    init_cd(&cd);
    if (parse_cmd(array, &cd) == FAIL)
        return;
    make_path(&cd, sh);
    if (cd.path)
        free(cd.path);
    return;
}
