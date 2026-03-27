/*
** EPITECH PROJECT, 2025
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/

#include <string.h>
#include "mysh.h"

static bool is_delim(char const c, char const *delim)
{
    for (size_t i = 0; delim[i] != '\0'; ++i) {
        if (delim[i] == c)
            return true;
    }
    return false;
}

static int is_spe(char const *str, char const *spe[], size_t idx)
{
    size_t len_spe = 0;

    if (!spe)
        return FAIL;
    for (size_t i = 0; spe[i] != NULL; ++i) {
        len_spe = strlen(spe[i]);
        if (strncmp(str + idx, spe[i], len_spe) == SUCCESS)
            return (int)len_spe;
    }
    return FAIL;
}

static void check_delim(char const c, char const *delim,
    size_t *words, bool sep[2])
{
    sep[0] = is_delim(c, delim);
    if (sep[0]) {
        sep[1] = false;
        return;
    }
    if (!sep[0] && !sep[1]) {
        sep[1] = true;
        ++(*words);
    }
    return;
}

static void how_many_word(char const *str, char const *delim,
    char const *spe[], size_t *words)
{
    int found = 0;
    bool sep[2] = {false, false};

    for (size_t i = 0; str[i] != '\0'; ++i) {
        found = is_spe(str, spe, i);
        if (found != FAIL) {
            ++(*words);
            i += (found - 1);
            sep[1] = false;
            continue;
        }
        check_delim(str[i], delim, words, sep);
    }
    return;
}

static int fill_array(char **line, char const *str, size_t *tab)
{
    *line = strndup(str + START, LEN);
    if (!(*line))
        return FAIL;
    START = 0;
    LEN = 0;
    ++IDX;
    return SUCCESS;
}

static int fill_spe(char **line, char const *str, int len, size_t *tab)
{
    *line = strndup(str + I, len);
    if (!(*line))
        return FAIL;
    I += (len - 1);
    ++IDX;
    return SUCCESS;
}

static int handle_separator(char **line, char const *str,
    bool *separator, size_t *tab)
{
    if (!(*separator) && LEN == 0)
        START = I;
    if (!(*separator))
        ++LEN;
    if ((*separator) && LEN > 0 && fill_array(line, str, tab) == FAIL)
        return FAIL;
    return SUCCESS;
}

static int handle_spe(char **array, char const *str,
    size_t *tab, int found)
{
    if (LEN > 0 && fill_array(&array[IDX], str, tab) == FAIL)
        return FAIL;
    if (fill_spe(&array[IDX], str, found, tab) == FAIL)
        return FAIL;
    return SUCCESS;
}

static int word_to_array(char **array, char const *str,
    char const *delim, char const *spe[])
{
    bool separator = false;
    size_t tab[4] = {0, 0, 0, 0};
    int found = 0;

    for (; str[I] != '\0'; ++I) {
        separator = is_delim(str[I], delim);
        found = is_spe(str, spe, I);
        if (found != FAIL
            && handle_spe(array, str, tab, found) == FAIL)
            return FAIL;
        if (found != FAIL)
            separator = true;
        if (handle_separator(&array[IDX], str, &separator, tab) == FAIL)
            return FAIL;
    }
    if (LEN > 0 && fill_array(&array[IDX], str, tab) == FAIL)
        return FAIL;
    return SUCCESS;
}

char **my_str_to_word_array(char const *str,
    char const *delim, char const *spe[])
{
    char **array = NULL;
    size_t words = 0;

    if (!str || !delim)
        return NULL;
    how_many_word(str, delim, spe, &words);
    if (words == 0)
        return NULL;
    array = malloc(sizeof(char *) * (words + 1));
    if (!array)
        return NULL;
    if (word_to_array(array, str, delim, spe) == FAIL)
        return NULL;
    array[words] = NULL;
    return array;
}
