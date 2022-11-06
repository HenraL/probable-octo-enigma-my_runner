##
## EPITECH PROJECT, 2021
## my_runner - Makefile
## File description:
## jitter jitter
##

SRC	=	get.c	\
		treat.c	\
		get_sprite_name.c	\
		get_sprite_type.c	\
		translate.c	\
		free_matrix.c

SUB_SRC	=	../my/str/my_strlen.c	\
			../my/str/my_revstr.c	\
			../my/str/my_strcpy.c	\
			../my/put/my_putchar.c	\
			../my/put/my_putstr.c	\
			../my/put/my_putnbr_base.c	\
			../my/put/my_put_nbr.c	\
			../my/get/my_get_content.c	\
			../convert/char_star_to_nb.c	\
			../maths/exponential.c


OBJ	=	$(SRC:.c=.o)

SUB_OBJ = $(SUB_SRC:.c=.o)

NAME	=	libmylevel.a

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