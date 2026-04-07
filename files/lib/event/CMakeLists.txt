add_library(myevents STATIC
    init_buttons.c
    initialise.c
    is_in_box.c
    on_event.c
    on_keydown.c
    on_keydown_2.c
)

target_include_directories(myevents PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
