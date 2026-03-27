/*
** EPITECH PROJECT, 2026
** minishell2
** File description:
** mysh
*/

#ifndef MYSH_H_
    #define MYSH_H_

    #include <stdbool.h>
    #include <stdlib.h>
    #include <stdarg.h>
    #include <signal.h>

    #include "enum.h"
    #include "define.h"
    #include "struct.h"


int mysh(char **env);

/* UTILS */
void init_sh(shell_t *sh);
void print_list(list_t *env);
int fill_env(char **env, shell_t *sh);
int push_back(char const *var, char const *val, shell_t *sh);
char *my_getenv(char const *var, shell_t *sh);
void free_array(char **array);
void free_narray(char **array, size_t end);
void free_sh(shell_t *sh);
int push_env(char const *var, char const *val, shell_t *sh);
char *concat_paths(char const *s1, char const *s2, char const *c);
char **list_to_array(shell_t *sh);
void init_cd(cd_t *cd);
void free_tab(char ***tab);
/* UTILS */

/* LIB */
char **my_str_to_word_array(char const *str,
    char const *delim, char const *spe[]);
bool is_nbr(char const *str);
int my_dprintf(int stream, const char *format, ...);
char *my_strdup(char const *str);
size_t my_strlen(char const *str);
char *my_strndup(char const *src, size_t size);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *dest, char const *src);
char *my_strchr(char *str, char c);
char ***array_to_array(char **array, char *delim);
int my_getnbr(char const *str);
int my_strncmp(char const *s1, char const *s2, size_t n);
/* LIB */

/* SHELL_S */
int shell_loop(shell_t *sh);
int get_input(char **cmd, char ***array);
int shell_iteration(shell_t *sh);
int cmd_check(char **array, shell_t *sh);
void exec_cmd(char **array, shell_t *sh);
/* SHELL_S */

/* BUILTIN */
void my_exit(char **array, shell_t *sh);
void my_env(char **array, shell_t *sh);
void my_setenv(char **array, shell_t *sh);
void my_unsetenv(char **array, shell_t *sh);
void my_cd(char **array, shell_t *sh);
/* BUILTIN */


/* SIGNALS */
void check_wstatus(int wstatus, shell_t *sh);
void sigsegv(void);
void sigbus(void);
void sigalrm(void);
void sigabrt(void);
void sigfpe(void);
void sighup(void);
void sigill(void);
void sigio(void);
void sigiot(void);
void sigkill(void);
void sigpoll(void);
void sigprof(void);
void sigpwr(void);
void sigquit(void);
void sigstkflt(void);
void sigsys(void);
void sigterm(void);
void sigtrap(void);
void sigusr1(void);
void sigusr2(void);
void sigvtalrm(void);
void sigxcpu(void);
void sigxfsz(void);
void sigint(int sig);
/* SIGNALS */

#endif
