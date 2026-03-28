/*
** EPITECH PROJECT, 2026
** 42sh
** File description:
** my_music
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "mysh.h"

static void open_link(char const *link)
{
    pid_t pid = fork();
    char *args[] = {"xdg-open", (char *)link, NULL};

    if (pid == FAIL)
        return;
    if (pid == SUCCESS) {
        freopen("/dev/null", "w", stderr);
        execvp("xdg-open", args);
        exit(SUCCESS);
    }
    return;
}

static bool check_correspondance(cJSON **titles, cJSON **links, char *input)
{
    for (size_t idx = 0; titles[idx] != NULL; ++idx) {
        if (titles[idx]->string && cJSON_IsString(titles[idx])
            && strcasecmp(input, titles[idx]->valuestring) == SUCCESS) {
            open_link(links[idx]->valuestring);
            free(input);
            return true;
        }
    }
    return false;
}

static void check_music(cJSON **titles, cJSON **links)
{
    char *input = NULL;
    size_t n = 0;

    for (size_t idx = 0; titles[idx] != NULL; ++idx) {
        if (titles[idx]->string && cJSON_IsString(titles[idx]))
            (void)printf("%s\n", titles[idx]->valuestring);
    }
    if (isatty(0) && write(1, "$> ", 3) == FAIL)
        return;
    if (getline(&input, &n, stdin) == FAIL)
        return;
    input[strcspn(input, "\n")] = '\0';
    if (check_correspondance(titles, links, input))
        return;
    (void)fprintf(stderr, "%s: don't match with any song.\n", input);
    free(input);
    return;
}

static int get_titles_and_links(cJSON ***titles, cJSON ***links,
    cJSON *json)
{
    if (get_data_json(titles, "title", json) == FAIL)
        return FAIL;
    if (!(*titles)[0]) {
        (void)fprintf(stderr, "Artist not found.\n");
        return FAIL;
    }
    if (get_data_json(links, "link", json) == FAIL)
        return FAIL;
    return SUCCESS;
}

static int parse_json_deezer(char const *str)
{
    cJSON *json = cJSON_Parse(str);
    cJSON **titles = NULL;
    cJSON **links = NULL;

    if (!json) {
        (void)fprintf(stderr, "Error with cJSON parse.\n");
        return FAIL;
    }
    if (get_titles_and_links(&titles, &links, json) == FAIL)
        return FAIL;
    check_music(titles, links);
    free(titles);
    free(links);
    cJSON_Delete(json);
    return SUCCESS;
}

static size_t data_receive(char *data, UNUSED size_t size,
    size_t nmemb, void *clientp)
{
    size_t realsize = nmemb;
    memory_t *mem = (memory_t *)clientp;
    char *ptr = realloc(mem->response, mem->size + realsize + 1);

    if (!ptr)
        return FAIL;
    mem->response = ptr;
    memcpy(&(mem->response[mem->size]), data, realsize);
    mem->size += realsize;
    mem->response[mem->size] = 0;
    return realsize;
}

static int curl_deezer_api(CURL *curl, char const *url)
{
    CURLcode result;
    memory_t chunk = {NULL, 0};

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, data_receive);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &chunk);
    result = curl_easy_perform(curl);
    if (result != 0)
        return FAIL;
    if (parse_json_deezer(chunk.response) == FAIL) {
        free(chunk.response);
        return FAIL;
    }
    free(chunk.response);
    return SUCCESS;
}

void my_music(char **array, UNUSED shell_t *sh)
{
    char *url = NULL;

    if (!array[1]) {
        (void)fprintf(stderr, "command [ARTIST_NAME]\n");
        return;
    }
    url = get_my_url(array + 1);
    if (!url)
        return;
    get_my_curl(url, curl_deezer_api);
    return;
}
