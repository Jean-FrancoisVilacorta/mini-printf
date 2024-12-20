/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "../include/my.h"
#include <stdlib.h>

static char *extract_hex(unsigned short nb, char *ret,
    char const capital, int base)
{
    unsigned short temp = 0;
    char *temp_c = NULL;

    while (nb > 0) {
        temp = nb % base;
        if (temp < 10)
            temp_c = add_char('0' + temp, ret);
        else
            temp_c = add_char(capital + (temp - 10), ret);
        free(ret);
        ret = temp_c;
        nb /= base;
    }
    ret = my_revstr(ret);
    return ret;
}

static char *error_case(unsigned short nb, char const capital,
    int base)
{
    char *ret = malloc(sizeof(char) * 2);

    if (ret == NULL)
        return NULL;
    ret[0] = '\0';
    ret[1] = '\0';
    if (nb == 0) {
        ret[0] = '0';
        return ret;
    }
    return extract_hex(nb, ret, capital, base);
}

char *convert_to_shortbase(unsigned short nb, char const capital,
    int base)
{
    return error_case(nb, capital, base);
}
