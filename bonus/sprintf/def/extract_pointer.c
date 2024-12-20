/*
** EPITECH PROJECT, 2024
** extract_pointer.c
** File description:
** print the pointer
*/

#include "../include/my.h"

static char *params_to_pointer(char *ret, char *print, struct param_s *param)
{
    char *added_params = apply_params(ret, param);
    char *end = NULL;

    if (added_params == NULL) {
        free(print);
        return NULL;
    }
    end = my_str_cmb(print, added_params);
    free(added_params);
    free(print);
    if (end == NULL)
        return NULL;
    return end;
}

char *extract_pointer(va_list c, char *print, struct param_s *param)
{
    char *ret = NULL;
    void *pointer = va_arg(c, void *);
    unsigned long nb = (unsigned long)pointer;

    param->hex = ON;
    ret = convert_to_hex(nb, 'a', 16);
    if (ret == NULL) {
        free(print);
        return NULL;
    }
    return params_to_pointer(ret, print, param);
}
