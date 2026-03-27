/*
** EPITECH PROJECT, 2026
** minishell2
** File description:
** sigpart_two
*/

#include <stdio.h>
#include "mysh.h"

void sigill(void)
{
    (void)fprintf(stderr, "Illegal instruction\n");
    return;
}

void sigio(void)
{
    (void)fprintf(stderr, "I/O possible\n");
    return;
}

void sigiot(void)
{
    (void)fprintf(stderr, "Aborted\n");
    return;
}

void sigkill(void)
{
    (void)fprintf(stderr, "Killed\n");
    return;
}

void sigpoll(void)
{
    (void)fprintf(stderr, "Pollable event occurred\n");
    return;
}
