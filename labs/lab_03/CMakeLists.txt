cmake_minimum_required(VERSION 3.29)
project(lab_03 C)

set(CMAKE_C_STANDARD 23)

add_executable(lab_03 main.c
        student.c
        student.h
        ../lab_05/verem/verem.c
        ../lab_05/verem/verem.h)
