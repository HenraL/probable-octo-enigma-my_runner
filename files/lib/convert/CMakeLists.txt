add_library(myconvert STATIC
    char_star_to_nb.c
    char_to_int.c
    char_to_nb.c
    hex_to_255.c
    int_to_char.c
    length_of_an_int.c
    my_get_args_for_prog.c
    nb_to_char_star.c
)

target_include_directories(myconvert PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(myconvert PUBLIC
    my
)
