add_library(mypixel STATIC
    add_pixel.c
    append_pixel_to_array.c
    create_pixel_array.c
    destroy_pixel_array.c
)

target_include_directories(mypixel PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(mypixel PUBLIC csfml-local)
