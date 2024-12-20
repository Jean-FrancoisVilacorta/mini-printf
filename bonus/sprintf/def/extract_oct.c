/*
** EPITECH PROJECT, 2024
** extract_hexa.x
** File description:
** extract a hexadecimal value
*/

#include "../include/my.h"

static char *params_to_oct(char *ret, char *print, struct param_s *param)
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

char *extract_oct(va_list c, char *print, struct param_s *param)
{
    char *ret = NULL;
    unsigned long nb = va_arg(c, unsigned long);

    param->positive = OFF;
    ret = convert_to_hex(nb, 'a', 8);
    if (ret == NULL) {
        free(print);
        return NULL;
    }
    return params_to_oct(ret, print, param);
}
