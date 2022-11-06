/*
** EPITECH PROJECT, 2021
** runner - translate.c
** File description:
** jitter jitter
*/

#include "../../include/my_level.h"

sprite_element_t translate_sprite_level(char **sprite_list)
{
    sprite_element_t my_sprite;
    my_sprite.id = char_star_to_nb(sprite_list[0]);
    my_sprite.clock = char_star_to_nb(sprite_list[1]);
    my_sprite.pos_y = char_star_to_nb(sprite_list[2]);
    my_sprite.type = get_sprite_type(my_sprite.id);
    my_sprite.name = get_sprite_name(my_sprite.id);
    free_matrix(sprite_list);
    return my_sprite;
}