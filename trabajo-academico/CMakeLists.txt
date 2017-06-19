cmake_minimum_required(VERSION 2.7)

project(cmetrics)

include_directories("${PROJECT_BINARY_DIR}")

add_executable(graph graph.c)