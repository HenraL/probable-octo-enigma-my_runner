/*
** EPITECH PROJECT, 2021
** runner - init_background_overflow.c
** File description:
** jitter jitter
*/

#include "include/my_root.h"

init_bkgd_t init_bkgd_overflow(init_bkgd_t init_bkgd, find_images_t image_path)
{
    char *path4 = image_path.cloud_path;
    two_sprites_t cloud_sprites = load_two_sprite(path4, path4, 1, 1.4);
    cloud_sprites = init_two_dims(cloud_sprites, 94, 38);
    cloud_sprites = initialise_drag_axis(cloud_sprites, 0);
    cloud_sprites.s1_y = 300;
    cloud_sprites.s2_y = 300;
    init_bkgd.background4 = cloud_sprites;
    return init_bkgd;
}