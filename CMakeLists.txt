cmake_minimum_required(VERSION 3.5)

# export compile commands, helps clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# set build type: Release or Debug
set(CMAKE_BUILD_TYPE "Debug")

# set C standard to 90
set(CMAKE_C_STANDARD 90)
set(CMAKE_C_EXTENSIONS OFF)

# strictly enforce C standard
set(CMAKE_C_FLAGS "-pedantic -Wpedantic")

# set project name
project(learning_c)

# include modules directories
add_subdirectory(chapter1)
add_subdirectory(chapter2)
add_subdirectory(chapter3)
add_subdirectory(chapter4)
add_subdirectory(utils)
