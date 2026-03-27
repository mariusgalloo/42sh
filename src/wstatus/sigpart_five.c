/*
** EPITECH PROJECT, 2026
** minishell2
** File description:
** sigpart_five
*/

#include "mysh.h"

void sigvtalrm(void)
{
    my_dprintf(2, "Virtual time alarm\n");
    return;
}

void sigxcpu(void)
{
    my_dprintf(2, "Cputime limit exceeded\n");
    return;
}

void sigxfsz(void)
{
    my_dprintf(2, "Filesize limit exceeded\n");
    return;
}

void sigint(int sig)
{
    signal(sig, sigint);
}
