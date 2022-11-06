/*
** EPITECH PROJECT, 2021
** runner - animation_tracking.c
** File description:
** jitter jitter
*/

#include "../../include/my_text.h"

text_t is_moving_needed(text_t my_text, int max, int step)
{
    if (my_text.x < max) {
        my_text.x += 2;
    }
    return my_text;
}