/*
** EPITECH PROJECT, 2026
** G-PSU-200-PAR-2-1-minishell2-11
** File description:
** array_to_array
*/

#include "mysh.h"

size_t how_many_array(char **array, char *delim)
{
    bool in_array = false;
    size_t len = 0;

    for (size_t i = 0; array[i] != NULL; ++i) {
        if (my_strcmp(array[i], delim) == 0) {
            in_array = false;
            continue;
        }
        if (!in_array) {
            ++len;
            in_array = true;
        }
    }
    return len;
}

static int fill_array(char ***sub, char **array, size_t *tab)
{
    *sub = malloc(sizeof(char *) * (LEN + 1));
    if (!(*sub))
        return FAIL;
    for (size_t i = 0; i < LEN; ++i)
        (*sub)[i] = array[START + i];
    (*sub)[LEN] = NULL;
    START = 0;
    LEN = 0;
    ++IDX;
    return SUCCESS;
}

static int array_in_array(char ***arrray, char **array, char *delim)
{
    bool separator = false;
    size_t tab[3] = {0, 0, 0};

    for (size_t i = 0; array[i] != NULL; ++i) {
        if (my_strcmp(array[i], delim) == 0)
            separator = true;
        else
            separator = false;
        if (!separator && LEN == 0)
            START = i;
        if (!separator)
            ++LEN;
        if (separator && LEN > 0
            && fill_array(&arrray[IDX], array, tab) == FAIL)
            return FAIL;
    }
    if (LEN > 0 && fill_array(&arrray[IDX], array, tab) == FAIL)
        return FAIL;
    arrray[IDX] = NULL;
    return SUCCESS;
}

char ***array_to_array(char **array, char *delim)
{
    char ***tab = NULL;
    size_t len = how_many_array(array, delim);

    tab = malloc(sizeof(char **) * (len + 1));
    if (!tab)
        return NULL;
    if (array_in_array(tab, array, delim) == FAIL)
        return NULL;
    return tab;
}
