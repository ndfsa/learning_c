cmake_minimum_required(VERSION 3.5)

# export compile commands, helps clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# set build type: Release or Debug
set(CMAKE_BUILD_TYPE "Debug")

# set C standard to 90
set(CMAKE_C_STANDARD 90)
set(CMAKE_C_EXTENSIONS OFF)

# strictly enforce C standard
set(CMAKE_C_FLAGS "-pedantic")

# set project name
project(learning_c)

# include modules directories
add_subdirectory(chapter1)

# test suite
enable_testing()

add_subdirectory(test)

add_test(NAME test_hello COMMAND hello_world)
add_test(NAME test_temperatures COMMAND test_temperatures)
add_test(NAME test_blanks COMMAND test_blanks)
add_test(NAME test_eof COMMAND test_eof)
add_test(NAME test_histogram COMMAND test_histogram)
