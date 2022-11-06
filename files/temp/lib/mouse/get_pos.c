/*
** EPITECH PROJECT, 2021
** runner - get_pos.c
** File description:
** jitter jitter
*/

#include "../../include/my_mouse.h"

mouse_trac_t get_pos(sfEvent event, mouse_trac_t mouse_sprite)
{
    mouse_sprite.pos_x = event.mouseMove.x;
    mouse_sprite.pos_y = event.mouseMove.y;
    return mouse_sprite;
}