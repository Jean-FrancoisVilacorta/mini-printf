/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** printf
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef SIGNED_H
    #define SIGNED_H

struct flag_signed_s {
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
char *extract_signed_int(va_list c, char *print, struct param_s *param);
char *extract_signed_hexa(va_list c, char *print, struct param_s *param);
char *extract_signed_oct(va_list c, char *print, struct param_s *param);
char *extract_signed_unsigned(va_list c, char *print, struct param_s *param);

static const struct flag_signed_s flag_signed[] = {
    {'i', extract_signed_int},
    {'d', extract_signed_int},
    {'x', extract_signed_hexa},
    {'X', extract_signed_hexa},
    {'u', extract_signed_unsigned},
    {'c', extract_char},
    {'s', extract_str},
    {'f', extract_float},
    {'%', extract_pourcent},
    {'p', extract_pointer},
    {'o', extract_signed_oct},
    {'b', extract_binary},
    {'n', extract_n},
    {'m', extract_errno},
    {'\0', NULL},
};

#endif /* !SIGNED_H */
