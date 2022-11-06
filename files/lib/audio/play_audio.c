/*
** EPITECH PROJECT, 2021
** runner - play_audio.c
** File description:
** jitter jitter
*/

#include "../../include/my_audio.h"

audio_status_t play_loaded_audio(audio_status_t audio)
{
    if (audio.playing == 0) {
        audio.playing = 1;
        audio.was_played++;
        sfSound_play(audio.my_sound);
    }
    return audio;
}