/*
** EPITECH PROJECT, 2021
** runner - free_matrix.c
** File description:
** jitter jitter
*/

#include "../../include/my_level.h"

void free_matrix(char **my_matrix)
{
    int i = 0;
    for (;my_matrix[i] != "EOT"; i++) {
        free(my_matrix[i]);
    }
    free(my_matrix);
}
