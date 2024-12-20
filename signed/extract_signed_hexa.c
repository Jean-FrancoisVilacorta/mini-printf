/*
** EPITECH PROJECT, 2024
** extract_hexa.x
** File description:
** extract a hexadecimal value
*/

#include "../include/my.h"

static char *params_to_signed_hexa(char *ret, char *print,
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

char *extract_signed_hexa(va_list c, char *print, struct param_s *param)
{
    char *ret = NULL;
    unsigned char nb = (unsigned char)va_arg(c, int);

    param->positive = OFF;
    if (param->flag == 'x')
        ret = convert_to_signedbase(nb, 'a', 16);
    else
        ret = convert_to_signedbase(nb, 'A', 16);
    if (ret == NULL) {
        free(print);
        return NULL;
    }
    return params_to_signed_hexa(ret, print, param);
}
