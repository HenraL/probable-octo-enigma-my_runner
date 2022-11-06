##
## EPITECH PROJECT, 2021
## my_runner - Makefile
## File description:
## jitter jitter
##

SRC	=	load.c	\
		load_two.c	\
		load_and_resize.c	\
		dup_sprite.c	\
		next_frame.c	\
		initialise_drag_axis.c	\
		initialise_sfintrect.c	\
		initialise_sffloatrect.c	\
		init_anim.c	\
		display.c	\
		moove.c	\
		move_sprite_with_struct.c	\
		move_two.c	\
		rescale.c	\
		rescale_by_percent.c	\
		randomise_position.c	\
		draw_two.c	\
		is_reset_drag_needed.c	\
		is_coliding.c	\
		is_out_of_home.c	\
		is_reset_pos_needed.c	\
		change_two_val.c	\
		override.c	\
		free.c	\
		free_two.c

SUB_SRC	=	../maths/calc_percent.c	\
			../maths/init_randint.c	\
			../maths/randint.c

OBJ	=	$(SRC:.c=.o)

SUB_OBJ = $(SUB_SRC:.c=.o)

NAME	=	libmysprite.a

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