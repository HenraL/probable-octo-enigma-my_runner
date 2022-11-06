/*
** EPITECH PROJECT, 2021
** runner - load.c
** File description:
** jitter jitter
*/

#include "../../include/my_image.h"

image_t create_image(image_t image, unsigned int w, unsigned int h)
{
    image.texture = sfTexture_createFromFile(image.path, NULL);
    if (!image.texture) {
        image.status = 84;
    } else {
        image.image = sfImage_create(w, h);
        image.status = 0;
    }
    return image;
}