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

static int count_num(unsigned long int num)
{
    int ret = 0;

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

static char *add_nb(unsigned long int num)
{
    int i = 0;
    int size = count_num(num);
    char *str = malloc(size * sizeof(char));

    if (str == NULL)
        return NULL;
    while (num > 0) {
        str[i] = (num % 10) + '0';
        i++;
        num /= 10;
    }
    str[i] = '\0';
    return finish_inverse(str, i);
}

char *un_int_to_string(unsigned long int num)
{
    char *ret = NULL;

    if (num == 0) {
        ret = malloc(sizeof(char *) * 2);
        ret[0] = '0';
        ret[1] = '\0';
        return ret;
    }
    return add_nb(num);
}

static void adapt_param_u(struct param_s *param)
{
    param->positive = OFF;
    param->zero = OFF;
    param->space = OFF;
}

char *extract_u(va_list c, char *print, struct param_s *param)
{
    char *ret = NULL;
    unsigned long int nb = va_arg(c, unsigned long int);
    char *temp = NULL;

    temp = un_int_to_string(nb);
    if (temp == NULL)
        return NULL;
    adapt_param_u(param);
    temp = apply_params(temp, param);
    ret = my_str_cmb(print, temp);
    free(temp);
    if (ret == NULL) {
        free(print);
        return NULL;
    }
    return ret;
}
