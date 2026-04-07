add_library(myaudio STATIC
    free_audio.c
    free_music.c
    load_audio.c
    load_music.c
    pause_audio.c
    pause_music.c
    play_as_sound.c
    play_audio.c
    play_music.c
    stop_music.c
)

target_include_directories(myaudio PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(myaudio PUBLIC
    csfml-audio
)
