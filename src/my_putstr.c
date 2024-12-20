/*
** EPITECH PROJECT, 2024
** my_putstr
** File description:
** display one by one, the characters of a string
*/

#include <unistd.h>
#include "../include/my.h"

int my_strlen(char const *str)
{
    int count = 0;

    while (str[count] != '\0')
        count++;
    return count;
}

int my_putstr(char const *str)
{
    int count = my_strlen(str);
    int ret = 0;

    ret = write(1, str, count);
    return ret;
}
