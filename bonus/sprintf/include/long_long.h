/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** printf
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef LONG_LONG_H
    #define LONG_LONG_H

struct flag_2long_s {
    char c;
    char *(*func)(va_list c, char *print, struct param_s *param);
};

int my_printf(const char *format, ...);
char *extract_char(va_list c, char *print, struct param_s *param);
char *extract_str(va_list c, char *print, struct param_s *param);
char *extract_pourcent(va_list c, char *print, struct param_s *param);
char *extract_pointer(va_list c, char *print, struct param_s *param);
char *extract_binary(va_list c, char *print, struct param_s *param);
char *extract_n(va_list c, char *print, struct param_s *param);
char *extract_float(va_list c, char *print, struct param_s *params);
char *extract_errno(va_list c, char *print, struct param_s *param);
char *extract_2long_int(va_list c, char *print, struct param_s *param);
char *extract_2long_hexa(va_list c, char *print, struct param_s *param);
char *extract_2long_oct(va_list c, char *print, struct param_s *param);
char *extract_2long_unsigned(va_list c, char *print, struct param_s *param);

static const struct flag_2long_s flag_2long[] = {
    {'i', extract_2long_int},
    {'d', extract_2long_int},
    {'x', extract_2long_hexa},
    {'X', extract_2long_hexa},
    {'u', extract_2long_unsigned},
    {'c', extract_char},
    {'s', extract_str},
    {'f', extract_float},
    {'%', extract_pourcent},
    {'p', extract_pointer},
    {'o', extract_2long_oct},
    {'b', extract_binary},
    {'n', extract_n},
    {'m', extract_errno},
    {'\0', NULL},
};

#endif /* !LONG_LONG_H */
