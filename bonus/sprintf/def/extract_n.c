/*
** EPITECH PROJECT, 2024
** extract_hexa.x
** File description:
** extract a hexadecimal value
*/

#include "../include/my.h"

char *extract_n(va_list c, char *print, struct param_s *param)
{
    int *nb = va_arg(c, int *);

    param->positive = OFF;
    *nb = my_strlen(print);
    return print;
}
