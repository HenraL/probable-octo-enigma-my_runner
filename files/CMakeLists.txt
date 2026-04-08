cmake_minimum_required(VERSION 3.10)

project(MyRunner C)

set(CMAKE_C_STANDARD 99)

if(UNIX) 
    message(STATUS "CSFML requires the following dependencies: libxrandr-dev  libxcursor-dev libxi-dev libudev-dev libfreetype-dev libflac-dev libvorbis-dev libgl1-mesa-dev libegl1-mesa-dev libfreetype-dev")
endif()

# Add rpath to the executable to find local .so files at runtime
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-rpath,'${CSFML_LIB_DIR}'")

# Add the CSFML build
add_subdirectory(csfml_lib)

# # Explicitly define the path to your local CSFML libraries
# set(CSFML_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build/install/include)
# set(CSFML_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build/install/lib)
# set(CMAKE_FIND_LIBRARY_SUFFIXES ".so;.a")

# Set the source files
set(SOURCES 
    my_runner.c
    init_window.c
    init_backgrounds.c
    init_time.c
    next_frame_full.c
    option_dealing.c
    show_credits.c
    title.c
    how_to_play.c
    init_background_overflow.c
)

# Add the executable
add_executable(my_runner ${SOURCES})

# Add our libraries and their dependencies (including CSFML)
add_subdirectory(lib)

# Link the final executable against our global interface library.
# This single target now provides all project libraries and all dependencies.
target_link_libraries(my_runner PRIVATE global_dependencies)

# Custom command to copy the executable to the root 'files' directory after build
add_custom_command(TARGET my_runner POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    $<TARGET_FILE:my_runner>
    ${CMAKE_CURRENT_SOURCE_DIR}/my_runner
    COMMENT "Copying executable to root project directory"
)

add_custom_command(TARGET my_runner POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    $<TARGET_FILE:my_runner>
    ${CMAKE_SOURCE_DIR}/my_runner
)


