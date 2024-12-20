/*
** EPITECH PROJECT, 2024
** add_char.c
** File description:
** add a char at the end
*/

#include <stdlib.h>
#include "../include/my.h"

char *add_char(char a, char *print)
{
    char *ret = NULL;
    char *temp = malloc(sizeof(char) * 2);

    if (temp == NULL) {
        free(print);
        return NULL;
    }
    temp[0] = a;
    temp[1] = '\0';
    ret = my_str_cmb(print, temp);
    free(temp);
    if (ret == NULL) {
        free(print);
        return NULL;
    }
    return ret;
}
