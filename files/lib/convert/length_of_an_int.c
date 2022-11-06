/*
** EPITECH PROJECT, 2021
** runner - length_of_an_int.c
** File description:
** jitter jitter
*/

#include "../../include/my_convert.h"

int length_of_an_int(int nb)
{
    int final_return = 0;
    if (nb < 0) {
        final_return++;
        nb *= -1;
    }
    for (;nb != 0;final_return++) {
        nb /= 10;
    }

    return final_return;
}