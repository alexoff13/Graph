cmake_minimum_required(VERSION 3.21)
project(graph)

set(CMAKE_CXX_STANDARD 23)
include_directories(src)

add_executable(graph main.cpp src/graph.cpp src/graph.h src/arc.cpp src/arc.h src/vertex.cpp src/vertex.h)
