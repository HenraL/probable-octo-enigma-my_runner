cmake_minimum_required(VERSION 3.15)
include(ExternalProject)

set(PREFIX ${CMAKE_CURRENT_BINARY_DIR}/install)

set(SFML_URL https://www.sfml-dev.org/files/SFML-2.5.1-sources.zip)
set(CSFML_URL https://www.sfml-dev.org/files/CSFML-2.5-sources.zip)

# ---------------- SFML ----------------
ExternalProject_Add(sfml_external
    URL ${SFML_URL}
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/sfml
    CMAKE_ARGS
        -DCMAKE_INSTALL_PREFIX=${PREFIX}
        -DCMAKE_BUILD_TYPE=Release
        -DBUILD_SHARED_LIBS=OFF
        -DSFML_BUILD_EXAMPLES=OFF
        -DSFML_BUILD_DOC=OFF
)

# ---------------- CSFML ----------------
ExternalProject_Add(csfml_external
    URL ${CSFML_URL}
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/csfml
    DEPENDS sfml_external
    CMAKE_ARGS
        -DCMAKE_INSTALL_PREFIX=${PREFIX}
        -DCMAKE_BUILD_TYPE=Release
        -DBUILD_SHARED_LIBS=OFF
        -DSFML_STATIC_LIBRARIES=TRUE
        -DSFML_DIR=${PREFIX}/lib/cmake/SFML
)

# ---------------- Imported / Interface targets ----------------
# This is a single "package" target that represents the entire local
# build of CSFML and its dependencies.
add_library(csfml-local INTERFACE)
add_dependencies(csfml-local csfml_external)

# Add the include directory for CSFML/ and SFML/ headers
target_include_directories(csfml-local INTERFACE
    "${PREFIX}/include"
)

# Add the library directory for the linker
target_link_directories(csfml-local INTERFACE
    "${PREFIX}/lib"
)

# Link against all the static libraries in the correct order.
# By using the full path to the libraries that will be generated,
# CMake can resolve these at link time.
target_link_libraries(csfml-local INTERFACE
    # CSFML Libraries
    "${PREFIX}/lib/libcsfml-graphics.a"
    "${PREFIX}/lib/libcsfml-window.a"
    "${PREFIX}/lib/libcsfml-audio.a"
    "${PREFIX}/lib/libcsfml-system.a"
    "${PREFIX}/lib/libcsfml-network.a"

    # SFML Libraries (static)
    "${PREFIX}/lib/libsfml-graphics-s.a"
    "${PREFIX}/lib/libsfml-window-s.a"
    "${PREFIX}/lib/libsfml-audio-s.a"
    "${PREFIX}/lib/libsfml-system-s.a"
    "${PREFIX}/lib/libsfml-network-s.a"

    # SFML's own dependencies on Linux
    "freetype"
    "X11"
    "Xrandr"
    "udev"
    "vorbisenc"
    "vorbisfile"
    "vorbis"
    "ogg"
    "openal"
    "FLAC"
    "pthread"
    "dl"
    "m"
    "GL"
    "stdc++"
)
