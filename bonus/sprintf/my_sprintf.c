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

static void add_print_into_str(char *str, char *print)
{
    for (int i = 0; print[i] != '\0'; i++) {
        str[i] = print[i];
    }
}

int read_string(char *str, const char *format, va_list parameters_info,
    char *print)
{
    int x = 0;
    int ret = 0;

    while (format[x] != '\0') {
        x = analize_str(format, parameters_info, &print, x);
        if (print == NULL)
            return 84;
        x++;
    }
    add_print_into_str(str, print);
    ret = my_strlen(print);
    va_end(parameters_info);
    return ret;
}

int my_sprintf(char *str, const char *format, ...)
{
    va_list paramaters_info;
    char *print = NULL;

    if (format == NULL)
        return -1;
    print = malloc(sizeof(char));
    print[0] = '\0';
    va_start(paramaters_info, format);
    return read_string(str, format, paramaters_info, print);
}
