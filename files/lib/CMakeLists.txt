# This file serves as a master list for all the libraries in the project.

add_subdirectory("audio")
add_subdirectory("convert")
add_subdirectory("dict")
add_subdirectory("end")
add_subdirectory("event")
add_subdirectory("game_assets")
add_subdirectory("help")
add_subdirectory("image")
add_subdirectory("key")
add_subdirectory("level")
add_subdirectory("maths")
add_subdirectory("mouse")
add_subdirectory("my")
add_subdirectory("pixel")
add_subdirectory("scores")
add_subdirectory("silvers")
add_subdirectory("sprite")
add_subdirectory("text")
add_subdirectory("window")

# The global_dependencies target bundles up all of your project's libraries
# AND the csfml-local dependency for the final executable.
add_library(global_dependencies INTERFACE)
target_link_libraries(global_dependencies INTERFACE
    csfml-local
    my
    mywindow
    myaudio
    mysprite
    mytext
    myimage
    myevents
    mymaths
    mymouse
    myassets
    myend
    myhelp
    mylevel
    mypixel
    myscores
    mysilvers
    myconvert
    mydict
    mykey
)
