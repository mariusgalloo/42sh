/*
** EPITECH PROJECT, 2026
** minishell2
** File description:
** sigpart_two
*/

#include "mysh.h"

void sigill(void)
{
    my_dprintf(2, "Illegal instruction\n");
    return;
}

void sigio(void)
{
    my_dprintf(2, "I/O possible\n");
    return;
}

void sigiot(void)
{
    my_dprintf(2, "Aborted\n");
    return;
}

void sigkill(void)
{
    my_dprintf(2, "Killed\n");
    return;
}

void sigpoll(void)
{
    my_dprintf(2, "Pollable event occurred\n");
    return;
}
