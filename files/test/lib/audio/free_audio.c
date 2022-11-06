/*
** EPITECH PROJECT, 2021
** runner - free_audio.c
** File description:
** jitter jitter
*/

#include "../../include/my_audio.h"

void free_audio(audio_status_t audio)
{
    sfSound_destroy(audio.my_sound);
    sfSoundBuffer_destroy(audio.my_soundbuffer);
}