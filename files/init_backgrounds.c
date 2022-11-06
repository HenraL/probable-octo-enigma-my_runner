/*
** EPITECH PROJECT, 2021
** runner - init_backgrounds.c
** File description:
** jitter jitter
*/

#include "include/my_root.h"

two_sprites_t init_two_dims(two_sprites_t default_sprites, int w, int h)
{
    default_sprites.sprite_widths = w;
    default_sprites.sprite_heights = h;
    default_sprites = initialise_drag_axis(default_sprites, 0);
    return default_sprites;
}

init_bkgd_t assign_bkgd(init_bkgd_t init_bkgd, two_sprites_t bkgd1,
                        two_sprites_t bkgd2, two_sprites_t bkgd3)
{
    init_bkgd.background1 = bkgd1;
    init_bkgd.background2 = bkgd2;
    init_bkgd.background3 = bkgd3;
    init_bkgd.status = 0;
    return init_bkgd;
}

two_sprites_t init_ice(two_sprites_t ice_sprites)
{
    ice_sprites.s1_y = 900;
    ice_sprites.s2_x = ice_sprites.sprite_widths;
    ice_sprites.s2_y = 900;
    return ice_sprites;
}

two_sprites_t init_path(two_sprites_t path_sprites)
{
    path_sprites.indent_level = 500 + 132;
    path_sprites.s1_y = path_sprites.indent_level;
    path_sprites.s2_x = path_sprites.sprite_widths;
    path_sprites.s2_y = path_sprites.indent_level;
    return path_sprites;
}

init_bkgd_t init_backgrounds(find_images_t image_path)
{
    init_bkgd_t init_bkgd;
    char *path1 = image_path.background_image_path;
    char *path2 = image_path.path_image_path;
    char *path3 = image_path.ice_image_path;
    two_sprites_t bkgd_sprites = load_two_sprite(path1, path1, 1, 0.9);
    two_sprites_t path_sprites = load_two_sprite(path2, path2, 1, 1.1);//"img/background/111111.jpeg"
    two_sprites_t ice_sprites = load_two_sprite(path3, path3, 1, 1.4);
    bkgd_sprites = init_two_dims(bkgd_sprites, 3642, 702);
    path_sprites = init_two_dims(path_sprites, 1920, 219);
    ice_sprites = init_two_dims(ice_sprites, 1920, 217);
    bkgd_sprites = initialise_drag_axis(bkgd_sprites, 0);
    path_sprites = initialise_drag_axis(path_sprites, 0);
    ice_sprites = initialise_drag_axis(ice_sprites, 0);
    bkgd_sprites.s2_x = bkgd_sprites.sprite_widths;
    path_sprites = init_path(path_sprites);
    ice_sprites.indent_level = path_sprites.indent_level + 277;
    ice_sprites = init_ice(ice_sprites);
    init_bkgd = assign_bkgd(init_bkgd, bkgd_sprites, path_sprites, ice_sprites);
    init_bkgd = init_bkgd_overflow(init_bkgd, image_path);
    return init_bkgd;
}