add_library(mymaths STATIC
    calc_percent.c
    exponential.c
    init_randint.c
    randint.c
    sleep.c
)

target_include_directories(mymaths PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
