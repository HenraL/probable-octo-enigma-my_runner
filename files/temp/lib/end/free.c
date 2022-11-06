/*
** EPITECH PROJECT, 2021
** runner - free.c
** File description:
** jitter jitter
*/

#include "../../include/my_end.h"

void free_end(end_values_t end)
{
    free_text(end.main_menu_text1);
    free_text(end.main_menu_text2);
    free_text(end.restart_text1);
    free_text(end.restart_text2);
    free_sprite(end.button_restart);
    free_sprite(end.sprite_lost);
    free_sprite(end.sprite_won);
}