/*
** EPITECH PROJECT, 2021
** runner - randomise_position.c
** File description:
** jitter jitter
*/

#include "../../include/my_sprite.h"

sprite_t randomise_sprite_pos_y(sprite_t default_sprite, int min_y, int max_y)
{
    default_sprite.d.y = randint(min_y, max_y, 1);
    return default_sprite;
}

sprite_t randomise_sprite_pos_x(sprite_t default_sprite, int min_x, int max_x)
{
    default_sprite.d.x = randint(min_x, max_x, 1);
    return default_sprite;
}