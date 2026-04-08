/*
** EPITECH PROJECT, 2021
** my_runner - int_long_to_char_star.c
** File description:
** jitter jitter
*/

#include "../../include/my_convert.h"

char *nb_to_char_star_allocate(int nb)
{
    int len = length_of_an_int(nb);
    char *result = NULL;
    if (nb == 0) {
        len = 1;
    }
    result = malloc(sizeof(char) * (len + 1));
    return result;
}

char *nb_to_char_star(int nb)
{
    int i = 0;
    char *result = nb_to_char_star_allocate(nb);
    if (result == NULL) {
        return NULL;
    }

    if (nb > 0) {
        for (; nb != 0; i++) {
            result[i] = (nb % 10) + '0';
            nb = nb / 10;
        }
        result[i] = '\0';
    } else {
        result[0] = '0';
        result[1] = '\0';
    }
    result = my_revstr(result);
    return result;
}

char *ntcs(int nb)
{
    char *result;
    int i = 0;
    for (; nb != 0; i++) {
        result[i] = (nb % 10) + '0';
        nb = nb / 10;
    }
    result = my_revstr(result);
    return result;
}
