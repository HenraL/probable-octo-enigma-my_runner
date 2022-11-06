/*
** EPITECH PROJECT, 2021
** runner - get_sprite_name.c
** File description:
** jitter jitter
*/

#include "../../include/my_level.h"

char *get_sprite_name_overflow4(int sprite_id)
{
    char *name;
    if (sprite_id == 9) {
        name = "spike";
        return name;
    } else if (sprite_id == 10) {
        name = "spike_ball";
        return name;
    } else {
        return get_sprite_name_overflow1(sprite_id);
    }

}

char *get_sprite_name_overflow3(int sprite_id)
{
    char *name;
    if (sprite_id == 7) {
        name = "mine";
        return name;
    } else if (sprite_id == 8) {
        name = "rocket";
        return name;
    } else {
        return get_sprite_name_overflow1(sprite_id);
    }

}

char *get_sprite_name_overflow2(int sprite_id)
{
    char *name;
    if (sprite_id == 5) {
        name = "bomb";
        return name;
    } else if (sprite_id == 6) {
        name = "Frozen river";
        return name;
    } else {
        return get_sprite_name_overflow1(sprite_id);
    }

}

char *get_sprite_name_overflow1(int sprite_id)
{
    char *name;
    if (sprite_id == 3) {
        name = "platform";
        return name;
    } else if (sprite_id == 4) {
        name = "asteroid";
        return name;
    } else {
        return get_sprite_name_overflow1(sprite_id);
    }

}

char *get_sprite_name(int sprite_id)
{
    char *name;
    if (sprite_id == 1) {
        name = "ice_block";
        return name;
    } else if (sprite_id == 2) {
        name = "ice_cube_block";
        return name;
    } else {
        return get_sprite_name_overflow1(sprite_id);
    }
}