/*
** EPITECH PROJECT, 2026
** minishell2
** File description:
** sigpart_four
*/

#include <stdio.h>
#include "mysh.h"

void sigsys(void)
{
    (void)fprintf(stderr, "Bad system call\n");
    return;
}

void sigterm(void)
{
    (void)fprintf(stderr, "Terminated\n");
    return;
}

void sigtrap(void)
{
    (void)fprintf(stderr, "Trace/BPT trap\n");
    return;
}

void sigusr1(void)
{
    (void)fprintf(stderr, "User signal 1\n");
    return;
}

void sigusr2(void)
{
    (void)fprintf(stderr, "User signal 2\n");
    return;
}
