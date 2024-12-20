/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** printf
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef MY_H
    #define MY_H
    #define ON 0
    #define OFF -1

struct param_s {
    int positive;
    int negative;
    int minus;
    int zero;
    int space;
    int whole;
    int decimals;
    char flag;
    int hex;
    int long_u;
    int short_h;
};

int my_sprintf(char *str, const char *format, ...);
int my_strlen(char const *str);
int my_putstr(char const *str);
char *my_revstr(char *str);
char *int_to_string(int num);
char *convert_to_hex(unsigned long nb, char const capital, int base);
char *un_int_to_string(unsigned long int num);
char *add_char(char a, char *print);
char *my_str_cmb(const char *str1, const char *str2);
int my_strcmp(char const *s1, char const *s2);
int find_parameters(char const *str, int x, char **print,
    va_list parameters_info);
char *apply_params(char *res, struct param_s *param);
void adapt_param(struct param_s *param);
char *convert_base(char const *nbr, char const *base_from,
    char const *base_to);
char *apply_params_float(char *str, struct param_s *param);
char *convert_to_long2base(unsigned long long nb, char const capital,
    int base);
char *convert_to_shortbase(unsigned short nb, char const capital,
    int base);
char *convert_to_signedbase(unsigned char nb, char const capital,
    int base);
char *search_flags(const char l_flag, va_list parameters_info,
    char *print, struct param_s *param);
char *long_long_int_to_string(long long int num);
char *convert_to_long2base(unsigned long long nb, char const capital,
    int base);
char *extract_gfloat(double nb, char *print, struct param_s *param);
char *extract_ge(double nb, char *print, struct param_s *param);

#endif /* !MY_H */
