/*
** EPITECH PROJECT, 2021
** runner - init.c
** File description:
** jitter jitter
*/

#include "../../include/my_image.h"

find_images_t init_images(void)
{
    find_images_t my_images;
    my_images.asteroid_path = "img/enemies/asteroid.png";
    my_images.bomb_path = "img/enemies/bomb.png";
    my_images.river_path = "img/enemies/frozen river.png";
    my_images.spike_ball_path = "img/enemies/spike_ball.png";
    my_images.button_path = "img/title_screen/button_sprite.png";
    my_images.background_image_path = "img/background/final_background.png";
    my_images.path_image_path = "img/background/path_final.png";
    my_images.ice_image_path = "img/background/ice_final.png";
    my_images.silver_s_path = "img/sprite/silver/silver_running_very_slow.png";
    my_images.silver_n_path = "img/sprite/silver/silver_running_slow.png";
    my_images.silver_f_path = "img/sprite/silver/silver_running_fast.png";
    my_images.end_sprite_won_path = "img/ending/eggman_end.png";
    my_images.end_sprite_lost_path = "img/ending/silver_loading.png";
    my_images.coins_path = "img/bonuses/blue ring_shrunk.png";
    my_images.rings_winter_path = "img/bonuses/coin_winter_spritesheet.png";
    my_images.rocket_path = "img/enemies/rk2.png";
    my_images.spike_path = "img/enemies/spike.png";
    my_images.obstacle2_path = "img/spike-ball.png";
    return my_images;
}