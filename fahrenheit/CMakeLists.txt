cmake_minimum_required(VERSION 3.5)
set(CMAKE_EXPORT_COMMANDS)
set(CMAKE_BUILD_TYPE "Debug")

project(fahrenheit)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c89")

add_subdirectory(src)
