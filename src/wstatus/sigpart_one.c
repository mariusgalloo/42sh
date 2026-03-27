/*
** EPITECH PROJECT, 2026
** minishell2
** File description:
** sigpart_one
*/

#include "mysh.h"

void sigabrt(void)
{
    my_dprintf(2, "Abort\n");
    return;
}

void sigalrm(void)
{
    my_dprintf(2, "Alarm clock\n");
    return;
}

void sigbus(void)
{
    my_dprintf(2, "Bus error\n");
    return;
}

void sigfpe(void)
{
    my_dprintf(2, "Floating exception\n");
    return;
}

void sighup(void)
{
    my_dprintf(2, "Hangup\n");
    return;
}
