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

void adapt_param(struct param_s *param)
{
    param->positive = OFF;
    param->zero = OFF;
    param->space = OFF;
    param->decimals = OFF;
    param->minus = OFF;
    param->flag = '\0';
}

char *extract_char(va_list c, char *print, struct param_s *param)
{
    char *ret = NULL;
    char a = (const int) va_arg(c, const int);
    char *temp = malloc(sizeof(char) * 2);

    if (temp == NULL)
        return NULL;
    temp[0] = a;
    temp[1] = '\0';
    temp = apply_params(temp, param);
    ret = my_str_cmb(print, temp);
    free(temp);
    if (ret == NULL) {
        free(print);
        return NULL;
    }
    return ret;
}
