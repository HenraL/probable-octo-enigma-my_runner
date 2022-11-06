##
## EPITECH PROJECT, 2021
## my_runner - Makefile
## File description:
## jitter jitter
##

SRC	=	init.c	\
		refresh.c	\
		reset.c

SUB_SRC	=	../my/str/my_strlen.c	\
			../my/str/my_revstr.c	\
			../my/put/my_putchar.c	\
			../my/put/my_putstr.c	\
			../my/put/my_putnbr_base.c	\
			../my/put/my_put_nbr.c	\
			../convert/nb_to_char_star.c

OBJ	=	$(SRC:.c=.o)

SUB_OBJ = $(SUB_SRC:.c=.o)

NAME	=	libmyscores.a

all:	$(NAME)

$(NAME):	$(OBJ) $(SUB_OBJ)
	ar rc $(NAME) $(OBJ) $(SUB_OBJ)

clean:
	rm -f $(OBJ)
	rm -f $(SUB_OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

auteur:
	echo $(USER) > auteur