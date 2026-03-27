/*
** EPITECH PROJECT, 2025
** my_getnbr
** File description:
** get nbr from str
*/

#include <limits.h>
#include "mysh.h"

static bool is_num(char const c)
{
    if (c >= '0' && c <= '9')
        return true;
    return false;
}

static void get_my_nbr(char const c, long long int *nbr, bool *in_nbr)
{
    if (is_num(c)) {
        *nbr = ((*nbr * 10) + c - '0');
        *in_nbr = true;
    }
    return;
}

static bool to_skip(char const c, int *neg, bool in_nbr)
{
    if (c == '-' && !in_nbr) {
        (*neg)++;
        return true;
    }
    if (!is_num(c) && !in_nbr)
        return true;
    return false;
}

static int apply_sign_and_limit(long long int *nbr, int neg)
{
    if (neg % 2 != 0)
        *nbr = -(*nbr);
    if (*nbr < INT_MIN)
        *nbr = 0;
    if (*nbr > INT_MAX)
        *nbr = 0;
    return (int) (*nbr);
}

int my_getnbr(char const *str)
{
    long long int nbr = 0;
    int neg = 0;
    bool in_nbr = false;

    if (!str)
        return 0;
    for (size_t i = 0; str[i] != '\0'; ++i) {
        if (to_skip(str[i], &neg, in_nbr))
            continue;
        get_my_nbr(str[i], &nbr, &in_nbr);
        if (nbr > (long long)INT_MAX + 1) {
            nbr = 0;
            break;
        }
        if (!is_num(str[i]) && in_nbr)
            break;
    }
    return apply_sign_and_limit(&nbr, neg);
}
