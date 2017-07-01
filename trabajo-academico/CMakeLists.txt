cmake_minimum_required(VERSION 3.4)

project(cmetrics C)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_C_FLAGS "-Wall")
set(CMAKE_C_FLAGS_DEBUG "-g")
set(CMAKE_C_FLAGS_RELEASE "-O3")

include_directories("${PROJECT_SOURCE_DIR}")

OPTION(LINUX_BUILD "Linux Build" OFF)
OPTION (USE_OpenMP "Use OpenMP" ON)
IF(USE_OpenMP)
  FIND_PACKAGE(OpenMP)
  IF(OPENMP_FOUND)
    SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
  ENDIF()
ENDIF()

IF(LINUX_BUILD)
    add_executable(cgmetrics mainlinux.c graph.c graphalgorithms.c priority_queue.c queue.c)
ELSE()
    add_executable(cgmetrics main.c graph.c graphalgorithms.c priority_queue.c queue.c)
ENDIF()
