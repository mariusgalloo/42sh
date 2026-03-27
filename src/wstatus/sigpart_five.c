/*
** EPITECH PROJECT, 2026
** minishell2
** File description:
** sigpart_five
*/

#include <stdio.h>
#include "mysh.h"

void sigvtalrm(void)
{
    (void)fprintf(stderr, "Virtual time alarm\n");
    return;
}

void sigxcpu(void)
{
    (void)fprintf(stderr, "Cputime limit exceeded\n");
    return;
}

void sigxfsz(void)
{
    (void)fprintf(stderr, "Filesize limit exceeded\n");
    return;
}

void sigint(int sig)
{
    (void)signal(sig, sigint);
    return;
}
