/*
** EPITECH PROJECT, 2024
** mini_printf
** File description:
** main file
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/mini_printf.h"
#include "include/my.h"

static int analize_str(const char *str, va_list parameters_info,
    char **print, int x)
{
    char *ret = NULL;
    int temp_x = 0;

    if (str[x] == '%') {
        temp_x = find_parameters(str, x + 1, print, parameters_info);
        if (temp_x == OFF)
            (*print) = add_char('%', (*print));
        else
            x = temp_x;
    } else {
        ret = add_char(str[x], (*print));
        free(*print);
        *print = ret;
    }
    return x;
}

int read_string(const char *str, va_list parameters_info, char *print)
{
    int x = 0;
    int ret = 0;

    while (str[x] != '\0') {
        x = analize_str(str, parameters_info, &print, x);
        if (print == NULL)
            return 84;
        x++;
    }
    if (my_putstr(print) == -1)
        return -1;
    ret = my_strlen(print);
    free(print);
    va_end(parameters_info);
    return ret;
}

int my_printf(const char *format, ...)
{
    va_list paramaters_info;
    char *print = NULL;

    if (format == NULL)
        return -1;
    print = malloc(sizeof(char));
    print[0] = '\0';
    va_start(paramaters_info, format);
    return read_string(format, paramaters_info, print);
}
