/*
** EPITECH PROJECT, 2026
** minishell2
** File description:
** init_cd
*/

#include "mysh.h"

void init_cd(cd_t *cd)
{
    cd->path = NULL;
    cd->flag_l = false;
    cd->flag_p = false;
    return;
}
