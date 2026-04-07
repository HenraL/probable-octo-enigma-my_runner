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

CSFML_DIR := $(CURDIR)/csfml_lib/

CSFML_DIST_DIR := $(CSFML_DIR)/build/install

CPPFLAGS += -isystem$(CSFML_DIST_DIR)/csfml/include -isystem$(CSFML_DIST_DIR)/sfml/include

LDFLAGS += -L$(CSFML_DIST_DIR)/csfml/lib -L$(CSFML_DIST_DIR)/sfml/lib
LDLIBS += -lcsfml-graphics -lcsfml-system -lcsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

export CPPFLAGS LDFLAGS LDLIBS

LIB	= 	-L lib/audio -lmyaudio	\
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

build_csfml:
	$(MAKE) -C $(CSFML_DIR)

$(OBJ): build_csfml

$(NAME):	$(OBJ)
	$(MAKE) -C lib/audio CPPFLAGS="$(CPPFLAGS)" LDFLAGS="$(LDFLAGS)" LDLIBS="$(LDLIBS)"
	$(MAKE) -C lib/event CPPFLAGS="$(CPPFLAGS)" LDFLAGS="$(LDFLAGS)" LDLIBS="$(LDLIBS)"
	$(MAKE) -C lib/my CPPFLAGS="$(CPPFLAGS)" LDFLAGS="$(LDFLAGS)" LDLIBS="$(LDLIBS)"
	$(MAKE) -C lib/window CPPFLAGS="$(CPPFLAGS)" LDFLAGS="$(LDFLAGS)" LDLIBS="$(LDLIBS)"
	$(MAKE) -C lib/sprite CPPFLAGS="$(CPPFLAGS)" LDFLAGS="$(LDFLAGS)" LDLIBS="$(LDLIBS)"
	$(MAKE) -C lib/mouse CPPFLAGS="$(CPPFLAGS)" LDFLAGS="$(LDFLAGS)" LDLIBS="$(LDLIBS)"
	$(MAKE) -C lib/silvers CPPFLAGS="$(CPPFLAGS)" LDFLAGS="$(LDFLAGS)" LDLIBS="$(LDLIBS)"
	$(MAKE) -C lib/text CPPFLAGS="$(CPPFLAGS)" LDFLAGS="$(LDFLAGS)" LDLIBS="$(LDLIBS)"
	$(MAKE) -C lib/end CPPFLAGS="$(CPPFLAGS)" LDFLAGS="$(LDFLAGS)" LDLIBS="$(LDLIBS)"
	$(MAKE) -C lib/convert CPPFLAGS="$(CPPFLAGS)" LDFLAGS="$(LDFLAGS)" LDLIBS="$(LDLIBS)"
	$(MAKE) -C lib/game_assets CPPFLAGS="$(CPPFLAGS)" LDFLAGS="$(LDFLAGS)" LDLIBS="$(LDLIBS)"
	$(MAKE) -C lib/scores CPPFLAGS="$(CPPFLAGS)" LDFLAGS="$(LDFLAGS)" LDLIBS="$(LDLIBS)"
	$(MAKE) -C lib/image CPPFLAGS="$(CPPFLAGS)" LDFLAGS="$(LDFLAGS)" LDLIBS="$(LDLIBS)"
	$(MAKE) -C lib/level CPPFLAGS="$(CPPFLAGS)" LDFLAGS="$(LDFLAGS)" LDLIBS="$(LDLIBS)"
	$(CXX) $(OBJ) -o $(NAME) $(CPPFLAGS) -Wl,--start-group $(LIB) $(LDFLAGS) $(LDLIBS) -Wl,--end-group $(SYS_LIBS) -g3

run: $(NAME)
	@read -p "Program args (optional): " ARGS; \
	LDPRE=""; \
	for f in $(CSFML_DIST_DIR)/csfml/lib/*.so $(CSFML_DIST_DIR)/sfml/lib/*.so; do \
		[ -f "$$f" ] || continue; \
		if [ "$$LDPRE" = "" ]; then LDPRE="$$f"; else LDPRE="$$LDPRE:$$f"; fi; \
	done; \
	if [ "$$LDPRE" != "" ]; then export LD_PRELOAD="$$LDPRE"; fi; \
	echo "Running: LD_PRELOAD=$$LD_PRELOAD ./$(NAME) $$ARGS"; \
	LD_PRELOAD="$$LDPRE" ./$(NAME) $$ARGS


clean:
	rm -f $(OBJ)
	$(MAKE) -C $(CSFML_DIR) clean
	$(MAKE) -C lib/audio clean
	$(MAKE) -C lib/event clean
	$(MAKE) -C lib/my clean
	$(MAKE) -C lib/window clean
	$(MAKE) -C lib/sprite clean
	$(MAKE) -C lib/mouse clean
	$(MAKE) -C lib/silvers clean
	$(MAKE) -C lib/text clean
	$(MAKE) -C lib/end clean
	$(MAKE) -C lib/convert clean
	$(MAKE) -C lib/game_assets clean
	$(MAKE) -C lib/scores clean
	$(MAKE) -C lib/image clean
	$(MAKE) -C lib/level clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(CSFML_DIR) fclean
	$(MAKE) -C lib/audio fclean
	$(MAKE) -C lib/event fclean
	$(MAKE) -C lib/my fclean
	$(MAKE) -C lib/window fclean
	$(MAKE) -C lib/sprite fclean
	$(MAKE) -C lib/mouse fclean
	$(MAKE) -C lib/silvers fclean
	$(MAKE) -C lib/text fclean
	$(MAKE) -C lib/end fclean
	$(MAKE) -C lib/convert fclean
	$(MAKE) -C lib/game_assets fclean
	$(MAKE) -C lib/scores fclean
	$(MAKE) -C lib/image fclean
	$(MAKE) -C lib/level fclean

re:	fclean all

auteur:
	echo $(USER) > auteur

.PHONY: all build_csfml clean fclean re auteur run
