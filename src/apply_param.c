/*
** EPITECH PROJECT, 2024
** aplly_params
** File description:
** xd
*/

#include "../include/my.h"

static char *create_str(char contenue, int size)
{
    char *ret = malloc(sizeof(char) * (size + 1));

    if (ret == NULL)
        return NULL;
    for (int x = 0; x != size; x++)
        ret[x] = contenue;
    ret[size] = '\0';
    return ret;
}

static char *decimals(char *res, struct param_s *param, char dec)
{
    int size = my_strlen(res);
    char *extra = NULL;
    char *ret = NULL;

    if (param->decimals == OFF)
        return res;
    if (size >= param->decimals)
        return res;
    size = param->decimals - size;
    extra = create_str(dec, size);
    ret = my_str_cmb(extra, res);
    free(extra);
    free(res);
    if (ret == NULL)
        return NULL;
    return ret;
}

static char *minus(char *res)
{
    char *ret = NULL;

    ret = my_str_cmb("-", res);
    free(res);
    if (ret == NULL)
        return NULL;
    return ret;
}

static char *plus(char *res, struct param_s *param)
{
    char *ret = NULL;

    if (param->minus == ON)
        return minus(res);
    if (param->positive == OFF)
        return res;
    ret = my_str_cmb("+", res);
    free(res);
    if (ret == NULL)
        return NULL;
    return ret;
}

static char *space(char *res, struct param_s *param)
{
    char *ret = NULL;

    if (param->space == OFF)
        return res;
    ret = my_str_cmb(" ", res);
    free(res);
    if (ret == NULL)
        return NULL;
    return ret;
}

static void free_whole(char *s1, char *s2)
{
    free(s1);
    free(s2);
}

static char *whole_f(char *res, struct param_s *param, char whole)
{
    char *add = NULL;
    char *ret = NULL;
    int size = my_strlen(res);

    if (param->whole == OFF)
        return res;
    if (param->space == ON)
        size++;
    if (param->negative == ON)
        whole = ' ';
    if (size >= param->whole)
        return res;
    size = param->whole - size;
    add = create_str(whole, size);
    if (param->negative == ON)
        ret = my_str_cmb(res, add);
    else
        ret = my_str_cmb(add, res);
    free_whole(res, add);
    return ret;
}

static char *hex(char *res, struct param_s *param)
{
    char *added_prefix = NULL;

    if (param->hex == OFF)
        return res;
    added_prefix = my_str_cmb("0x", res);
    free(res);
    return added_prefix;
}

static char *apply_params_2(char *res, struct param_s *param, char whole)
{
    res = plus(res, param);
    if (res == NULL)
        return NULL;
    res = whole_f(res, param, whole);
    if (res == NULL)
        return NULL;
    res = space(res, param);
    if (res == NULL)
        return NULL;
    return res;
}

char *apply_params(char *res, struct param_s *param)
{
    char whole = ' ';
    char dec = '0';

    if (param->zero == ON) {
        if (param->decimals == OFF)
            whole = '0';
        else
            dec = '0';
    }
    res = decimals(res, param, dec);
    if (res == NULL)
        return NULL;
    res = hex(res, param);
    if (res == NULL)
        return NULL;
    return apply_params_2(res, param, whole);
}
