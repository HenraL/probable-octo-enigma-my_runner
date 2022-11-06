/*
** EPITECH PROJECT, 2021
** runner (Workspace)
** File description:
** get_sprite_type.c
*/

#include "../../include/my_level.h"

int get_sprite_type(int sprite_id)
{
    if (sprite_id > 0 && sprite_id < 4) {
        return 0;
    } else {
        return 1;
    }
}
