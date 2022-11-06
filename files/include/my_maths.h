/*
** EPITECH PROJECT, 2021
** my_runner - maths.h
** File description:
** jitter jitter
*/


#ifndef MY_MATHS_H_
#define MY_MATHS_H_

#include <time.h>
#include <stdlib.h>

#ifndef ABS
#define ABS(N) ((N<0)?(-N):(N))
#endif

int exponential(int nb, int n);
void my_sleep(unsigned int time);
void my_fsleep(char *tIme);
float calc_percent(float factor, float nb, int up_or_down);
void init_randint(void);
int randint(int lower, int upper, int count);

#endif