/*
** EPITECH PROJECT, 2026
** minishell2
** File description:
** sigpart_four
*/

#include "mysh.h"

void sigsys(void)
{
    my_dprintf(2, "Bad system call\n");
    return;
}

void sigterm(void)
{
    my_dprintf(2, "Terminated\n");
    return;
}

void sigtrap(void)
{
    my_dprintf(2, "Trace/BPT trap\n");
    return;
}

void sigusr1(void)
{
    my_dprintf(2, "User signal 1\n");
    return;
}

void sigusr2(void)
{
    my_dprintf(2, "User signal 2\n");
    return;
}
