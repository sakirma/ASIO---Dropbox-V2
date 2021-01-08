cmake_minimum_required(VERSION 3.17)
project(server)

set(CMAKE_CXX_STANDARD 20)

add_executable(server server.cpp
        src/CommandFactory.cpp)

target_include_directories(server PRIVATE src include)

target_link_libraries(server ws2_32)