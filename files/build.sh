#!/usr/bin/env bash
CWD=$(pwd)
rm -rf build my_runner
mkdir -p build
cmake -S . -B ./build
if [ $? -ne 0 ]; then
    echo "CMake configuration failed"
    exit 1
fi
cd build
make VERBOSE=1
if [ $? -ne 0 ]; then
    cd "$CWD"
    echo "Build failed"
    exit 1
fi
cd "$CWD"
