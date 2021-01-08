cmake_minimum_required(VERSION 3.17)
project(CPP2)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(./client)
add_subdirectory(./server)

add_executable(CPP2 main.cpp)