/*
** EPITECH PROJECT, 2021
** my_runner - my_root.h
** File description:
** jitter jitter
*/

#ifndef MY_ROOT_H_
#define MY_ROOT_H_

#include "my_audio.h"
#include "structs.h"
#include "my_sprite.h"
#include "my_image.h"
#include "my_lib.h"

typedef struct init_bkgd_s {
    two_sprites_t background1;
    two_sprites_t background2;
    two_sprites_t background3;
    two_sprites_t background4;
    int status;
} init_bkgd_t;

typedef struct my_music_s
{
    music_status_t m1;
    music_status_t m2;
    music_status_t m3;
    music_status_t s1;
} my_music_t;



void show_howto(void);
void show_credits(void);
void show_credits_overflow(void);
void if_none(void);
void show_help(char **argv);
int launch_game(void);
init_bkgd_t init_backgrounds(find_images_t image_path);
two_sprites_t init_two_width(two_sprites_t default_sprites, int w, int h);
init_bkgd_t assign_bkgd(init_bkgd_t init_bkgd, two_sprites_t bkgd1,
                        two_sprites_t bkgd2, two_sprites_t bkgd3);
int initialisation_failed(two_sprites_t sp1, two_sprites_t sp2,
                          two_sprites_t sp3);
two_sprites_t init_ice(two_sprites_t ice_sprites);
two_sprites_t init_path(two_sprites_t path_sprites);
track_time_t init_time(int nb);
two_sprites_t init_two_dims(two_sprites_t default_sprites, int w, int h);
my_music_t load_all_music(void);
max_t init_window_size(int w, int h);
init_bkgd_t init_bkgd_overflow(init_bkgd_t init_bkgd, find_images_t image_path);


#endif