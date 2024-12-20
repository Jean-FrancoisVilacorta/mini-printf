##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Write a makefile for MiniShell1
##

SRC =   my_sprintf.c     \
    src/add_char.c      \
    src/my_revstr.c	\
    src/my_putstr.c     \
    src/find_flags.c    \
    src/my_str_cmb.c    \
    src/apply_param.c   \
    src/sent_to_extract.c \
    def/extract_n.c		\
    def/extract_int.c   	\
    def/extract_g.c		\
	def/extract_e.c 	\
	def/extract_str.c   	\
	def/extract_oct.c		\
	def/extract_char.c 		\
	def/float_params.c		\
	def/extract_hexa.c		\
	def/extract_whole.c		\
	def/extract_float.c 	\
	def/extract_errno.c		\
	def/convert_to_hex.c	\
	def/extract_binary.c	\
	def/extract_pointer.c	\
	def/extract_unsigned.c	\
	def/extract_pourcent.c	\
	long/extract_long_int.c			\
	long/extract_long_oct.c			\
	long/extract_long_hexa.c		\
	long/extract_long_unsigned.c	\
    long_long/extract_2long_int.c 		\
    long_long/extract_2long_oct.c 		\
	long_long/extract_2long_hexa.c 		\
	long_long/convert_to_long2base.c 	\
    long_long/extract_2long_unsigned.c 	\
    short/extract_short_int.c 		\
    short/extract_short_oct.c 		\
	short/extract_short_hexa.c 		\
    short/convert_to_shortbase.c 	\
    short/extract_short_unsigned.c 	\
    signed/extract_signed_int.c 		\
    signed/extract_signed_oct.c 		\
	signed/extract_signed_hexa.c 		\
    signed/convert_to_signedbase.c 		\
    signed/extract_signed_unsigned.c 	\

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -g3

NAME = libmy.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ) ;

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) ;

unit_tests: fclean
	gcc -o unit_tests $(SRC) tests/mini_test.c --coverage -lcriterion

tests_run:
	./unit_tests

clean_test:
	rm *.gcno ; rm *.gcda ; rm unit_tests

re: fclean all
