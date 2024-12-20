/*
** EPITECH PROJECT, 2024
** mini_printf
** File description:
** main file
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"

static int count_num(int num, int negative)
{
    int ret = 0;

    if (negative == ON)
        ret++;
    while (num > 0) {
        ret++;
        num /= 10;
    }
    ret++;
    return ret;
}

static char *finish_inverse(char *str, int i)
{
    char temp = '\0';

    for (int j = 0; j < i / 2; j++) {
        temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = temp;
    }
    return str;
}

static char *add_nb(int num, int negative)
{
    int i = 0;
    int size = count_num(num, negative);
    char *str = malloc(size * sizeof(char));

    if (str == NULL)
        return NULL;
    while (num > 0) {
        str[i] = (num % 10) + '0';
        i++;
        num /= 10;
    }
    if (negative == ON) {
        str[i] = '-';
        i++;
    }
    str[i] = '\0';
    return finish_inverse(str, i);
}

char *int_to_string(int num)
{
    char *ret = NULL;
    int negative = OFF;

    if (num == 0) {
        ret = malloc(sizeof(char *) * 2);
        ret[0] = '0';
        ret[1] = '\0';
        return ret;
    }
    if (num < 0) {
        negative = ON;
        num = -num;
    }
    return add_nb(num, negative);
}

char *extract_int(va_list c, char *print, struct param_s *param)
{
    char *ret = NULL;
    int nb = (const int) va_arg(c, const int);
    char *temp = NULL;

    if (nb < 0) {
        param->minus = ON;
        nb = nb * -1;
    }
    temp = int_to_string(nb);
    if (temp == NULL)
        return NULL;
    temp = apply_params(temp, param);
    ret = my_str_cmb(print, temp);
    free(temp);
    if (ret == NULL) {
        free(print);
        return NULL;
    }
    return ret;
}
