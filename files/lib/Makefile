##
## EPITECH PROJECT, 2021
## my_runner - Makefile
## File description:
## jitter jitter
##

SRC	=	test2.c

LIB	=	-L my/ -lmy	\
		-L dict/ -lmydict	\
		-L convert -lmyconvert	\
		-L window -lmywindow	\
		-L maths -lmymaths	\
		-L help -lmyhelp	\
		-L audio -lmyaudio	\
		-L sprite -lmysprite	\
		-L event -lmyevents


OBJ	=	$(SRC:.c=.o)

NAME	=	test.out
all:	$(NAME)
$(NAME):	$(OBJ)
	$(MAKE) -C audio CPPFLAGS="$(CPPFLAGS)"  LDFLAGS="$(LDFLAGS)" LDLIBS="$(LDLIBS)"
	$(MAKE) -C convert CPPFLAGS="$(CPPFLAGS)"  LDFLAGS="$(LDFLAGS)" LDLIBS="$(LDLIBS)"
	$(MAKE) -C dict CPPFLAGS="$(CPPFLAGS)"  LDFLAGS="$(LDFLAGS)" LDLIBS="$(LDLIBS)"
	$(MAKE) -C event CPPFLAGS="$(CPPFLAGS)"  LDFLAGS="$(LDFLAGS)" LDLIBS="$(LDLIBS)"
	$(MAKE) -C maths CPPFLAGS="$(CPPFLAGS)"  LDFLAGS="$(LDFLAGS)" LDLIBS="$(LDLIBS)"
	$(MAKE) -C help CPPFLAGS="$(CPPFLAGS)"  LDFLAGS="$(LDFLAGS)" LDLIBS="$(LDLIBS)"
	$(MAKE) -C my CPPFLAGS="$(CPPFLAGS)"  LDFLAGS="$(LDFLAGS)" LDLIBS="$(LDLIBS)"
	$(MAKE) -C sprite CPPFLAGS="$(CPPFLAGS)"  LDFLAGS="$(LDFLAGS)" LDLIBS="$(LDLIBS)"
	$(MAKE) -C window CPPFLAGS="$(CPPFLAGS)"  LDFLAGS="$(LDFLAGS)" LDLIBS="$(LDLIBS)"
	gcc $(SRC) -o $(NAME) -lcsfml-graphics -lcsfml-system -lcsfml-audio $(LIB)

clean:
	rm -f $(OBJ)
	$(MAKE) -C audio clean
	$(MAKE) -C convert clean
	$(MAKE) -C dict clean
	$(MAKE) -C event clean
	$(MAKE) -C maths clean
	$(MAKE) -C help clean
	$(MAKE) -C my clean
	$(MAKE) -C sprite clean
	$(MAKE) -C window clean
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C audio fclean
	$(MAKE) -C convert fclean
	$(MAKE) -C dict fclean
	$(MAKE) -C event fclean
	$(MAKE) -C help fclean
	$(MAKE) -C maths fclean
	$(MAKE) -C my fclean
	$(MAKE) -C sprite fclean
	$(MAKE) -C window fclean


re:	fclean all

auteur:
	echo $(USER) > auteur
