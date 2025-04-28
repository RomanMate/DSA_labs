cmake_minimum_required(VERSION 3.29)
project(lab_01 C)

set(CMAKE_C_STANDARD 23)

add_executable(lab_01 main.c
        array_functions.c
        array_functions.h
        ../lab_05/main.c
        ../lab_05/int_stack/main.c
        ../lab_05/char_stack/main.c
        ../lab_05/char_stack/char_stack_functions.c)
