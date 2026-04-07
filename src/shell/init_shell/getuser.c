/*
** EPITECH PROJECT, 2026
** 1shell
** File description:
** getuser
*/

#include "mysh.h"

int len_of_nb(int nb)
{
    int i = 1;
    int result = nb;

    result /= 10;
    if (result > 0) {
        i += len_of_nb(result);
    }
    return i;
}

static char *fill_user(char *char_uid)
{
    FILE *file = fopen("/etc/passwd", "r");
    size_t len = 0;
    ssize_t read;
    char *line = NULL;
    char *user = NULL;

    if (!file)
        return NULL;
    read = getline(&line, &len, file);
    while (read != -1) {
        if (strstr(line, char_uid) != NULL) {
            user = strdup(strtok(line, ":"));
            break;
        }
        read = getline(&line, &len, file);
    }
    free(line);
    fclose(file);
    return user;
}

char *get_user(void)
{
    uid_t uid = getuid();
    char *char_uid = malloc(sizeof(char) * len_of_nb(uid) + 1);
    char *user = NULL;

    if (!char_uid)
        return NULL;
    sprintf(char_uid, "%d", uid);
    user = fill_user(char_uid);
    if (!user)
        return NULL;
    free(char_uid);
    return user;
}
