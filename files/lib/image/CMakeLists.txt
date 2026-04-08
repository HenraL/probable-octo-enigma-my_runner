add_library(myimage STATIC
    display.c
    free.c
    init.c
    load.c
)

target_include_directories(myimage PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(myimage PUBLIC csfml-local)
