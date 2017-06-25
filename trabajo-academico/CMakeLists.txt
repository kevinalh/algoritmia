cmake_minimum_required(VERSION 2.7)

project(cmetrics C)

set(CMAKE_BUILD_TYPE Release)

include_directories("${PROJECT_SOURCE_DIR}")

add_executable(graph main.c graph.c graphalgorithms.c priority_queue.c queue.c)