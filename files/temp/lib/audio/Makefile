##
## EPITECH PROJECT, 2021
## my_runner - Makefile
## File description:
## jitter jitter
##

SRC	=	load_music.c	\
		load_audio.c	\
		play_music.c	\
		play_audio.c	\
		play_as_sound.c	\
		pause_music.c	\
		pause_audio.c	\
		stop_music.c	\
		free_music.c	\
		free_audio.c


OBJ	=	$(SRC:.c=.o)

NAME	=	libmyaudio.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)


clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

auteur:
	echo $(USER) > auteur