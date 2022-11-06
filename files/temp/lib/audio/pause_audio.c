/*
** EPITECH PROJECT, 2021
** runner - pause_audio.c
** File description:
** jitter jitter
*/

#include "../../include/my_audio.h"

audio_status_t pause_loaded_audio(audio_status_t audio)
{
    if (audio.playing == 1) {
        audio.playing = 0;
        sfSound_pause(audio.my_sound);
    }
    return audio;
}