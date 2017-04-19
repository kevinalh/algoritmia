cmake_minimum_required(VERSION 2.7)

project(clase3 C)

set(CMAKE_BUILD_TYPE Debug)

add_executable(patron patron.c)
add_executable(hseqclase hseqclase.c)
add_executable(knight knight.c)
add_executable(sudoku sudoku.c)
add_executable(nqueens nqueens.c)

target_link_libraries(hseqclase m)
