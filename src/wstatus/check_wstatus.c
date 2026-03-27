/*
** EPITECH PROJECT, 2026
** minishell2
** File description:
** check_wstatus
*/

#include "wstatus.h"
#include "mysh.h"

static void putwstatus(int signal)
{
    for (size_t i = 0; i < CHILD_COUNT; ++i) {
        if (wstat[i].signal == signal) {
            wstat[i].func();
            break;
        }
    }
    return;
}

void check_wstatus(int wstatus, shell_t *sh)
{
    int signal = 0;

    if (WIFEXITED(wstatus)) {
        sh->exit_status = WEXITSTATUS(wstatus);
        return;
    }
    if (WIFSIGNALED(wstatus)) {
        signal = WTERMSIG(wstatus);
        sh->exit_status = SIG_BASE + signal;
        putwstatus(signal);
    }
}
