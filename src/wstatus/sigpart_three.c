/*
** EPITECH PROJECT, 2026
** minishell2
** File description:
** sigpart_three
*/

#include <stdio.h>
#include "mysh.h"

void sigprof(void)
{
    (void)fprintf(stderr, "Profiling time alarm\n");
    return;
}

void sigpwr(void)
{
    (void)fprintf(stderr, "Power failure\n");
    return;
}

void sigquit(void)
{
    (void)fprintf(stderr, "Quit\n");
    return;
}

void sigsegv(void)
{
    (void)fprintf(stderr, "Segmentation fault\n");
    return;
}

void sigstkflt(void)
{
    (void)fprintf(stderr, "Stack limit exceeded\n");
    return;
}
