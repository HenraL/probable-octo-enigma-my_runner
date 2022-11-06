/*
** EPITECH PROJECT, 2021
** runner (Workspace)
** File description:
** get.c
*/

#include "../../include/my_level.h"

int *get_level(char *path)
{
    my_putstr("in read it\n");
    char *my_content = my_get_content(path);
    my_putstr(my_content);
    my_putchar('\n');

}