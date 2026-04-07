cmake_minimum_required(VERSION 3.5)
project(build_sfml_csfml NONE)

include(ExternalProject)

if(UNIX)
  message(STATUS "Required Linux dev packages: libx11-dev libxrandr-dev libxinerama-dev libxcursor-dev libxkbcommon-dev libfreetype6-dev libxcb1-dev libasound2-dev libopenal-dev libvorbis-dev libogg-dev libflac-dev libgl1-mesa-dev libglu1-mesa-dev pkg-config")
endif()

# Check for system dependencies early and provide actionable hints
# find_package(X11)
# if(NOT X11_FOUND)
#   message(FATAL_ERROR "X11 not found. Install X11 development headers (e.g. libx11-dev).")
# endif()
# if(NOT DEFINED X11_Xrandr_LIB OR X11_Xrandr_LIB STREQUAL "")
#   message(FATAL_ERROR "X11 RandR library not found. Install libxrandr-dev.")
# endif()
# if(NOT DEFINED X11_Xinerama_LIB OR X11_Xinerama_LIB STREQUAL "")
#   message(WARNING "X11 Xinerama library not found. Install libxinerama-dev if needed.")
# endif()
# find_package(Freetype)
# if(NOT Freetype_FOUND)
#   message(WARNING "Freetype not found. Install libfreetype6-dev for font support.")
# endif()

set(SFML_URL https://www.sfml-dev.org/files/SFML-2.5.1-sources.zip)
set(CSFML_URL https://www.sfml-dev.org/files/CSFML-2.5-sources.zip)

set(prefix ${CMAKE_CURRENT_BINARY_DIR}/install)

ExternalProject_Add(sfml
  URL ${SFML_URL}
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/sfml
  CONFIGURE_COMMAND ${CMAKE_COMMAND} <SOURCE_DIR> -DCMAKE_BUILD_TYPE=Release -DBUILD_SHARED_LIBS=OFF -DCMAKE_INSTALL_PREFIX=${prefix}/sfml
  BUILD_COMMAND ${CMAKE_COMMAND} --build . -- -j${CMAKE_BUILD_PARALLEL_LEVEL}
  INSTALL_COMMAND ${CMAKE_COMMAND} --build . --target install
)

ExternalProject_Add(csfml
  URL ${CSFML_URL}
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/csfml
  DEPENDS sfml
  CONFIGURE_COMMAND ${CMAKE_COMMAND} <SOURCE_DIR> -DSFML_STATIC_LIBRARIES=TRUE -DCMAKE_BUILD_TYPE=Release -DBUILD_SHARED_LIBS=OFF -DSFML_DIR=${prefix}/sfml/lib/cmake/SFML -DCMAKE_INSTALL_PREFIX=${prefix}/csfml
  BUILD_COMMAND ${CMAKE_COMMAND} --build . -- -j${CMAKE_BUILD_PARALLEL_LEVEL}
  INSTALL_COMMAND ${CMAKE_COMMAND} --build . --target install
)

add_custom_target(build-all
  DEPENDS sfml csfml
)
