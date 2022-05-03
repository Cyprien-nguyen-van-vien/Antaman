##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

SRC	=	my_putchar.c	\
		my_putstr.c	\
		my_putint.c	\
		my_putdouble.c	\
		my_revstr.c	\
		my_strcpy.c	\
		my_strdup.c	\
		my_strlen.c	\
		my_str_to_int.c	\
		my_str_to_double.c	\
		my_int_to_str.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f *~

re:	fclean all
