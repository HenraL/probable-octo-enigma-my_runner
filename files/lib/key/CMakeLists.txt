add_library(mykey STATIC
    display.c
    get.c
    initialise.c
    on_event.c
)

target_include_directories(mykey PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(mykey PUBLIC csfml-local)
