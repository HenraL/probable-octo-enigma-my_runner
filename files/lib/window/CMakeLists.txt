add_library(mywindow STATIC
    createWindow.c
    create_framebuffer.c
    destroy_framebuffer.c
)

target_include_directories(mywindow PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(mywindow PUBLIC csfml-local)
