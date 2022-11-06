/*
** EPITECH PROJECT, 2021
** runner - load_music.c
** File description:
** jitter jitter
*/

#include "../../include/my_audio.h"

music_status_t load_music(music_status_t music, int loop)
{
    music.music = sfMusic_createFromFile(music.path);
    if (loop == sfTrue) {
        sfMusic_setLoop(music.music, sfTrue);
    } else {
        sfMusic_setLoop(music.music, sfFalse);
    }
    if (!music.music) {
        music.status = 84;
    }
    music.playing = 0;
    music.status = 0;
    music.was_played = 0;
    return music;
}