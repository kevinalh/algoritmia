cmake_minimum_required(VERSION 2.7)

project(clase9 C)

add_executable(pila pila.c pila.h)
add_executable(posfix posfix.c pila.h)
add_executable(balance balance.c pila.h)
