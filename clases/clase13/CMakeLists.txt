cmake_minimum_required(VERSION 2.7)

project(clase13 C)

include_directories("${PROJECT_BINARY_DIR}")

add_executable(hash main.c openhashing.c)
