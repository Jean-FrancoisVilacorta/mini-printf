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

static char *my_strcopy(char const *str)
{
    int size = my_strlen(str);
    char *ret = malloc(sizeof(char) * (size + 1));

    for (int x = 0; str[x] != '\0'; x++)
        ret[x] = str[x];
    ret[size] = '\0';
    return ret;
}

char *extract_str(va_list c, char *print, struct param_s *param)
{
    char *ret = NULL;
    char *temp = (char *) va_arg(c, char *);
    char *end = NULL;
    char *copy = NULL;

    if (temp == NULL) {
        temp = my_str_cmb("(null)", "\0");
    }
    adapt_param(param);
    copy = my_strcopy(temp);
    end = apply_params(copy, param);
    ret = my_str_cmb(print, end);
    free(end);
    if (ret == NULL) {
        free(print);
        return NULL;
    }
    return ret;
}
