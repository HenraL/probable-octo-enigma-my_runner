/*
** EPITECH PROJECT, 2021
** runner - create.c
** File description:
** jitter jitter
*/

#include "../../include/my_event.h"
#include "../../include/my_lib.h"

void display_key_code(sfEvent event)
{
    if (event.key.type != 11 || event.key.type != 10) {
        my_putchar(event.key.code);
        my_putchar('=');
        my_put_nbr(event.key.type);
        my_putchar('\n');
    }
}