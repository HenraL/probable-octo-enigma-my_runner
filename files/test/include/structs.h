/*
** EPITECH PROJECT, 2021
** my_runner - structs.h
** File description:
** jitter jitter
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>

#include <stdio.h>

#ifndef FRAMEBUFFERH
typedef struct s_framebuffer {
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
} framebuffer_t;

#endif
typedef struct sleepy {
    int microseconds;
    int milliseconds;
    int seconds;
    int minutes;
    int hours;
} sleepy;
typedef struct move_s {
    int up;
    int down;
    int left;
    int right;
    int center;
} move_t;
typedef struct track_time_s {
    int silver;
    int rings;
    int eggman;
    int rocket;
    int won;
    int lost;
    int asteroid;
    int bomb;
    int spike_ball;
    int current_play;
} track_time_t;

typedef struct max_s
{
    int w;
    int h;
} max_t;


#endif