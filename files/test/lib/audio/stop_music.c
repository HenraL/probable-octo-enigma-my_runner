/*
** EPITECH PROJECT, 2021
** runner - stop_music.c
** File description:
** jitter jitter
*/


#include "../../include/my_audio.h"

music_status_t stop_loaded_music(music_status_t music)
{
    if (music.playing == 1) {
        music.playing = 0;
        sfMusic_stop(music.music);
    }
    return music;
}