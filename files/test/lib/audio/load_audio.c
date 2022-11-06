/*
** EPITECH PROJECT, 2021
** runner - load_audio.c
** File description:
** jitter jitter
*/

#include "../../include/my_audio.h"

audio_status_t load_audio(audio_status_t audio)
{
    sfSoundBuffer *my_soundbuffer;
    my_putstr("Soudbuffer created\n");
    sfSound *my_sound;
    my_putstr("sfSound created\n");
    my_soundbuffer = sfSoundBuffer_createFromFile(audio.path);
    my_putstr("file loaded into soundbuffer\n");
    sfSound_setBuffer(my_sound, (const sfSoundBuffer *)my_soundbuffer);
    my_putstr("soundbuffer set in sound\n");
    audio.my_soundbuffer = my_soundbuffer;
    my_putstr("soundbuffer assigned to struct\n");
    audio.my_sound = my_sound;
    my_putstr("my_sound assigned to struct\n");
    audio.playing = 0;
    my_putstr("playing struct var initialised.\n");
    audio.load_status = 0;
    my_putstr("load_status struct var initialised.\n");
    audio.was_played = 0;
    my_putstr("was_player struct var initialised.\n");
    return audio;
}