/*
** EPITECH PROJECT, 2026
** 42sh
** File description:
** compute
*/

#ifndef COMPUTE_H_
    #define COMPUTE_H_

    #include "enum.h"
    #include "mysh.h"

    #define TAB_COUNT sizeof(tab_comp) / sizeof(tab_comp[0])

typedef struct {
    char sign;
    double (*comp_db)(double, double);
} comp_t;

static const comp_t tab_comp[] = {
    {'+', add},
    {'-', sub},
    {'*', mul},
    {'/', divide},
};

#endif
