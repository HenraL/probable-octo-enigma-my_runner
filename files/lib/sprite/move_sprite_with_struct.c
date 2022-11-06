/*
** EPITECH PROJECT, 2021
** get_csfml_keys (Workspace)
** File description:
** move_sprite_from_s_coordinates.c
*/

#include "../../include/my_sprite.h"

sprite_t move_sprite_with_struct(sprite_t default_sprite)
{
    default_sprite = move_sprite(default_sprite, default_sprite.d.x,
                                 default_sprite.d.y);
    return default_sprite;
}