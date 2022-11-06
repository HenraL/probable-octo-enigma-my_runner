/*
** EPITECH PROJECT, 2021
** runner - play_as_sound.c
** File description:
** jitter jitter
*/

#include "../../include/my_audio.h"

music_status_t play_as_sound(music_status_t music)
{
    if (music.playing == 0) {
        sfTime m_offset;
        music.playing = 0;
        music.was_played++;
        m_offset = sfMusic_getPlayingOffset(music.music);
        m_offset.microseconds = m_offset.microseconds - m_offset.microseconds;
        sfMusic_setPlayingOffset(music.music, m_offset);
        sfMusic_play(music.music);
    }
    return music;
}