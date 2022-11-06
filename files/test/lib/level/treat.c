/*
** EPITECH PROJECT, 2021
** runner - treat.c
** File description:
** jitter jitter
*/

#include "../../include/my_level.h"

lst_inf_t treat_level(char *file_content)
{
    lst_inf_t lst_inf;
    lst_inf.length = my_strlen(file_content);
    lst_inf.lst = malloc(sizeof(int) * lst_inf.length);
    my_putstr("content length = ");
    my_put_nbr(my_strlen(file_content));
    my_putchar('\n');
    int i = 0;
    char *temp = "";
    int list_tracker = 0;
    for (;file_content[i] != '\0'; i++) {
        my_putstr("file_content = ");
        my_putchar(file_content[i]);
        my_putchar('\n');
        if (file_content[i] == ',') {
            lst_inf.lst[list_tracker] = char_star_to_int(temp);
            temp = "";
            list_tracker++;
        } else {
            temp += file_content[i];
        }
    }
    free(file_content);
    i = 0;
    for (;i < lst_inf.length; i++) {
        my_putstr(nb_to_char_star(lst_inf.lst[i]));
        my_putchar('\n');
    }
    return lst_inf;
}
