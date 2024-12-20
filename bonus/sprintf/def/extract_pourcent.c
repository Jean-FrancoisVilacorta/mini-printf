/*
** EPITECH PROJECT, 2024
** extract_pourcent
** File description:
** pourcent
*/

#include <stdarg.h>
#include <stddef.h>
#include "../include/my.h"

char *extract_pourcent(va_list c, char *print, struct param_s *param)
{
    int a = 0;

    if (c == NULL)
        a = 0;
    a++;
    adapt_param(param);
    print = add_char('%', print);
    if (print == NULL)
        return NULL;
    return print;
}
