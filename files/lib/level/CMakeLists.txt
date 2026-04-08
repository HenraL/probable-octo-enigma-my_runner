add_library(mylevel STATIC
    free_matrix.c
    get.c
    treat.c
)

target_include_directories(mylevel PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(mylevel PUBLIC my)
