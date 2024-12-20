/*
** EPITECH PROJECT, 2024
** float_params.c
** File description:
** params
*/

#include "../include/my.h"

static char *add_zeros(int size, char *str)
{
    char *ret = malloc(sizeof(char) * (size + 1));
    int x = 0;

    while (str[x] != '\0') {
        ret[x] = str[x];
        x++;
    }
    while (x != size) {
        ret[x] = '0';
        x++;
    }
    ret[size] = '\0';
    free(str);
    return ret;
}

static int count_decimals(char *str)
{
    int count = 0;
    int x = 0;
    int on_off = OFF;

    while (str[x] != '\0') {
        if (on_off == ON)
            count++;
        if (str[x] == '.')
            on_off = ON;
        x++;
    }
    return count;
}

static int add_one(int x, char *str)
{
    if (str[x] == '\0')
        return 0;
    if (str[x] > '5')
        return 1;
    if (str[x] < '5')
        return 0;
    return add_one(x + 1, str);
}

static char *added(int x, char *str, int add)
{
    char *temp = NULL;

    if (x == -1) {
        temp = my_str_cmb("1", str);
        free(str);
        return temp;
    }
    if (str[x] == '.')
        return added(x - 1, str, add);
    str[x] = str[x] + add;
    if (str[x] == ':') {
        str[x] = '0';
        return added(x - 1, str, add);
    }
    return str;
}

static char *cut_dec(int x, char *str, int len, struct param_s *param)
{
    int add = add_one(x + 1, str);

    str = added(x, str, add);
    if (len == 1)
        x--;
    if (param->flag == 'e' && len == 1)
        x--;
    if (len == 0)
        x = x - 2;
    str[x + 1] = '\0';
    return str;
}

static char *edit_len(int len, char *str, struct param_s *param)
{
    int size = my_strlen(str);
    int dec = count_decimals(str);

    if (len == dec)
        return str;
    if (len > dec)
        return add_zeros(size - dec + len, str);
    return cut_dec(size - dec + len - 1, str, len, param);
}

char *apply_params_float(char *str, struct param_s *param)
{
    str = edit_len(param->decimals, str, param);
    param->decimals = OFF;
    return apply_params(str, param);
}
