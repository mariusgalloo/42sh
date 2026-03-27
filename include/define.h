/*
** EPITECH PROJECT, 2026
** minishell2
** File description:
** define
*/

#ifndef DEFINE_H_
    #define DEFINE_H_

/* STATUS_ERROR */
    #define EXIT_FAIL 84
    #define EXIT_SUCCESS 0
/* STATUS_ERROR */

/* WSTATUS */
    #define SIG_BASE 128
/* WSTATUS */

/* MAIN_MAX_ARGS */
    #define MAX_ARGS 1
/* MAIN_MAX_ARGS */

/* MY_STR_TO_WORD_ARRAY */
    #define DELIM " \t\n\r"
    #define START tab[0]
    #define LEN tab[1]
    #define IDX tab[2]
    #define I tab[3]
/* MY_STR_TO_WORD_ARRAY */

/* UNUSED */
    #define UNUSED __attribute__((unused))
/* UNUSED */

/* ENV_NLS_PATH */
    #define NLS1 "/usr/share/locale/%L/LC_MESSAGES/%N.cat:"
    #define NLS2 "/usr/share/locale/%l/LC_MESSAGES/%N.cat"
    #define NLS_PATH NLS1 NLS2
    #define NLSPATH "NLSPATH"
/* ENV_NLS_PATH */

#endif
