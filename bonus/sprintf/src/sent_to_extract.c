/*
** EPITECH PROJECT, 2024
** find_parameters
** File description:
** search parameters and flags
*/

#include "../include/my.h"
#include "../include/long.h"
#include "../include/long_long.h"
#include "../include/mini_printf.h"
#include "../include/short.h"
#include "../include/signed.h"
#include <stdarg.h>
#include <stdlib.h>

static char *search_long(const char l_flag, va_list parameters_info,
    char *print, struct param_s *param)
{
    for (int i = 0; flag_long[i].c != '\0'; i++) {
        if (flag_long[i].c == l_flag) {
            print = flag_long[i].func(parameters_info, print, param);
            return print;
        }
    }
    free(print);
    return NULL;
}

static char *search_2long(const char l_flag, va_list parameters_info,
    char *print, struct param_s *param)
{
    for (int i = 0; flag_2long[i].c != '\0'; i++) {
        if (flag_2long[i].c == l_flag) {
            print = flag_2long[i].func(parameters_info, print, param);
            return print;
        }
    }
    free(print);
    return NULL;
}

static char *search_short(const char l_flag, va_list parameters_info,
    char *print, struct param_s *param)
{
    for (int i = 0; flag_short[i].c != '\0'; i++) {
        if (flag_short[i].c == l_flag) {
            print = flag_short[i].func(parameters_info, print, param);
            return print;
        }
    }
    free(print);
    return NULL;
}

static char *search_signed(const char l_flag, va_list parameters_info,
    char *print, struct param_s *param)
{
    for (int i = 0; flag_signed[i].c != '\0'; i++) {
        if (flag_signed[i].c == l_flag) {
            print = flag_signed[i].func(parameters_info, print, param);
            return print;
        }
    }
    free(print);
    return NULL;
}

char *search_flags(const char l_flag, va_list parameters_info,
    char *print, struct param_s *param)
{
    if (param->long_u == 1)
        return search_long(l_flag, parameters_info, print, param);
    if (param->long_u == 2)
        return search_2long(l_flag, parameters_info, print, param);
    if (param->short_h == 1)
        return search_short(l_flag, parameters_info, print, param);
    if (param->short_h == 2)
        return search_signed(l_flag, parameters_info, print, param);
    for (int i = 0; flag[i].c != '\0'; i++) {
        if (flag[i].c == l_flag) {
            print = flag[i].func(parameters_info, print, param);
            return print;
        }
    }
    free(print);
    return NULL;
}
