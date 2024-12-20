/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** printf
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef LONG_H
    #define LONG_H

struct flag_long_s {
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
char *extract_long_int(va_list c, char *print, struct param_s *param);
char *extract_long_hexa(va_list c, char *print, struct param_s *param);
char *extract_long_oct(va_list c, char *print, struct param_s *param);
char *extract_long_unsigned(va_list c, char *print, struct param_s *param);

static const struct flag_long_s flag_long[] = {
    {'i', extract_long_int},
    {'d', extract_long_int},
    {'x', extract_long_hexa},
    {'X', extract_long_hexa},
    {'u', extract_long_unsigned},
    {'c', extract_char},
    {'s', extract_str},
    {'f', extract_float},
    {'%', extract_pourcent},
    {'p', extract_pointer},
    {'o', extract_long_oct},
    {'b', extract_binary},
    {'n', extract_n},
    {'m', extract_errno},
    {'\0', NULL},
};

#endif /* !LONG_H */
