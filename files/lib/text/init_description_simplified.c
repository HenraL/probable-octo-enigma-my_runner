/*
** EPITECH PROJECT, 2021
** runner - init_description_simplified.c
** File description:
** jitter jitter
*/

#include "../../include/my_text.h"

text_t init_desc_simp(char *text, int font_choice, int font_size,
                      sfVector2i pos)
{
    text_t default_text = init_text(text, font_choice, font_size);
    default_text = set_colors(default_text, rgba(250, 255, 255, 1),
                              rgba(0, 155, 255, 1));
    default_text = set_more_info(default_text, 3.5, 0, sfTextBold);
    default_text = text_positioning(default_text, pos.x, pos.y, 0);
    return default_text;
}