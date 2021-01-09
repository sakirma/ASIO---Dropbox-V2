cmake_minimum_required(VERSION 3.17)
project(server)

set(CMAKE_CXX_STANDARD 20)

add_compile_definitions(_WIN32_WINNT=0x0601)

add_executable(server server.cpp
        src/server/Commands/CommandFactory.cpp
        src/server/Commands/InfoCommand.cpp
        src/server/DirectoryManager.cpp
        src/server/Commands/CommandMakeDirectory.cpp
        src/server/Adapters/AdapterMakeDirectory.cpp)

target_include_directories(server PRIVATE src include)

target_link_libraries(server ws2_32)