/*
** EPITECH PROJECT, 2024
** extract_float
** File description:
** extract a float
*/
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include "../include/my.h"

static char *print_numbers(int temp_nb, char *ret)
{
    char *temp = NULL;

    if (temp_nb >= 10) {
        ret = print_numbers(temp_nb / 10, ret);
    }
    temp = add_char(temp_nb % 10 + '0', ret);
    free(ret);
    return temp;
}

int index_comma(float temp_nb_virg)
{
    int n = 0;
    int number = (int)temp_nb_virg;

    while (number != temp_nb_virg) {
        temp_nb_virg = temp_nb_virg * 10;
        number = temp_nb_virg;
        n = n + 1;
    }
    return n;
}

int if_equal(double nb_decimal, int len, int numero, int n)
{
    if (len - 1 == n) {
        nb_decimal = nb_decimal - numero;
        nb_decimal = nb_decimal * 10;
        if (nb_decimal > 5) {
            return 2;
        }
        return 0;
    }
    return -1;
}

static char *print_decimal_nb(char *ret, float temp_nb_virg, int n, int numero)
{
    int nb_int = (int)temp_nb_virg;
    double nb_decimal = (double)temp_nb_virg - (double)nb_int;
    int len = index_comma(temp_nb_virg);
    char *temp = NULL;

    while (nb_decimal != 0 && n < len) {
        nb_decimal = nb_decimal * 10;
        numero = (int) nb_decimal;
        temp = add_char('0' + numero, ret);
        free(ret);
        ret = temp;
        nb_decimal = nb_decimal - numero;
        n = n + 1;
    }
    return ret;
}

char *remove_exedent(char *temp)
{
    int x = my_strlen(temp) - 1;

    if (x < 0)
        return temp;
    if (temp[x] == '0') {
        temp[x] = '\0';
        return remove_exedent(temp);
    }
    if (temp[x] == '.')
        temp[x] = '\0';
    return temp;
}

char *extract_gfloat(double nb, char *print, struct param_s *param)
{
    char *temp = malloc(sizeof(char));
    char *dot = NULL;

    temp[0] = '\0';
    if (nb < 0) {
        nb = -nb;
        param->minus = ON;
    }
    if (param->decimals == OFF)
        param->decimals = 6;
    temp = print_numbers((int)nb, temp);
    dot = add_char('.', temp);
    free(temp);
    temp = print_decimal_nb(dot, nb, 0, 0);
    temp = apply_params_float(temp, param);
    temp = remove_exedent(temp);
    dot = my_str_cmb(print, temp);
    free(print);
    free(temp);
    return dot;
}

char *extract_float(va_list c, char *print, struct param_s *param)
{
    double nb = va_arg(c, const double);
    char *temp = malloc(sizeof(char));
    char *dot = NULL;

    temp[0] = '\0';
    if (nb < 0) {
        nb = -nb;
        param->minus = ON;
    }
    if (param->decimals == OFF)
        param->decimals = 6;
    temp = print_numbers((int)nb, temp);
    dot = add_char('.', temp);
    free(temp);
    temp = print_decimal_nb(dot, nb, 0, 0);
    temp = apply_params_float(temp, param);
    dot = my_str_cmb(print, temp);
    free(print);
    free(temp);
    return dot;
}
