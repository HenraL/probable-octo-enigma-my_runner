/*
** EPITECH PROJECT, 2021
** my_runner - create_framebuffer.c
** File description:
** abx
*/

#include "../../include/framebuffer.h"
#include "../../include/my_window.h"

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *framebuffer = malloc(sizeof(framebuffer_t));

    framebuffer->width = width;
    framebuffer->height = height;
    framebuffer->pixels = malloc(width * height * 32 / 8);
    return (framebuffer);
}