cmake_minimum_required(VERSION 3.29)
project(teszt C)

set(CMAKE_C_STANDARD 23)

add_library(teszt STATIC library.c)
