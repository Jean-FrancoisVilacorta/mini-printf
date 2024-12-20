/*
** EPITECH PROJECT, 2024
** extract a
** File description:
** a double to hexa
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"

char *extract_g(va_list c, char *print, struct param_s *param)
{
    double nb = va_arg(c, double);
    char *nb_str = long_long_int_to_string((long long int)nb);
    int len = 0;

    if (nb_str == NULL) {
        free(print);
        return NULL;
    }
    if (param->decimals == OFF)
        param->decimals = 6;
    if (param->decimals == 0)
        param->decimals = 1;
    len = my_strlen(nb_str);
    free(nb_str);
    if (len > param->decimals) {
        param->flag = 'e';
        return extract_ge(nb, print, param);
    }
    return extract_gfloat(nb, print, param);
}
