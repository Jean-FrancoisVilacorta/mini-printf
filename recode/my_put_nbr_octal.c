/*
** EPITECH PROJECT, 2024
** my_put_nbr_octal.c
** File description:
** into_to_oct
*/

#include <unistd.h>

int my_putchar(char c)
{
    if (write(1, &c, 1) == -1)
	    return -1;
    return 0;
}

int my_put_nbr_octal(int nb)
{
    if (nb > 7) {
	    if (my_put_nbr_octal(nb / 8) == -1) {
	        return -1;
	    }
	    my_putchar(nb % 8 + '0');
	    return 0;
    }
    if (my_putchar(nb + '0') == -1) {
	    return -1;
        }
    return 0;
}

int main(int argc)
{
    if (my_put_nbr_octal(10) == -1)
	    return 84;
    return 0;
}
