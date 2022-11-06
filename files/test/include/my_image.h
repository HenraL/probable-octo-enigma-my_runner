/*
** EPITECH PROJECT, 2021
** runner - my_image.h
** File description:
** jitter jitter
*/

#ifndef MY_IMAGE_H_
#define MY_IMAGE_H_

#include <SFML/Graphics.h>
#include <SFML/Config.h>

typedef struct image_s
{
    char *path;
    int status;
    sfImage *image;
    sfTexture *texture;
} image_t;

typedef struct find_images_s {
    char *asteroid_path;
    char *bomb_path;
    char *river_path;
    char *spike_ball_path;
    char *button_path;
    char *background_image_path;
    char *path_image_path;
    char *ice_image_path;
    char *silver_s_path;
    char *silver_n_path;
    char *silver_f_path;
    char *end_sprite_won_path;
    char *end_sprite_lost_path;
    char *coins_path;
    char *rings_winter_path;
    char *rocket_path;
    char *spike_path;
    char *obstacle2_path;
    char *cloud_path;
} find_images_t;

find_images_t init_images(void);
image_t create_image(image_t image, unsigned int w, unsigned int h);
void display_image(sfRenderWindow *window, image_t image,
                   sfRenderStates *state);
void free_image(image_t iamge);



#endif