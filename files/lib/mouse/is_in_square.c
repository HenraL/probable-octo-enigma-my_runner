/*
** EPITECH PROJECT, 2021
** runner - is_in_square.c
** File description:
** jitter jitter
*/

#include "../../include/my_mouse.h"

int is_mouse_in_square(mouse_trac_t mouse, sprite_t default_sprite)
{
    int is_x = sfFalse;
    int is_y = sfFalse;
    if (mouse.pos_x > default_sprite.d.x &&
        mouse.pos_x < (default_sprite.d.x + default_sprite.d.w)) {
        is_x = sfTrue;
    }
    if (mouse.pos_y > default_sprite.d.y &&
        mouse.pos_y < (default_sprite.d.y + default_sprite.d.h)) {
        is_y = sfTrue;
    }
    if (is_x == sfTrue && is_y == sfTrue) {
        return sfTrue;
    }
    return sfFalse;
}