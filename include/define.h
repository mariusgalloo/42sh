/*
** EPITECH PROJECT, 2026
** minishell2
** File description:
** define
*/

#include <curl/curl.h>

#ifndef DEFINE_H_
    #define DEFINE_H_

/* PARSER LL OPERATOR */
    #define OPERATORS ";|"
/* PARSER LL OPERATOR */

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

/* STRCMP MATCH*/
    #define MATCH 0
/* STRCMP MATCH*/

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
    #define PATH1 "/usr/local/sbin:/usr/local/bin:"
    #define PATH2 "/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"
    #define CMD_PATH PATH1 PATH2
    #define PATH "PATH"
    #define HOST "HOST"
    #define USER "USER"
    #define PWD "PWD"
    #define HOME "HOME"
    #define PATH_HOME "/home/"
/* ENV_NLS_PATH */

/* API */
    #define API_DEEZ "https://api.deezer.com/search?q="
/* API */

#endif
