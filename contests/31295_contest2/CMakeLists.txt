cmake_minimum_required(VERSION 2.7)

project(contest2 C)

include(CMakeToolsHelpers OPTIONAL)

add_executable(vertex vertex.c)
add_executable(walkslengthn walkslengthn.c)
add_executable(catan catan.c)
add_executable(robotmotion robotmotion.c)