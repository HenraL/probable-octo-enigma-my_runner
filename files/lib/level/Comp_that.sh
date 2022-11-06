#!/bin/bash
##
## EPITECH PROJECT, 2021
## runner - Comp_that.sh
## File description:
## jitter jitter
##

make re
gcc -g test.c -o test.out -L. -lmylevel
./test.out