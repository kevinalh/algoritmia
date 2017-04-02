cmake_minimum_required(VERSION 2.7)

project(30967 C)

set(CMAKE_BUILD_TYPE Debug)

add_executable(equations equations.c)
add_executable(shovel shovel.c)
add_executable(taymyr taymyr.c)
add_executable(substrings substrings.c)
add_executable(counterex counterex.c)
add_executable(dragons dragons.c)
add_executable(ilya ilya.c)
add_executable(newyear newyear.c)
add_executable(ananagrams ananagrams.c)

target_link_libraries(equations m)
target_link_libraries(newyear m)
