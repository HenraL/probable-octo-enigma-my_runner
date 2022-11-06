/*
** EPITECH PROJECT, 2021
** runner - init_buttons.c
** File description:
** jitter jitter
*/

#include "../../include/my_event.h"

buttons_t initialise_button(sprite_t butt1, sprite_t butt2, sprite_t butt3,
                            sprite_t butt4)
{
    buttons_t buttons;
    buttons.button1 = butt1;
    buttons.button2 = butt2;
    buttons.button3 = butt3;
    buttons.button4 = butt4;
    return buttons;
}