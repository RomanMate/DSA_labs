cmake_minimum_required(VERSION 3.29)
project(lab_05 C)

set(CMAKE_C_STANDARD 23)

add_executable(lab_05 main.c
        verem.c
        ../../lab_06/Queue/queuef.c
        ../../lab_06/Queue/queuef.h
        constants.h)
