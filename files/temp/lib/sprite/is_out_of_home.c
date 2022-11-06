/*
** EPITECH PROJECT, 2021
** runner - is_out_of_home.c
** File description:
** jitter jitter
*/

#include "../../include/my_sprite.h"

sprite_t is_out_of_home_overflow(sprite_t default_sprite, int reset_step)
{
    if (default_sprite.d.y < default_sprite.home_position.y -
        (default_sprite.y_step / 2)) {
        default_sprite.d.y += reset_step;
    }
    return default_sprite;
}

sprite_t is_out_of_home(sprite_t default_sprite, int reset_step)
{
    if (default_sprite.d.x > default_sprite.home_position.x + 1920) {
        default_sprite.d.x += (reset_step * -1);
    }
    if (default_sprite.d.x < default_sprite.home_position.x -
        (default_sprite.x_step / 2)) {
        default_sprite.d.x += reset_step;
    }
    if (default_sprite.d.y > default_sprite.home_position.y + 130) {
        default_sprite.d.y += (reset_step * -1);
    }
    default_sprite = is_out_of_home_overflow(default_sprite, reset_step);
    return default_sprite;
}
