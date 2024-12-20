/*
** EPITECH PROJECT, 2024
** extract_hexa.x
** File description:
** extract a hexadecimal value
*/

#include "../include/my.h"

static char *params_to_unsigned(char *ret, char *print,
    struct param_s *param)
{
    char *temp = apply_params(ret, param);
    char *end = NULL;

    if (temp == NULL) {
        free(print);
        return NULL;
    }
    end = my_str_cmb(print, temp);
    free(temp);
    free(print);
    if (end == NULL)
        return NULL;
    return end;
}

char *extract_2long_unsigned(va_list c, char *print, struct param_s *param)
{
    char *ret = NULL;
    unsigned long long nb = va_arg(c, unsigned long long);

    param->positive = OFF;
    ret = convert_to_long2base(nb, 'a', 10);
    if (ret == NULL) {
        free(print);
        return NULL;
    }
    return params_to_unsigned(ret, print, param);
}
