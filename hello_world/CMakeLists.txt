cmake_minimum_required(VERSION 3.5)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE "Release")

project(hello_world)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c89")

add_subdirectory(src)
