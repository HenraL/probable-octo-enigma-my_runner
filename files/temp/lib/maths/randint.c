/*
** EPITECH PROJECT, 2021
** runner - randint.c
** File description:
** jitter jitter
*/

#include "../../include/my_maths.h"

int randint(int lower, int upper, int count)
{
    int i = 0;
    int num = 0;
    for (; i < count; i++) {
        num = (rand() % (upper - lower + 1)) + lower;
    }
    return num;
}