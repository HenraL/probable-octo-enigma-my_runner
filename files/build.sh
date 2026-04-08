#!/usr/bin/env bash
CWD=$(pwd)
if [ "$1" == "clean" ]; then
    rm -rf build my_runner
    echo "Cleaned build artifacts"
    exit 0
fi
mkdir -p build
if [ $? -ne 0 ]; then
    echo "Failed to create build directory"
    exit 1
fi
if [ "${1,,}" == "debug" ]; then
    CMAKE_BUILD_TYPE=Debug
    MAKE_IT_VERBOSE=1
else
    CMAKE_BUILD_TYPE=Release
    MAKE_IT_VERBOSE=0
fi
cmake -S . -B ./build -DCMAKE_BUILD_TYPE=$CMAKE_BUILD_TYPE
if [ $? -ne 0 ]; then
    echo "CMake configuration failed"
    exit 1
fi
cd build
make VERBOSE=$MAKE_IT_VERBOSE
if [ $? -ne 0 ]; then
    cd "$CWD"
    echo "Build failed"
    exit 1
fi
cd "$CWD"
