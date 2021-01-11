cmake_minimum_required(VERSION 3.17)
project(CPP2)

set(CMAKE_CXX_STANDARD 20)

add_executable(client client.cpp DirectoryManager.cpp DirectoryManager.hpp)

target_link_libraries(client ws2_32)