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

static double char_to_double(char *str)
{
    int i = 0;
    double nb = 0;
    int negative = 1;

    if (str[0] == '-') {
        negative = -1;
        i++;
    }
    for (int x = i; str[x] != '\0'; x++)
        nb = nb * 10 + str[x] - '0';
    nb = nb * negative;
    return nb;
}

static double extract_dec(double nb)
{
    int temp = 0;
    double ret = 0;
    int x = 0;

    while (nb != 0 && x != 6) {
        nb = nb * 10;
        temp = (int)(nb);
        ret = ret * 10 + (temp);
        nb = nb - (int)(temp);
        temp = 0;
        x++;
    }
    return ret;
}

static double delete_zeros(long long int nb)
{
    if (nb == 0)
        return 0;
    while (nb % 10 == 0) {
        nb /= 10;
    }
    return (double)nb;
}

static char *add_point(char *str)
{
    int len = my_strlen(str);
    char *new = malloc(sizeof(char) * (len + 2));

    new[0] = str[0];
    new[1] = '.';
    for (int i = 1; str[i] != '\0'; i++) {
        new[i + 1] = str[i];
    }
    new[len + 1] = '\0';
    free(str);
    return new;
}

char *part_3(struct param_s *param, char *all, int size)
{
    char *len = NULL;
    char *temp = NULL;

    if (param->decimals == 0)
        param->decimals = 1;
    all = apply_params_float(all, param);
    len = int_to_string(size);
    if (size < 10)
        temp = my_str_cmb(all, "e+0");
    else
        temp = my_str_cmb(all, "e+0");
    free(all);
    all = my_str_cmb(temp, len);
    free(temp);
    return all;
}

static char *error_case(struct param_s *param, int negative,
    char *all, int p_whole)
{
    if (negative == ON) {
        param->whole = p_whole;
        param->negative = ON;
        all = apply_params_float(all, param);
    }
    return all;
}

static char *part_2(char *whole, char *dec, struct param_s *param)
{
    int size = my_strlen(whole);
    char *all = NULL;
    int negative = OFF;
    int p_whole = 0;

    if (size > 1)
        size--;
    whole = add_point(whole);
    all = my_str_cmb(whole, dec);
    if (param->negative == ON) {
        p_whole = param->whole;
        param->whole = 0;
        negative = ON;
    }
    all = part_3(param, all, size);
    free(whole);
    free(dec);
    return error_case(param, negative, all, p_whole);
}

static char *last_print(char *print, char *whole_str, char *dec_str,
    struct param_s *param)
{
    char *all = NULL;
    char *temp = NULL;

    if (param->decimals == OFF)
        param->decimals = 6;
    param->whole -= 4;
    all = part_2(whole_str, dec_str, param);
    temp = my_str_cmb(print, all);
    free(print);
    free(all);
    return temp;
}

char *extract_ge(double nb, char *print, struct param_s *param)
{
    char *whole_str = NULL;
    double whole = 0;
    double dec = 0;
    char *dec_str = NULL;

    param->decimals--;
    if (nb < 0) {
        param->minus = ON;
        nb = -nb;
    }
    whole_str = long_long_int_to_string((long long int)nb);
    whole = char_to_double(whole_str);
    nb = nb - whole;
    dec = extract_dec(nb);
    dec = delete_zeros(dec);
    dec_str = long_long_int_to_string((long long int)dec);
    return last_print(print, whole_str, dec_str, param);
}

char *extract_e(va_list c, char *print, struct param_s *param)
{
    double nb = va_arg(c, double);
    char *whole_str = NULL;
    double whole = 0;
    double dec = 0;
    char *dec_str = NULL;

    if (nb < 0) {
        param->minus = ON;
        nb = -nb;
    }
    whole_str = long_long_int_to_string((long long int)nb);
    whole = char_to_double(whole_str);
    nb = nb - whole;
    dec = extract_dec(nb);
    dec = delete_zeros(dec);
    dec_str = long_long_int_to_string((long long int)dec);
    return last_print(print, whole_str, dec_str, param);
}
