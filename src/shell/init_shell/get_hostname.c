/*
** EPITECH PROJECT, 2026
** 42sh
** File description:
** get_hostname.c
*/

#include "mysh.h"

static void remove_new_line(char **str)
{
    size_t len = strlen(*str);

    if (len > 0 && (*str)[len - 1] == '\n')
        (*str)[len - 1] = '\0';
}

char *get_hostname(void)
{
    size_t len = 0;
    char *hostname = NULL;
    FILE *stream = fopen("/etc/hostname", "r");

    if (!stream)
        return NULL;
    if (getline(&hostname, &len, stream) == FAIL)
        return NULL;
    remove_new_line(&hostname);
    if (fclose(stream) != SUCCESS) {
        perror("fclose hostname file");
        return NULL;
    }
    return hostname;
}
