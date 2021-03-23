cmake_minimum_required(VERSION 3.17)
project(learn_math C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(learn_math
        def.h
        main.c
        suplem.c)
