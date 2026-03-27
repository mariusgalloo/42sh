/*
** EPITECH PROJECT, 2026
** minishell2
** File description:
** cmd_check
*/

#include <unistd.h>
#include <stdio.h>
#include "builtin.h"
#include "mysh.h"

bool builtins_func(char **array, shell_t *sh)
{
    for (size_t i = 0; i < BUILTIN_COUNT; ++i) {
        if (my_strcmp(array[0], built[i].cmd) == 0) {
            built[i].ptr(array, sh);
            return true;
        }
    }
    return false;
}

static int check_loop_cmd(char **array, shell_t *sh)
{
    if (builtins_func(array, sh)) {
        if (sh->error)
            return FAIL;
        return SUCCESS;
    } else {
        exec_cmd(array, sh);
        if (sh->error)
            return FAIL;
    }
    return SUCCESS;
}

static int array_occ(char **array, char *occ)
{
    int cmp = 0;
    bool found = false;

    for (size_t i = 0; array[i] != NULL; ++i) {
        cmp = my_strcmp(array[i], occ);
        if (cmp == 0 && (!array[i + 1] || my_strcmp(array[i + 1], "|") == 0)) {
            my_dprintf(2, "Invalid null command.\n");
            return FAIL;
        }
        if (cmp == 0)
            found = true;
    }
    if (found)
        return FOUND;
    return SUCCESS;
}

static size_t len_tab(char ***tab)
{
    size_t i = 0;

    for (; tab[i] != NULL; ++i);
    return i;
}

static int make_pipes(pipe_t *pipe_info, shell_t *sh)
{
    for (size_t i = 0; i < pipe_info->len - 1; ++i) {
        if (pipe(pipe_info->pipes[i]) == FAIL) {
            sh->error = true;
            perror("pipe");
            free(pipe_info->pipes);
            free(pipe_info->pids);
            return FAIL;
        }
    }
    return SUCCESS;
}

static int init_pipe_info(pipe_t *pipe_info, char ***tab, shell_t *sh)
{
    pipe_info->len = len_tab(tab);
    pipe_info->pipes = malloc(sizeof(int[2]) * (pipe_info->len - 1));
    if (!pipe_info->pipes) {
        sh->error = true;
        return FAIL;
    }
    pipe_info->pids = malloc(sizeof(pid_t) * pipe_info->len);
    if (!pipe_info->pids) {
        sh->error = true;
        free(pipe_info->pipes);
        return FAIL;
    }
    if (make_pipes(pipe_info, sh) == FAIL)
        return FAIL;
    pipe_info->tab = tab;
    pipe_info->wstatus = 0;
    return SUCCESS;
}

static void forks_pids(pipe_t *pipe_info, size_t i, shell_t *sh)
{
    pipe_info->pids[i] = fork();
    if (pipe_info->pids[i] < 0) {
        perror("fork");
        return;
    }
    if (pipe_info->pids[i] == 0) {
        if (i > 0)
            dup2(pipe_info->pipes[i - 1][0], STDIN_FILENO);
        if (i < pipe_info->len - 1)
            dup2(pipe_info->pipes[i][1], STDOUT_FILENO);
        for (size_t j = 0; j < pipe_info->len - 1; ++j) {
            close(pipe_info->pipes[j][0]);
            close(pipe_info->pipes[j][1]);
        }
        check_loop_cmd(pipe_info->tab[i], sh);
        exit(sh->exit_status);
    }
    return;
}

static int check_pipe(char ***tab, shell_t *sh)
{
    pipe_t pipe_info;

    if (init_pipe_info(&pipe_info, tab, sh) == FAIL)
        return FAIL;
    for (size_t i = 0; i < pipe_info.len; ++i) {
        forks_pids(&pipe_info, i, sh);
    }
    for (size_t i = 0; i < pipe_info.len - 1; ++i) {
        close(pipe_info.pipes[i][0]);
        close(pipe_info.pipes[i][1]);
    }
    for (size_t i = 0; i < pipe_info.len; ++i) {
        waitpid(pipe_info.pids[i], &pipe_info.wstatus, 0);
        if (WIFEXITED(pipe_info.wstatus)
            && WEXITSTATUS(pipe_info.wstatus) != 0)
            sh->exit_status = ERROR;
    }
    free(pipe_info.pids);
    free(pipe_info.pipes);
    return SUCCESS;
}

static int check_array(char **array, shell_t *sh)
{
    char ***tab = NULL;
    int status = 0;

    status = array_occ(array, "|");
    if (status == FAIL)
        return FOUND;
    if (status == SUCCESS)
        return SUCCESS;
    tab = array_to_array(array, "|");
    if (!tab)
        return FAIL;
    if (check_pipe(tab, sh) == FAIL) {
        free_tab(tab);
        return FOUND;
    }
    free_tab(tab);
    return FOUND;
}

int cmd_check(char **array, shell_t *sh)
{
    char ***tab = array_to_array(array, ";");

    if (!tab)
        return FAIL;
    for (size_t i = 0; tab[i] != NULL; ++i) {
        if (check_array(tab[i], sh) == FOUND)
            continue;
        if (check_loop_cmd(tab[i], sh) == FAIL) {
            free_tab(tab);
            return FAIL;
        }
    }
    free_tab(tab);
    return SUCCESS;
}
