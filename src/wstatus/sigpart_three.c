/*
** EPITECH PROJECT, 2026
** minishell2
** File description:
** sigpart_three
*/

#include "mysh.h"

void sigprof(void)
{
    my_dprintf(2, "Profiling time alarm\n");
    return;
}

void sigpwr(void)
{
    my_dprintf(2, "Power failure\n");
    return;
}

void sigquit(void)
{
    my_dprintf(2, "Quit\n");
    return;
}

void sigsegv(void)
{
    my_dprintf(2, "Segmentation fault\n");
    return;
}

void sigstkflt(void)
{
    my_dprintf(2, "Stack limit exceeded\n");
    return;
}
