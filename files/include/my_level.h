/*
** EPITECH PROJECT, 2021
** runner - my_level.h
** File description:
** jitter jitter
*/

#ifndef MY_LEVEL_H_
#define MY_LEVEL_H_

#include <stdio.h>
#include <stdlib.h>
#include "my_lib.h"
#include "my_convert.h"
#include "my_maths.h"

typedef struct sprite_element_s
{
    int id;
    int clock;
    int pos_y;
    char *name;
    int type;
} sprite_element_t;

typedef struct lst_inf_s
{
    int *lst;
    int length;
} lst_inf_t;


lst_inf_t get_level(char *path);
lst_inf_t treat_level(char *file_content);
void free_matrix(char **my_matrix);

#endif