/*
** EPITECH PROJECT, 2026
** G-PSU-200-PAR-2-1-minishell2-11
** File description:
** enum
*/

#ifndef ENUM_H_
    #define ENUM_H_

typedef enum {
    FAIL = -1,
    SUCCESS = 0,
    ERROR = 1,
    FOUND = 2
} status_t;

typedef enum {
    SEMI,
    PIPE,
    CMD
} type_t;

typedef enum {
    REDIR_IN,
    DOUBLE_REDIR_IN,
    REDIR_OUT,
    DOUBLE_REDIR_OUT
} redir_type;

#endif
