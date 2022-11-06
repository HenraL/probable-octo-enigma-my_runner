##
## EPITECH PROJECT, 2021
## Bootstrap - Makefile
## File description:
## jitter jitter
##

SRC	=	my_runner.c	\
		option_dealing.c	\
		how_to_play.c	\
		show_credits.c	\
		title.c	\
		next_frame_full.c	\
		init_backgrounds.c	\
		init_background_overflow.c	\
		init_time.c	\
		init_window.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_runner

LIB	=	-L lib/audio -lmyaudio	\
		-L lib/my/ -lmy	\
		-L lib/sprite -lmysprite	\
		-L lib/mouse -lmymouse	\
		-L lib/window -lmywindow	\
		-L lib/event -lmyevents	\
		-L lib/silvers -lmysilvers	\
		-L lib/text -lmytext	\
		-L lib/end -lmyend	\
		-L lib/convert -lmyconvert	\
		-L lib/game_assets -lmyassets	\
		-L lib/scores -lmyscores	\
		-L lib/image -lmyimage	\
		-L lib/level -lmylevel

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/audio
	make -C lib/event
	make -C lib/my
	make -C lib/window
	make -C lib/sprite
	make -C lib/mouse
	make -C lib/silvers
	make -C lib/text
	make -C lib/end
	make -C lib/convert
	make -C lib/game_assets
	make -C lib/scores
	make -C lib/image
	make -C lib/level
	gcc -g $(SRC) -o $(NAME) -lcsfml-graphics -lcsfml-system -lcsfml-audio $(LIB) -g3

clean:
	rm -f $(OBJ)
	make -C lib/audio clean
	make -C lib/event clean
	make -C lib/my clean
	make -C lib/window clean
	make -C lib/sprite clean
	make -C lib/mouse clean
	make -C lib/silvers clean
	make -C lib/text clean
	make -C lib/end clean
	make -C lib/convert clean
	make -C lib/game_assets clean
	make -C lib/scores clean
	make -C lib/image clean
	make -C lib/level clean

fclean: clean
	rm -f $(NAME)
	make -C lib/audio fclean
	make -C lib/event fclean
	make -C lib/my fclean
	make -C lib/window fclean
	make -C lib/sprite fclean
	make -C lib/mouse fclean
	make -C lib/silvers fclean
	make -C lib/text fclean
	make -C lib/end fclean
	make -C lib/convert fclean
	make -C lib/game_assets fclean
	make -C lib/scores fclean
	make -C lib/image fclean
	make -C lib/level fclean

re:	fclean all

auteur:
	echo $(USER) > auteur