/*
** EPITECH PROJECT, 2021
** get_csfml_keys - is_smoothing_time.c
** File description:
** jitter jitter
*/

#include "../../include/my_silvers.h"

smoothing_tracker_t is_smoothing_time_overflow(smoothing_tracker_t is_it)
{
    if (is_it.smoother > 0 && is_it.smoother < 6) {
        is_it.global_speed++;
        is_it.smoother++;
    }
    if (is_it.smoother > 6 && is_it.smoother < 11) {
        is_it.global_speed++;
        is_it.smoother++;
    }
    return is_it;
}

smoothing_tracker_t is_smoothing_time(smoothing_tracker_t is_it,
                                      silver_states_t silvers, sprite_t p_sp)
{
    is_it.nb_loops++;
    if ((is_it.nb_loops / 1000) == 1) {
        p_sp.anim.max_ticks = 15;
        is_it.smoother += 1;
    }
    if ((is_it.nb_loops / 1000) == 2) {
        p_sp.anim.max_ticks = 5;
        is_it.smoother++;
    }
    if (is_it.smoother > 0 && is_it.smoother < 11) {
        is_it = is_smoothing_time_overflow(is_it);
        return is_it;
    }
    return is_it;
}

smoothing_tracker_t init_smoothing(silver_states_t silvers)
{
    smoothing_tracker_t is_it;
    is_it.smoother = 0;
    is_it.global_speed = 0;
    is_it.nb_loops = 0;
    is_it.silver = change_sprite(silvers, 1);
    return is_it;
}