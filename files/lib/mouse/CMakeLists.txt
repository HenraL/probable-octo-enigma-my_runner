add_library(mymouse STATIC
    analyse.c
    get_pos.c
    hide.c
    init.c
    is_in_square.c
    show.c
    update_pos.c
)

target_include_directories(mymouse PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
