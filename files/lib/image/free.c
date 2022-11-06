/*
** EPITECH PROJECT, 2021
** runner - display.c
** File description:
** jitter jitter
*/

#include "../../include/my_image.h"

void free_sprite(image_t image)
{
    sfImage_destroy(image.image);
    sfTexture_destroy(image.texture);
}