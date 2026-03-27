/*
** EPITECH PROJECT, 2026
** mysh
** File description:
** main
*/

#include <signal.h>
#include "mysh.h"

int main(int ac, char UNUSED **av, char **env)
{
    if (ac != MAX_ARGS || !env)
        return EXIT_FAIL;
    signal(SIGINT, sigint);
    return mysh(env);
}
