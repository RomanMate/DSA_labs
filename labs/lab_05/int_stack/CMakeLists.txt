cmake_minimum_required(VERSION 3.29)
project(int_stack C)

set(CMAKE_C_STANDARD 23)

add_executable(int_stack main.c
        int_stack_functions.c
        ../../lab_06/simple_queue/main.c
        ../../lab_06/simple_queue/simple_queue.c)
