cmake_minimum_required(VERSION 2.6.0)

project(clase1 C)

set(CMAKE_BUILD_TYPE Debug)

add_executable(bubblesort bubblesort.c)
add_executable(busqueda-secuencial busqueda-secuencial.c)
add_executable(string-matching string-matching.c)
add_executable(closest-pair closest-pair.c)
add_executable(selection-sort selection-sort.c)

target_link_libraries(closest-pair m)
