/*
** EPITECH PROJECT, 2021
** runner - is_reset_pos_needed.c
** File description:
** jitter jitter
*/

#include "../../include/my_sprite.h"

sprite_t is_res_pos_req(sprite_t default_sprite, int cond, int pos,
                        int x_or_y)
{
    if (x_or_y == 0) {
        if (default_sprite.d.x <= cond) {
            default_sprite.d.x = pos;
        }
    } else if (x_or_y == 1) {
        if (default_sprite.d.y >= cond) {
            default_sprite.d.y = pos;
        }
    } else {
        if (default_sprite.d.x <= cond) {
            default_sprite.d.x = pos;
        }
        if (default_sprite.d.y >= cond) {
            default_sprite.d.y = pos;
        }
    }
    default_sprite = move_sprite_with_struct(default_sprite);
    return default_sprite;
}