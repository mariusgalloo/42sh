/*
** EPITECH PROJECT, 2026
** 42sh
** File description:
** get_my_curl
*/

#include <curl/curl.h>
#include "mysh.h"

int init_curl(CURL **curl)
{
    curl_global_init(CURL_GLOBAL_ALL);
    *curl = curl_easy_init();
    if (!(*curl)) {
        (void)fprintf(stderr, "Error with curl.\n");
        return FAIL;
    }
    return SUCCESS;
}

int get_my_curl(char *url,
    int (*api_func)(CURL *curl, char const *url))
{
    CURL *curl = NULL;

    if (init_curl(&curl) == FAIL)
        return 84;
    if (!url || api_func(curl, url) == FAIL) {
        free(url);
        curl_easy_cleanup(curl);
        curl_global_cleanup();
        return FAIL;
    }
    curl_easy_cleanup(curl);
    curl_global_cleanup();
    free(url);
    return SUCCESS;
}
