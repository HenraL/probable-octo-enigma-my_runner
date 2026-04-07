add_library(mydict STATIC
    append.c
    create.c
    del_item.c
    free.c
    get_value.c
)

target_include_directories(mydict PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
