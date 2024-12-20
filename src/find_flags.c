/*
** EPITECH PROJECT, 2024
** find_parameters
** File description:
** search parameters and flags
*/

#include "../include/my.h"
#include "../include/mini_printf.h"
#include <stdarg.h>
#include <stdlib.h>

static void default_params(struct param_s *param)
{
    (*param).positive = OFF;
    (*param).negative = OFF;
    (*param).zero = OFF;
    (*param).space = OFF;
    (*param).whole = OFF;
    (*param).decimals = OFF;
    (*param).minus = OFF;
    (*param).flag = '\0';
    (*param).hex = OFF;
    (*param).long_u = 0;
    (*param).short_h = 0;
}

static int extract_nb(char const *str, int x, int *point)
{
    int nb = 0;

    while (str[x] != '\0') {
        if (str[x] >= '0' && str[x] <= '9')
            nb = nb * 10 + str[x] - '0';
        else {
            (*point) = nb;
            return x;
        }
        x++;
    }
    (*point) = nb;
    return x;
}

static int extract_whole(char const *str, int x, int *point)
{
    if (str[x] >= '0' && str[x] <= '9') {
        x = extract_nb(str, x, point);
        return x;
    }
    (*point) = 0;
    return x;
}

static int search_flag(char const *str, int x, struct param_s *param)
{
    for (int i = 0; flag[i].c != '\0'; i++) {
        if (flag[i].c == str[x]) {
            (*param).flag = flag[i].c;
            return x;
        }
    }
    return OFF;
}

static int extract_long(char const *str, int x, struct param_s *param)
{
    if (str[x] == '.')
        return extract_whole(str, x + 1, &(*param).decimals);
    if (str[x] >= 'a' && str[x] <= 'z')
        return search_flag(str, x, param);
    if (str[x] >= 'A' && str[x] <= 'Z')
        return search_flag(str, x, param);
    return OFF;
}

static int extract_parameters_2(char const *str, int x, struct param_s *param)
{
    if (str[x] == '-') {
        (*param).negative = ON;
        (*param).zero = OFF;
        return x + 1;
    }
    if (str[x] == ' ') {
        if ((*param).whole == OFF && (*param).decimals == OFF) {
            (*param).space = ON;
            return x + 1;
        } else
            return OFF;
    }
    if (str[x] == '+') {
        (*param).positive = ON;
        return x + 1;
    }
    if (str[x] >= '1' && str[x] <= '9')
        return extract_whole(str, x, &(*param).whole);
    return extract_long(str, x, param);
}

static int extract_parameters(char const *str, int x, struct param_s *param)
{
    if (str[x] == 'l') {
        (*param).long_u += 1;
        return x + 1;
    }
    if (str[x] == 'h') {
        (*param).short_h += 1;
        return x + 1;
    }
    if (str[x] == '%')
        return search_flag(str, x, param);
    if (str[x] == '0') {
        if ((*param).negative != ON)
            (*param).zero = ON;
        return x + 1;
    }
    return extract_parameters_2(str, x, param);
}

int find_parameters(char const *str, int x, char **print,
    va_list parameters_info)
{
    struct param_s param = {0};

    default_params(&param);
    while (str[x] != '\0') {
        x = extract_parameters(str, x, &param);
        if (x == OFF)
            return OFF;
        if (param.flag != '\0') {
            (*print) = search_flags(param.flag, parameters_info,
                (*print), &param);
            return x;
        }
    }
    return x;
}
