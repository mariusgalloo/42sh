/*
** EPITECH PROJECT, 2026
** 42sh
** File description:
** my_compute
*/

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <errno.h>
#include "compute.h"
#include "mysh.h"

static size_t len_array(char **array)
{
    size_t idx = 0;

    for (; array[idx] != NULL; ++idx);
    return idx;
}

static int get_sign(char const *str, char *sign)
{
    if (str[0] == '\0'
        || str[1] != '\0'
        || !strchr("+-*/", str[0]))
        return FAIL;
    *sign = str[0];
    return SUCCESS;
}

static int get_double(char const *s1, char const *s2,
    double *val1, double *val2)
{
    char *end = NULL;

    *val1 = strtod(s1, &end);
    if (end[0] != '\0')
        return FAIL;
    if (errno == ERANGE) {
        (void)fprintf(stderr, "Number out of range.\n");
        return FAIL;
    }
    *val2 = strtod(s2, &end);
    if (end[0] != '\0')
        return FAIL;
    if (errno == ERANGE) {
        (void)fprintf(stderr, "Number out of range.\n");
        return FAIL;
    }
    return SUCCESS;
}

double add(double a, double b)
{
    return a + b;
}

double sub(double a, double b)
{
    return a - b;
}

double mul(double a, double b)
{
    return a * b;
}

double divide(double a, double b)
{
    if (b == 0) {
        fprintf(stderr, "Division by zero.\n");
        return 0;
    }
    return a / b;
}

static void compute(double val1, double val2, char const sign)
{
    for (size_t i = 0; i < TAB_COUNT; ++i) {
        if (tab_comp[i].sign == sign) {
            (void)printf("result: %g\n", tab_comp[i].comp_db(val1, val2));
            return;
        }
    }
    return;
}

void my_compute(char **array, UNUSED shell_t *sh)
{
    char sign;
    double val1 = 0;
    double val2 = 0;

    if (len_array(array + 1) != 3) {
        (void)fprintf(stderr, "compute [nbr1] [sign] [nbr2].\n");
        return;
    }
    if (get_sign(array[2], &sign) == FAIL) {
        (void)fprintf(stderr, "Wrong type of sign.\n");
        return;
    }
    if (get_double(array[1], array[3], &val1, &val2) == FAIL)
        return;
    compute(val1, val2, sign);
    return;
}
