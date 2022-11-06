/*
** EPITECH PROJECT, 2021
** runner - test.c
** File description:
** jitter jitter
*/

#include "../../include/my_level.h"

void main(void)
{
    printf("In main\n");
    char **my_level = get_level("../../level/level1.runner");
    my_putstr("Content res=ceived\n");
    my_putstr("Going to display file content.\n");
    printf("my_level = %s", my_level);

}