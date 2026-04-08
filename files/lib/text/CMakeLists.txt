add_library(mytext STATIC
    animation_tracking.c
    free.c
    init.c
    init_4_vals.c
    init_description_simplified.c
    init_simplified.c
    init_title_simplified.c
    move.c
    move_from_struct_coordinates.c
    positioning.c
    rgba.c
    set_colors.c
    set_more_info.c
    update.c
)

target_include_directories(mytext PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(mytext PUBLIC csfml-graphics csfml-local)
