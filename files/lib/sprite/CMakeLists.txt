add_library(mysprite STATIC
    change_two_val.c
    create.c
    display.c
    draw_two.c
    dup_sprite.c
    free.c
    free_two.c
    init_anim.c
    initialise_drag_axis.c
    initialise_sffloatrect.c
    initialise_sfintrect.c
    is_coliding.c
    is_out_of_home.c
    is_reset_drag_needed.c
    is_reset_pos_needed.c
    load.c
    load_and_resize.c
    load_two.c
    moove.c
    move_sprite_with_struct.c
    move_two.c
    next_frame.c
    override.c
    randomise_position.c
    rescale.c
    rescale_by_percent.c
)

target_include_directories(mysprite PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
