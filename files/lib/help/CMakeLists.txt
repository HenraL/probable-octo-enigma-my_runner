add_library(myhelp STATIC
    display_help.c
    help_in_general.c
    help_prog_options.c
    help_rgba.c
    help_speed.c
)

target_include_directories(myhelp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
