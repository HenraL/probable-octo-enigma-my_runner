/*
** EPITECH PROJECT, 2021
** runner - init_title_simplified.c
** File description:
** jitter jitter
*/

#include "../../include/my_text.h"

text_t init_title_simp(char *text, int font_choice, sfVector2i pos,
                       sfUint32 style)
{
    text_t default_text = init_text(text, font_choice, 100);
    default_text = set_colors(default_text, rgba(192, 192, 192, 1),
                              rgba(211, 211, 211, 1));
    default_text = set_more_info(default_text, 10, 0, style);
    default_text = text_positioning(default_text, pos.x, pos.y, 2.0);
    return default_text;
}