##
## EPITECH PROJECT, 2021
## my_runner - Makefile
## File description:
## jitter jitter
##

SRC	=	initialise.c	\
		is_in_box.c	\
		init_buttons.c	\
		on_event.c	\
		on_keydown.c	\
		on_keydown_2.c

SUB_SRC	=	../my/str/my_strlen.c	\
			../my/str/my_revstr.c	\
			../my/put/my_putchar.c	\
			../my/put/my_putstr.c	\
			../my/put/my_putnbr_base.c	\
			../my/put/my_put_nbr.c	\
			../audio/play_audio.c	\
			../mouse/get_pos.c	\
			../mouse/is_in_square.c

OBJ	=	$(SRC:.c=.o)

SUB_OBJ = $(SUB_SRC:.c=.o)

NAME	=	libmyevents.a

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