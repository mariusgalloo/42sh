/*
** EPITECH PROJECT, 2026
** minishell2
** File description:
** sigpart_one
*/

#include <stdio.h>
#include "mysh.h"

void sigabrt(void)
{
    (void)fprintf(stderr, "Abort\n");
    return;
}

void sigalrm(void)
{
    (void)fprintf(stderr, "Alarm clock\n");
    return;
}

void sigbus(void)
{
    (void)fprintf(stderr, "Bus error\n");
    return;
}

void sigfpe(void)
{
    (void)fprintf(stderr, "Floating exception\n");
    return;
}

void sighup(void)
{
    (void)fprintf(stderr, "Hangup\n");
    return;
}
