/*
** EPITECH PROJECT, 2021
** runner (Workspace)
** File description:
** get.c
*/

#include "../../include/my_level.h"

lst_inf_t get_level(char *path)
{
    my_putstr("in read it\n");
    char *my_content = my_get_content(path);
    lst_inf_t level_list = treat_level(my_content);
    my_putstr("out of reading\n");
    return level_list;
}