cmake_minimum_required(VERSION 3.5)

# export compile commands, helps clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# set build type: Release or Debug
set(CMAKE_BUILD_TYPE "Debug")

# set C standard to 90
set(CMAKE_C_STANDARD 90)
set(CMAKE_C_EXTENSIONS OFF)

# set project name
project(learning_c)

# include modules directories
add_subdirectory(temperatures)
add_subdirectory(hello_world)
add_subdirectory(input_output)

# test suite
enable_testing()
add_subdirectory(test)
add_test(NAME full_test COMMAND test-all)
