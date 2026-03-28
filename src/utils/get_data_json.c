/*
** EPITECH PROJECT, 2026
** 42sh
** File description:
** get_data_json
*/

#include "mysh.h"

static int fill_element(cJSON **field, char const *name, cJSON *data, int len)
{
    cJSON *element = NULL;

    for (int idx = 0; idx < len; ++idx) {
        element = cJSON_GetArrayItem(data, idx);
        if (!element) {
            (void)fprintf(stderr, "Error with cJSON element.\n");
            return FAIL;
        }
        field[idx] = cJSON_GetObjectItem(element, name);
    }
    return SUCCESS;
}

int get_data_json(cJSON ***field, char const *name, cJSON *json)
{
    cJSON *data = NULL;
    int len = 0;

    data = cJSON_GetObjectItem(json, "data");
    if (!data) {
        (void)fprintf(stderr, "Error with cJSON data.\n");
        return FAIL;
    }
    len = cJSON_GetArraySize(data);
    *field = malloc(sizeof(cJSON *) * (len + 1));
    if (!(*field)) {
        (void)fprintf(stderr, "Error with cJSON field.\n");
        return FAIL;
    }
    if (fill_element(*field, name, data, len) == -1)
        return FAIL;
    (*field)[len] = NULL;
    return SUCCESS;
}
