cmake_minimum_required(VERSION 3.18)
project(rubikscube C)

set(CMAKE_C_STANDARD 11)

add_executable(rubikscube main.c
        rubikscube.c)
