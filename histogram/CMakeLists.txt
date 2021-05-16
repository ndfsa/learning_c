cmake_minimum_required(VERSION 3.5)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_C_STANDARD 90)
set(CMAKE_C_EXTENSIONS OFF)

project(histogram)

add_subdirectory(src)
