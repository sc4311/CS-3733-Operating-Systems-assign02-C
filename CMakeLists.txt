cmake_minimum_required(VERSION 3.28)
project(assign02 C)

set(CMAKE_C_STANDARD 11)

add_executable(assign02 main.c
        array_operations.h
        array_operations.c
        merge_operations.h
        merge_operations.c)
