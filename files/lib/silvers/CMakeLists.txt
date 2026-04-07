add_library(mysilvers STATIC
    change_sprite.c
    free.c
    is_smoothing_time.c
    limit.c
    load.c
    set_frame_spec.c
)

target_include_directories(mysilvers PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
