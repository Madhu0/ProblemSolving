cmake_minimum_required(VERSION 3.9)
project(Graphs C)

set(CMAKE_C_STANDARD 99)

add_executable(Graphs main.c graphUtils.h graphUtils.c)