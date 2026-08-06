cmake_minimum_required(VERSION 4.2)
project(type_challenges)

set(CMAKE_CXX_STANDARD 20)

add_library(type_challenges STATIC compile_checks.cpp)

if (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/solutions/compile_checks.cpp)
    add_library(type_challenges_solutions STATIC solutions/compile_checks.cpp)
endif()
