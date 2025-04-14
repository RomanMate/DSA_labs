cmake_minimum_required(VERSION 3.29)
project(lab_05 C)

set(CMAKE_C_STANDARD 23)

add_executable(lab_05 main.c
        verem.c
        ../../lab_06/Queue/queuef.c
        ../../lab_06/Queue/queuef.h
        constants.h
        ../../lab_07/Glass_circular/glass_circular_queue.c
        ../../lab_07/Glass_circular/glass_circular_queue.h
        ../../lab_07/Glass_circular/main.c)
