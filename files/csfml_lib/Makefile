##
## EPITECH PROJECT, 2025
## probable-octo-enigma-my_runner
## File description:
## Makefile
##


all:
	mkdir -p build
	cmake -S . -B build
	cmake --build build --target build-all -- -j$(shell nproc || echo 1)

clean:
	rm -rf build sfml_install install

fclean: clean
	rm -f SFML-2.5.1-sources.zip CSFML-2.5-sources.zip

.PHONY: all clean fclean
