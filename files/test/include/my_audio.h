/*
** EPITECH PROJECT, 2021
** runner (Workspace)
** File description:
** my_audio.h
*/

#ifndef MY_AUDIO_
#define MY_AUDIO_

#include <SFML/Audio.h>
#include <stdlib.h>
#include "my_lib.h"
typedef struct music_status_s
{
    char *path;
    sfMusic *music;
    int status;
    int playing;
    int was_played;
} music_status_t;

typedef struct audio_status_s
{
    const char *path;
    sfSoundBuffer *my_soundbuffer;
    sfSound *my_sound;
    int load_status;
    int playing;
    int was_played;
} audio_status_t;


music_status_t load_music(music_status_t music, int loop);
music_status_t play_loaded_music(music_status_t music);
music_status_t play_as_sound(music_status_t music);
music_status_t pause_loaded_music(music_status_t music);
music_status_t stop_loaded_music(music_status_t music);
void free_music(music_status_t music);

audio_status_t load_audio(audio_status_t audio);
audio_status_t play_loaded_audio(audio_status_t audio);
audio_status_t pause_loaded_audio(audio_status_t audio);
void free_audio(audio_status_t audio);

#endif