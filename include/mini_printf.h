/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** printf
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

#ifndef MY_PRINTF_H
    #define MY_PRINTF_H

struct flag_s {
    char c;
    char *(*func)(va_list c, char *print, struct param_s *param);
};

int my_printf(const char *format, ...);
int my_strlen(char const *str);
char *my_str_cmb(const char *str1, const char *str2);
char *extract_char(va_list c, char *print, struct param_s *param);
char *extract_int(va_list c, char *print, struct param_s *param);
char *extract_str(va_list c, char *print, struct param_s *param);
char *extract_pourcent(va_list c, char *print, struct param_s *param);
char *extract_hexa(va_list c, char *print, struct param_s *param);
char *extract_pointer(va_list c, char *print, struct param_s *param);
char *extract_oct(va_list c, char *print, struct param_s *param);
char *extract_unsigned(va_list c, char *print, struct param_s *param);
char *extract_binary(va_list c, char *print, struct param_s *param);
char *extract_n(va_list c, char *print, struct param_s *param);
char *extract_float(va_list c, char *print, struct param_s *params);
char *extract_errno(va_list c, char *print, struct param_s *param);
char *extract_g(va_list c, char *print, struct param_s *param);
char *extract_e(va_list c, char *print, struct param_s *param);

static const struct flag_s flag[] = {
    {'c', extract_char},
    {'s', extract_str},
    {'i', extract_int},
    {'d', extract_int},
    {'f', extract_float},
    {'%', extract_pourcent},
    {'x', extract_hexa},
    {'X', extract_hexa},
    {'p', extract_pointer},
    {'o', extract_oct},
    {'u', extract_unsigned},
    {'b', extract_binary},
    {'n', extract_n},
    {'m', extract_errno},
    {'g', extract_g},
    {'e', extract_e},
    {'\0', NULL},
};

#endif /* !MY_PRINTF_H */
