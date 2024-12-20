/*
** EPITECH PROJECT, 2024
** extract_scientif_not
** File description:
** extract a float to output a scientific notation
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "../include/my.h"

static void print_exp(int exp)
{
    my_putstr("e");
    if (exp < 0) {
        my_putchar('-');
        exp = -exp;
    } else {
        my_putchar('+');
    }
    if (exp < 10 && exp >= 0) {
        my_putchar('0');
        my_putchar(exp + '0');
    }
    if (exp >= 10) {
        print_number(exp);
    }
}

static void add_one(int j, int number, double nb)
{
    double near_one = 0;

    if (j == 6) {
        near_one = (double) number;
        nb = nb;
        if (nb > near_one) {
            number += 1;
        }
    }
}

static void initialize(int number, int integer, int j, int exp)
{
    if (number == 1000000) {
        if (integer == 9) {
            integer = 0;
        }
        integer += 1;
        number = 0;
        j = 1;
        exp += 1;
    }
}

static void print_decimal(int if_zero, int number, int maxi, int j)
{
    while (if_zero != 0) {
        my_putchar('0');
        if_zero -= 1;
    }
    print_number(number);
    maxi = 6 - j;
    while (maxi != 0) {
        my_putchar('0');
        maxi = maxi - 1;
    }
}

static int test_number(int number, int if_zero)
{
    if (number == 0) {
        if_zero += 1;
    }
    return if_zero;
}

static char *decimal(double nb, int index, int exp)
{
    int number = (int)nb;
    double near_one = 0;
    int maxi = 6;
    int j = 0;
    int if_zero = 0;
    double integer = (int)nb;

    nb = nb - number;
    while (number != nb && j != 6) {
        nb = nb * 10;
        number = nb;
        test_number(number, if_zero);
        j = j + 1;
    }
    add_one(j, number, nb);
    initialize(number, integer, j, exp);
    print_number(integer);
    my_putchar('.');
    print_decimal(if_zero, number, maxi, j);
    print_exp(exp);
}

static void nb_is_zero(double nb)
{
    int inferior_to_six = 0;

    print_number(nb);
    my_putchar('.');
    while (inferior_to_six != 6) {
        my_putchar('0');
        inferior_to_six += 1;
    }
    print_exp(0);
}

static char *print_exp_decimal(float nb)
{
    int exp = 0;
    int index = 0;
    int integer = (int) nb;
    int temp = nb;

    while (nb <= 1) {
        nb = nb * 10;
        exp -= 1;
        index += 1;
    }
    decimal(nb, index, exp);
}

static void print_exp_positive(double nb)
{
    int exp = 0;
    int index = 0;
    int integer = (int) integer;

    while (nb >= 10) {
        nb = nb / 10;
        exp += 1;
        index += 1;
    }
    decimal(nb, index, exp);
}

int extract_scientif(va_list c, char *print, struct param_s *param)
{
    double nb = va_arg(c, double);
    char *ret = NULL;

    if (nb < 0) {
        nb = -nb;
        param->minus = ON;
    }
    if (nb == 0)
        nb_is_zero(nb);
    if (nb < 1 && nb > 0)
        print_exp_decimal(nb);
    if (nb >= 10)
        print_exp_positive(nb);
    if (nb >= 1 && nb < 10)
        print_exp_positive(nb);
    return 0;
}
