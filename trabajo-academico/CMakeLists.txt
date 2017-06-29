cmake_minimum_required(VERSION 2.7)

project(cmetrics C)

set(CMAKE_BUILD_TYPE Release)

include_directories("${PROJECT_SOURCE_DIR}")

OPTION (USE_OpenMP "Use OpenMP" ON)
IF(USE_OpenMP)
  FIND_PACKAGE(OpenMP)
  IF(OPENMP_FOUND)
    SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
  ENDIF()
ENDIF()

add_executable(graph main.c graph.c graphalgorithms.c priority_queue.c queue.c)