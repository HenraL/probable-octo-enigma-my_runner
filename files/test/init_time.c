/*
** EPITECH PROJECT, 2021
** runner - init_time.c
** File description:
** jitter jitter
*/

#include "include/structs.h"

track_time_t init_time(int nb)
{
    track_time_t time;
    time.silver = nb;
    time.rings = nb;
    time.asteroid = nb;
    time.bomb = nb;
    time.eggman = nb;
    time.lost = nb;
    time.rocket = nb;
    time.spike_ball = nb;
    time.won = nb;
    return time;
}