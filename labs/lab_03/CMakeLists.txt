cmake_minimum_required(VERSION 3.29)
project(lab_03 C)

set(CMAKE_C_STANDARD 23)

add_executable(lab_03 main.c library.h libteszt.a
        Student_functions.c
        Student_functions.h
        ../lab_01/main.c)
target_link_libraries(lab_03 ${PROJECT_SOURCE_DIR}/libteszt.a)