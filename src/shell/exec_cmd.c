/*
** EPITECH PROJECT, 2026
** minishell2
** File description:
** exec_cmd
*/

#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "mysh.h"

static void free_exec(cmd_t *exec)
{
    free_array(exec->env);
    free(exec->cmd);
    return;
}

static char **paths_from_env(shell_t *sh, bool *val_null)
{
    char **array = NULL;
    list_t *curr = sh->env;

    while (curr && strcmp(curr->var, "PATH") != 0)
        curr = curr->next;
    if (!curr)
        return NULL;
    array = my_str_to_word_array(curr->val, ":", NULL);
    if (!array) {
        *val_null = true;
        return NULL;
    }
    return array;
}

char *search_cmd(char const *input, char **paths)
{
    char *cmd = NULL;

    for (size_t i = 0; paths[i] != NULL; ++i) {
        cmd = concat_paths(paths[i], input, "/");
        if (!cmd)
            return NULL;
        if (access(cmd, X_OK) == 0)
            return cmd;
        free(cmd);
    }
    return NULL;
}

static char *search_path_list(char const *input, shell_t *sh,
    char *stc_paths[])
{
    bool val_null = false;
    char **paths = paths_from_env(sh, &val_null);
    char *cmd = NULL;

    if (paths) {
        cmd = search_cmd(input, paths);
        free_array(paths);
    } else {
        if (val_null)
            return NULL;
        cmd = search_cmd(input, stc_paths);
    }
    return cmd;
}

static char *check_access_cmd(char *cmd, shell_t *sh)
{
    if (access(cmd, F_OK) != 0) {
        (void)fprintf(stderr, "%s: Command not found.\n", cmd);
        sh->exit_status = ERROR;
        return NULL;
    }
    if (access(cmd, X_OK) != 0) {
        (void)fprintf(stderr, "%s: Permission denied.\n", cmd);
        sh->exit_status = ERROR;
        return NULL;
    }
    return cmd;
}

static char *get_path(char const *input, shell_t *sh)
{
    char *cmd = NULL;
    char *stc_paths[] = {
        "/usr/local/sbin", "/usr/local/bin",
        "/usr/sbin", "/usr/bin", "/sbin", "/bin", "/snap/bin", NULL};

    if (strchr((char *)input, '/')) {
        cmd = strdup(input);
        if (!cmd) {
            sh->error = true;
            return NULL;
        }
        return check_access_cmd(cmd, sh);
    }
    cmd = search_path_list(input, sh, stc_paths);
    if (!cmd) {
        (void)fprintf(stderr, "%s: Command not found.\n", input);
        sh->exit_status = 1;
        return NULL;
    }
    return cmd;
}

static void execute_cmd(cmd_t *exec)
{
    if (execve(exec->cmd, exec->array, exec->env) == FAIL) {
        (void)fprintf(stderr, "%s: %s", exec->array[0], strerror(errno));
        if (errno == ENOEXEC)
            (void)fprintf(stderr, ". Binary file not executable");
        (void)fprintf(stderr, ".\n");
        free_exec(exec);
        exit(ERROR);
    }
    return;
}

static void check_child(cmd_t *exec)
{
    if (exec->pid < 0) {
        free_exec(exec);
        return;
    }
    if (exec->pid == 0)
        execute_cmd(exec);
    return;
}

static int init_exec(cmd_t *exec, char **array, shell_t *sh)
{
    exec->cmd = NULL;
    exec->array = array;
    exec->env = NULL;
    exec->pid = 0;
    exec->wstatus = 0;
    exec->cmd = get_path(array[0], sh);
    if (!exec->cmd)
        return FAIL;
    exec->env = list_to_array(sh);
    return SUCCESS;
}

void exec_cmd(char **array, shell_t *sh)
{
    cmd_t exec;

    if (init_exec(&exec, array, sh) == FAIL)
        return;
    exec.pid = fork();
    check_child(&exec);
    waitpid(exec.pid, &exec.wstatus, 0);
    check_wstatus(exec.wstatus, sh);
    free_exec(&exec);
    return;
}
