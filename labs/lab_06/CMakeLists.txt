cmake_minimum_required(VERSION 3.29.6)
project(lab_06 C)

set(CMAKE_C_STANDARD 23)

add_executable(lab_06 main.c
        main.c
        simple_queue.c
        simple_queue.h
        constans.h
        ../lab_07/glasess_circular_queue.h
)
