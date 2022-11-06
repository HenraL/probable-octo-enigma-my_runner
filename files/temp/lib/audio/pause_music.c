/*
** EPITECH PROJECT, 2021
** runner - pause_music.c
** File description:
** jitter jitter
*/

#include "../../include/my_audio.h"

music_status_t pause_loaded_music(music_status_t music)
{
    if (music.playing == 1) {
        music.playing = 0;
        sfMusic_pause(music.music);
    }
    return music;
}