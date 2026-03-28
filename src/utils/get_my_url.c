/*
** EPITECH PROJECT, 2026
** 42sh
** File description:
** get_my_url
*/

#include <string.h>
#include "mysh.h"

static size_t get_len_artist(char **array, size_t *cut)
{
    size_t sum = 0;
    size_t idx = 0;

    for (; array[idx] != NULL; ++idx)
        sum += strlen(array[idx]);
    *cut = (idx - 1);
    return sum;
}

char *get_my_url(char **array)
{
    char *url = NULL;
    size_t len_src = strlen(API_DEEZ);
    size_t cut = 0;
    size_t len_artist = get_len_artist(array, &cut);
    size_t len = len_src + len_artist;

    url = malloc(sizeof(char) * (len + cut + 1));
    if (!url)
        return NULL;
    (void)strcpy(url, API_DEEZ);
    for (size_t idx = 0; array[idx] != NULL; ++idx) {
        (void)strcat(url, array[idx]);
        if (array[idx + 1] != NULL)
            (void)strcat(url, "+");
    }
    url[len + cut] = '\0';
    return url;
}
