##
## EPITECH PROJECT, 2021
## B-CPE-110-PAR-1-1-antman-cyprien.nguyen-van-vien
## File description:
## Makefile
##

MAI =	main.c

SRC	=	src/chardict/create.c	\
		src/chardict/free.c	\
		src/antman.c	\
		src/compress.c	\
		src/count_chars.c	\
		src/file_exists.c	\
		src/generate_tree.c	\
		src/my_put.c	\
		src/towrite.c	\
		src/writerror.c

NAME	=	giantman

CC	=	gcc

all: $(NAME)

FILLAG	=	$(MAI) $(SRC)

CLE	=	*~	\
		src\*~	\
		src\chardict\*~

LDFLAG	=	-L../lib/my -lmy

LIFLAG	=	-I./antman_h -I../include

$(NAME):
	make -C ../lib/my/
	$(CC) -o $(NAME) $(FILLAG) $(LDFLAG) $(LIFLAG) -g3
	make fclean -C ../lib/my/

clean:
	rm -f $(CLE)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

play: fclean all
	make clean
	clear

.PHONY: re all fclean clean play
