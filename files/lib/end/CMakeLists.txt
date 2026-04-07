add_library(myend STATIC
    free.c
    initialise.c
    which_ending.c
)

target_include_directories(myend PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
