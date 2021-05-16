cmake_minimum_required(VERSION 3.5)

# export compile commands, helps clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

# set build type: Release or Debug
set(CMAKE_BUILD_TYPE "Debug")

# set C standard to 90
set(CMAKE_C_STANDARD 90)
set(CMAKE_C_EXTENSIONS OFF)

# set project name
project(input_output)

# include src directory
add_subdirectory(src)
