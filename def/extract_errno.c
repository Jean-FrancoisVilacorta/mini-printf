/*
** EPITECH PROJECT, 2024
** mini_printf
** File description:
** main file
*/

#include <stdarg.h>
#include <stdlib.h>
#include <errno.h>
#include "../include/my.h"
#include "../include/errno_errors.h"

static char *my_strcopy(char *str)
{
    int size = my_strlen(str);
    char *ret = malloc(sizeof(char) * (size + 1));

    for (int x = 0; str[x] != '\0'; x++)
        ret[x] = str[x];
    ret[size] = '\0';
    return ret;
}

static char *error_errno(void)
{
    char *nb = int_to_string(errno);
    char *ret = NULL;

    if (ret == NULL)
        return NULL;
    ret = my_str_cmb("Unknown error ", nb);
    free(nb);
    return ret;
}

static char *search_errno(void)
{
    if (errno >= 0 && errno <= 134)
        return my_strcopy(list_errno[errno].str);
    else
        return error_errno();
}

char *extract_errno(va_list c, char *print, struct param_s *param)
{
    char *ret = NULL;
    char *end = NULL;
    char *copy = NULL;

    if (c == NULL)
        end = NULL;
    adapt_param(param);
    copy = search_errno();
    if (copy == NULL)
        return NULL;
    end = apply_params(copy, param);
    if (end == NULL)
        return NULL;
    ret = my_str_cmb(print, end);
    free(end);
    if (ret == NULL) {
        free(print);
        return NULL;
    }
    return ret;
}
