cmake_minimum_required(VERSION 3.29)
project(lab_11 C)

set(CMAKE_C_STANDARD 23)

add_executable(lab_11 main.c
        library.h
        library.c
        ../lab_13/main.c
        ../lab_13/operations-with-hashTable/hash_static_uj/main.c
        ../lab_13/operations-with-hashTable/hash_static_uj/hash_table.c)
