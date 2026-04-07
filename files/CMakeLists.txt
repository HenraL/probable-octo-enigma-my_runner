cmake_minimum_required(VERSION 3.10)

project(MyRunner C)

set(CMAKE_C_STANDARD 99)

add_subdirectory(csfml_lib)

# Tell CMake where to find the local CSFML headers
include_directories(csfml_lib/include)

# Tell CMake where to find the local CSFML libraries
link_directories(csfml_lib/lib)

# Add the executable
add_executable(my_runner
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

# Find the CSFML components
#find_package(CSFML 2.5 COMPONENTS graphics window system audio REQUIRED)

# Build the libraries
add_subdirectory(lib/audio)
add_subdirectory(lib/convert)
add_subdirectory(lib/dict)
add_subdirectory(lib/end)
add_subdirectory(lib/event)
add_subdirectory(lib/game_assets)
add_subdirectory(lib/help)
add_subdirectory(lib/image)
add_subdirectory(lib/key)
add_subdirectory(lib/level)
add_subdirectory(lib/maths)
add_subdirectory(lib/mouse)
add_subdirectory(lib/my)
add_subdirectory(lib/pixel)
add_subdirectory(lib/scores)
add_subdirectory(lib/silvers)
add_subdirectory(lib/sprite)
add_subdirectory(lib/text)
add_subdirectory(lib/window)

# Link the libraries
target_link_libraries(my_runner
    csfml-graphics
    csfml-window
    csfml-system
    csfml-audio
    my
    myend
    mytext
    mydict
    mypixel
    myaudio
    mymouse
    myimage
    mylevel
    mymaths
    mysprite
    mywindow
    myevents
    myassets
    myscores
    mysilvers
    myconvert
)

add_custom_command(TARGET my_runner POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    $<TARGET_FILE:my_runner>
    ${CMAKE_SOURCE_DIR}/my_runner
)


