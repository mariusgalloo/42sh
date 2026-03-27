/*
** EPITECH PROJECT, 2026
** minishell2
** File description:
** wstatus
*/

#ifndef WSTATUS_H_
    #define WSTATUS_H_

    #include "mysh.h"

    #define CHILD_COUNT sizeof(wstat) / sizeof(wstat[0])

typedef struct status_s {
    int signal;
    void (*func)(void);
} wstatus_t;

static const wstatus_t wstat[] = {
    {SIGSEGV, &sigsegv},
    {SIGBUS, &sigbus},
    {SIGALRM, &sigalrm},
    {SIGABRT, &sigabrt},
    {SIGFPE, &sigfpe},
    {SIGHUP, &sighup},
    {SIGILL, &sigill},
    {SIGPOLL, &sigpoll},
    {SIGIO, &sigio},
    {SIGIOT, &sigiot},
    {SIGKILL, &sigkill},
    {SIGPROF, &sigprof},
    {SIGPWR, &sigpwr},
    {SIGQUIT, &sigquit},
    {SIGSTKFLT, &sigstkflt},
    {SIGSYS, &sigsys},
    {SIGTERM, &sigterm},
    {SIGTRAP, &sigtrap},
    {SIGTRAP, &sigtrap},
    {SIGUSR1, &sigusr1},
    {SIGUSR2, &sigusr2},
    {SIGVTALRM, &sigvtalrm},
    {SIGXCPU, &sigxcpu},
    {SIGXFSZ, &sigxfsz}
};

#endif
