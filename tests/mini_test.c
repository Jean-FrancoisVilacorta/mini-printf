/*
** EPITECH PROJECT, 2024
** test
** File description:
** aaaaa
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"
#include "../include/mini_printf.h"

void redirect_all_std(void)
{
    cr_redirect_stdout () ;
    cr_redirect_stderr () ;
}

Test(my_printf, unsigned_integer, .init = redirect_all_std)
{
    my_printf("%u", 12345);
    cr_assert_stdout_eq_str("12345");
}

Test(my_printf, unsigned_integer_with_plus, .init = redirect_all_std)
{
    my_printf("%+u", 12345);
    cr_assert_stdout_eq_str("12345");
}

Test(my_printf, unsigned_integer_with_space, .init = redirect_all_std)
{
    my_printf("% u", 12345);
    cr_assert_stdout_eq_str(" 12345");
}

Test(my_printf, unsigned_integer_with_zero_padding, .init = redirect_all_std)
{
    my_printf("%05u", 123);
    cr_assert_stdout_eq_str("00123");
}

Test(my_printf, unsigned_integer_with_precision, .init = redirect_all_std)
{
    my_printf("%.5u", 123);
    cr_assert_stdout_eq_str("00123");
}

Test(my_printf, lowercase_hex, .init = redirect_all_std)
{
    my_printf("%x", 255);
    cr_assert_stdout_eq_str("ff");
}

Test(my_printf, uppercase_hex, .init = redirect_all_std)
{
    my_printf("%X", 255);
    cr_assert_stdout_eq_str("FF");
}

Test(my_printf, lowercase_hex_with_precision, .init = redirect_all_std)
{
    my_printf("%.4x", 15);
    cr_assert_stdout_eq_str("000f");
}

Test(my_printf, uppercase_hex_with_precision, .init = redirect_all_std)
{
    my_printf("%.4X", 15);
    cr_assert_stdout_eq_str("000F");
}

Test(my_printf, octal, .init = redirect_all_std)
{
    my_printf("%o", 64);
    cr_assert_stdout_eq_str("100");
}

Test(my_printf, octal_with_zero_padding, .init = redirect_all_std)
{
    my_printf("%05o", 64);
    cr_assert_stdout_eq_str("00100");
}

Test(my_printf, octal_with_precision, .init = redirect_all_std)
{
    my_printf("%.5o", 64);
    cr_assert_stdout_eq_str("00100");
}

Test(my_printf, octal_with_space, .init = redirect_all_std)
{
    my_printf("% o", 64);
    cr_assert_stdout_eq_str(" 100");
}

Test(my_printf, unsigned_integer_with_negative_flag, .init = redirect_all_std)
{
    my_printf("%-u", 12345);
    cr_assert_stdout_eq_str("12345");
}


Test(my_printf, simple_string, .init = redirect_all_std)
{
    my_printf("%s", "¡Hola, Mundo!");
    cr_assert_stdout_eq_str("¡Hola, Mundo!");
}

Test(my_printf, null_string, .init = redirect_all_std)
{
    my_printf("%s", NULL);
    cr_assert_stdout_eq_str("(null)"); 
}

Test(my_printf, single_character, .init = redirect_all_std)
{
    my_printf("%c", 'A');
    cr_assert_stdout_eq_str("A");
}

Test(my_printf, newline_character, .init = redirect_all_std)
{
    my_printf("%c", '\n');
    cr_assert_stdout_eq_str("\n");
}

Test(my_printf, space_character, .init = redirect_all_std)
{
    my_printf("%c", ' ');
    cr_assert_stdout_eq_str(" ");
}

Test(my_printf, special_character, .init = redirect_all_std)
{
    my_printf("%c", '@');
    cr_assert_stdout_eq_str("@");
}

Test(my_printf, string_with_special_chars, .init = redirect_all_std)
{
    my_printf("%s", "¡Fiesta!\nLine2\tTabbed");
    cr_assert_stdout_eq_str("¡Fiesta!\nLine2\tTabbed");
}

Test(my_printf, string_with_formatting, .init = redirect_all_std)
{
    my_printf("%s", "¡Hola!\tWelcome to the party!");
    cr_assert_stdout_eq_str("¡Hola!\tWelcome to the party!");
}


Test(my_printf, short_integer, .init = redirect_all_std)
{
    short int num = 12;
    my_printf("%hd", num);
    cr_assert_stdout_eq_str("12");
}

Test(my_printf, short_negative_integer, .init = redirect_all_std)
{
    short int num = -34;
    my_printf("%hd", num);
    cr_assert_stdout_eq_str("-34");
}

Test(my_printf, long_integer, .init = redirect_all_std)
{
    long int num = 567890;
    my_printf("%ld", num);
    cr_assert_stdout_eq_str("567890");
}

Test(my_printf, long_negative_integer, .init = redirect_all_std)
{
    long int num = -123456;
    my_printf("%ld", num);
    cr_assert_stdout_eq_str("-123456");
}

Test(my_printf, long_long_integer, .init = redirect_all_std)
{
    long long int num = 9876543210;
    my_printf("%lld", num);
    cr_assert_stdout_eq_str("9876543210");
}

Test(my_printf, long_long_negative_integer, .init = redirect_all_std)
{
    long long int num = -9876543210;
    my_printf("%lld", num);
    cr_assert_stdout_eq_str("-9876543210");
}

Test(my_printf, char_integer, .init = redirect_all_std)
{
    char num = 7;
    my_printf("%hhd", num);
    cr_assert_stdout_eq_str("7");
}

Test(my_printf, char_negative_integer, .init = redirect_all_std)
{
    char num = -5;
    my_printf("%hhd", num);
    cr_assert_stdout_eq_str("-5");
}

Test(my_printf, unsigned_short_integer, .init = redirect_all_std)
{
    unsigned short int num = 25;
    my_printf("%hu", num);
    cr_assert_stdout_eq_str("25");
}

Test(my_printf, unsigned_long_integer, .init = redirect_all_std)
{
    unsigned long int num = 123456789;
    my_printf("%lu", num);
    cr_assert_stdout_eq_str("123456789");
}

Test(my_printf, unsigned_long_long_integer, .init = redirect_all_std)
{
    unsigned long long int num = 1122334455;
    my_printf("%llu", num);
    cr_assert_stdout_eq_str("1122334455");
}

Test(my_printf, short_unsigned_integer_with_flags, .init = redirect_all_std)
{
    unsigned short int num = 123;
    my_printf("%+05hu", num);
    cr_assert_stdout_eq_str("00123");
}

Test(my_printf, long_unsigned_integer_with_precision, .init = redirect_all_std)
{
    unsigned long int num = 123;
    my_printf("%.5lu", num);
    cr_assert_stdout_eq_str("00123");
}

Test(my_printf, pourcet, .init = redirect_all_std)
{
    my_printf("%%");
    cr_assert_stdout_eq_str("%%");
}

Test(my_printf, a, .init = redirect_all_std)
{
    unsigned int num = 23;
    my_printf("%.5u", num);
    cr_assert_stdout_eq_str("00023");
}

Test(my_printf, long_long_unsigned_integer_with_flags, .init = redirect_all_std)
{
    unsigned long long int num = 9876543210;
    my_printf("%-10llu", num);
    cr_assert_stdout_eq_str("9876543210");
}

Test(my_printf, char_unsigned_integer_with_zero_padding, .init = redirect_all_std)
{
    unsigned char num = 5;
    my_printf("%04hhu", num);
    cr_assert_stdout_eq_str("0005");
}

Test(my_printf, octal_with_short_length_and_precision, .init = redirect_all_std)
{
    unsigned short int num = 64;
    my_printf("%.5ho", num);
    cr_assert_stdout_eq_str("00100");
}

Test(my_printf, lowercase_hex_with_short_length_and_flags, .init = redirect_all_std)
{
    unsigned short int num = 255;
    my_printf("%-4hx", num);
    cr_assert_stdout_eq_str("ff  ");
}

Test(my_printf, uppercase_hex_with_long_length_and_space, .init = redirect_all_std)
{
    unsigned long int num = 255;
    my_printf("% lX", num);
    cr_assert_stdout_eq_str(" FF");
}

Test(my_printf, decimal_with_space_flag, .init = redirect_all_std)
{
    int num = 100;
    my_printf("% d", num);
    cr_assert_stdout_eq_str(" 100");
}

Test(my_printf, decimal_with_plus_flag, .init = redirect_all_std)
{
    int num = 100;
    my_printf("%+d", num);
    cr_assert_stdout_eq_str("+100");
}

Test(my_printf, binary_with_zero_padding, .init = redirect_all_std)
{
    unsigned int num = 5;
    my_printf("%05b", num);
    cr_assert_stdout_eq_str("00101");
}

Test(my_printf, binary_with_precision, .init = redirect_all_std)
{
    unsigned int num = 5;
    my_printf("%.5b", num);
    cr_assert_stdout_eq_str("00101");
}

Test(my_printf, decimal_with_negative_flag, .init = redirect_all_std)
{
    int num = 100;
    my_printf("%-d", num);
    cr_assert_stdout_eq_str("100");
}

Test(my_printf, float_with_space_flag_g, .init = redirect_all_std)
{
    float num = 123.456;
    my_printf("% g", num);
    cr_assert_stdout_eq_str(" 123.456000");
}

Test(my_printf, float_with_plus_flag_e, .init = redirect_all_std)
{
    float num = 123.456;
    my_printf("%+e", num);
    cr_assert_stdout_eq_str("+1.234560e+02");
}

Test(my_printf, float_with_minus_flag_f, .init = redirect_all_std)
{
    float num = 123.456;
    my_printf("%-f", num);
    cr_assert_stdout_eq_str("123.456000");
}

Test(my_printf, float_with_precision_and_minus_flag_g, .init = redirect_all_std)
{
    float num = 0.0012345;
    my_printf("%-.2g", num);
    cr_assert_stdout_eq_str("0.0012");
}
