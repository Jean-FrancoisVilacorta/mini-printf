/*
** EPITECH PROJECT, 2024
** extract_hexa.x
** File description:
** extract a hexadecimal value
*/

#include "../include/my.h"

static char *params_to_2long_hexa(char *ret, char *print,
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

char *extract_2long_hexa(va_list c, char *print, struct param_s *param)
{
    char *ret = NULL;
    unsigned long long nb = va_arg(c, unsigned long long);

    param->positive = OFF;
    if (param->flag == 'x')
        ret = convert_to_long2base(nb, 'a', 16);
    else
        ret = convert_to_long2base(nb, 'A', 16);
    if (ret == NULL) {
        free(print);
        return NULL;
    }
    return params_to_2long_hexa(ret, print, param);
}
