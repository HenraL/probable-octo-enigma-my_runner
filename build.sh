#!/bin/bash
##
## EPITECH PROJECT, 2025
## probable-octo-enigma-my_runner
## File description:
## build.sh
##

rm -rf build
mkdir -p build
cmake -S . -B build
if [ $? -ne 0 ]; then
    echo "CMake configuration failed"
    exit 1
fi
cmake --build build
if [ $? -ne 0 ]; then
    echo "Build failed"
    exit 1
fi
if [ $# -gt 0 ]; then
    ./build/my_runner -h
else
    ./build/my_runner -l
fi
