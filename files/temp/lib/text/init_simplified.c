/*
** EPITECH PROJECT, 2021
** runner - init_simplified.c
** File description:
** jitter jitter
*/

#include "../../include/my_text.h"

text_t init_text_simp(char *text, int font_choice, sfColor color, float thick)
{
    text_t default_text = init_text(text, font_choice, 50);
    default_text = set_colors(default_text, color, rgba(0, 0, 0, 1));
    default_text = set_more_info(default_text, thick, 0, sfTextBold);
    return default_text;
}