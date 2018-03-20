cmake_minimum_required(VERSION 3.9)
project(PPCS_CW)

# added -fopenmp
find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp functions.h functions.cpp)
add_executable(PPCS_CW main.cpp)