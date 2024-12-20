/*
** EPITECH PROJECT, 2024
** extract a
** File description:
** a double to hexa
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"

double char_to_double(char *str)
{
    int i = 0;
    double nb = 0;
    int negative = 1;

    if(str[0] == '-') {
	negative = -1;
	i++;
    }
    for (int x = i; str[x] != '\0'; x++)
	nb = nb * 10 + str[x] - '0';
    nb = nb * negative;
    return nb;
}

double extract_dec(double nb)
{
    int temp = 0;
    double ret = 0;

    int x = 0;
    while (nb != 0 && x != 6) {
	nb = nb * 10;
	temp = (int)(nb);
	ret = ret * 10 + (temp);
	nb  = nb - (int)(temp);
	temp = 0;
	x++;
    }
    return ret;
}

double delete_zeros(long long int nb)
{
    if (nb == 0)
	return 0;
    while (nb % 10 == 0) {
	nb /= 10;
    }
    return (double)nb;
}

char *convert(char *str, int x)
{
    int end = x + 4;
    int hex = 0;

    while (str[x] != '\0') {
	hex = hex << 1;
	if (str[x] == '1')
	    hex += 1;
	x++;
    }
    return convert_to_hex(hex, 'a', 16);
}

char *binaire_to_hexa(char *str)
{
    int x = 1;
    int count = 0;
    char *res = malloc(sizeof(char) * 3);
    char *temp = NULL;
    char *add = NULL;
    int len = my_strlen(str) - 1;

    res[0] = '1';
    res[1] = '.';
    res[2] = '\0';
    while (count != 1) {
	temp = convert(str, x);
        add = my_str_cmb(res, temp);
        free(temp);
        free(res);
        res = add;
        x = x + 4;
        count++;
    }
    free(str);
    return res;
}

char *convert_to_binaire(double whole, double dec, char flag)
{
    char *b_whole = convert_to_long2base((unsigned long long)whole, flag, 2);
    char *b_dec = convert_to_long2base((unsigned long long)dec, flag, 2);
    char *cmb = my_str_cmb(b_whole, b_dec);
    char *ret = NULL;

    free(b_whole);
    free(b_dec);
    cmb = binaire_to_hexa(cmb);
    if (flag == 'a')
	ret = my_str_cmb("0x", cmb);
    else
	ret = my_str_cmb("0X", cmb);
    free(cmb);
    return ret;
}

char *extract_a(va_list c, char *print, struct param_s *param)
{
    double nb = va_arg(c, double);
    char *whole_str = NULL;
    double whole = 0;
    double dec = 0;
    char *all = NULL;

    whole_str = long_long_int_to_string((long long int)nb);
    if (whole_str == NULL) {
        free(print);
        return NULL;
    }
    whole = char_to_double(whole_str);
    free(whole_str);
    nb = nb - whole;
    dec = extract_dec(nb);
    //dec = delete_zeros(dec);
    all = convert_to_binaire(whole, dec, param->flag);
    printf("%s\n", all);
    free(all);
    return print;
}
