/*
** EPITECH PROJECT, 2026
** G-PSU-200-PAR-2-1-minishell2-11
** File description:
** my_dprintf
*/

#include <limits.h>
#include <unistd.h>
#include "mysh.h"

int my_dput_nbr(int stream, int nb)
{
    char c;

    if (nb == INT_MIN) {
        write(stream, "-2147483648", 11);
        return SUCCESS;
    }
    if (nb < 0) {
        write(stream, "-", 1);
        nb = -nb;
    }
    if (nb >= 10)
        my_dput_nbr(stream, nb / 10);
    c = (nb % 10) + '0';
    write(stream, &c, 1);
    return SUCCESS;
}

int my_dputstr(int stream, char const *str)
{
    if (!str)
        return FAIL;
    for (size_t i = 0; str[i] != '\0'; ++i)
        write(stream, &str[i], 1);
    return SUCCESS;
}

int my_dputchar(int stream, char c)
{
    return write(stream, &c, 1);
}

static void find_type(int stream, const char str, va_list args)
{
    if (str == 'd' || str == 'i') {
        my_dput_nbr(stream, va_arg(args, int));
    }
    if (str == 'c') {
        my_dputchar(stream, (va_arg(args, int)));
    }
    if (str == '%') {
        my_dputchar(stream, '%');
    }
    if (str == 's') {
        my_dputstr(stream, va_arg(args, char *));
    }
}

int my_dprintf(int stream, const char *format, ...)
{
    va_list arg;

    va_start(arg, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            ++i;
            find_type(stream, format[i], arg);
        } else {
            write(stream, &format[i], 1);
        }
    }
    va_end(arg);
    return 0;
}
