/*
** EPITECH PROJECT, 2024
** extract_hexa.x
** File description:
** extract a hexadecimal value
*/

#include "../include/my.h"

char *params_to_hexa(char *ret, char *print, struct param_s *param)
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

char *extract_hexa(va_list c, char *print, struct param_s *param)
{
    char *ret = NULL;
    unsigned long nb = va_arg(c, unsigned long);

    param->positive = OFF;
    if (param->flag == 'x')
        ret = convert_to_hex(nb, 'a', 16);
    else
        ret = convert_to_hex(nb, 'A', 16);
    if (ret == NULL) {
        free(print);
        return NULL;
    }
    return params_to_hexa(ret, print, param);
}
