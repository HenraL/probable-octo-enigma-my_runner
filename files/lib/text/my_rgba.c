/*
** EPITECH PROJECT, 2021
** get_csfml_keys (Workspace)
** File description:
** rgba.c
*/

#include "../../include/my_text.h"

sfColor my_rgba(sfUint8 r, sfUint8 g, sfUint8 b, sfUint8 a)
{
    sfColor my_colour;
    my_colour = sfColor_fromRGBA(r, g, b, a * 255);
    return my_colour;
}
