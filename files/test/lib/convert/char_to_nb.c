/*
** EPITECH PROJECT, 2021
** runner - char_to_nb.c
** File description:
**
*/

#include "../../include/my_lib.h"

int char_to_nb(char *string)
{
    int nb = 0;
    int length = my_strlen(string) - 1;
    int exp = 1;
    int j = 0;
    if (string[0] == '-') {
        string[0] = '0';
        j = 1;
    }
    for (; string[length] != '\0' && exp != 1000000000; length--) {
        nb = nb + (string[length] - '0') * exp;
        exp = exp * 10;
    }
    if (j == 1) {
        nb = nb * (-1);
    }
    return nb;
}