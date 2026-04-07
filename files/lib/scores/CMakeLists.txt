add_library(myscores STATIC
    init.c
    refresh.c
    reset.c
)

target_include_directories(myscores PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
