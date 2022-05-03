##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile de antman
##

NAME	=	zantman

all: $(NAME)

$(NAME):
	make -C lib/my
	make re -C antman
	make re -C giantman

clean:
	make clean -C lib/my
	make clean -C antman
	make clean -C giantman

fclean: clean
	make fclean -C lib/my
	make fclean -C antman/
	make fclean -C giantman/

re:	fclean all

play: fclean all
	make clean
	clear

.PHONY: re all fclean clean play
