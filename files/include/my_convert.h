/*
** EPITECH PROJECT, 2021
** Bootstrap - libmy.h
** File description:
** jitter jitter
*/

#ifndef MY_CONVERT_H_
#define MY_CONVERT_H_

#include "my_lib.h"
#include <stdlib.h>

char char_to_int(char str);
char cti(char str);
char *nb_to_char_star(int nb);
char *ntcs(int nb);
char int_to_char(int nb);
char itct(int nb);

int char_star_to_nb(char *str);
int cstnb(char *str);
int char_star_to_int(char *digits);
int treat_program_and_speed(char *arg, int b, int default_return);
int *treat_pixels(char *arg, int b);
int char_to_nb(char *string);
int length_of_an_int(int nb);

#endif
