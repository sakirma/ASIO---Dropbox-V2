cmake_minimum_required(VERSION 3.17)
project(server)

set(CMAKE_CXX_STANDARD 20)

add_compile_definitions(_WIN32_WINNT=0x0601)

add_executable(server server.cpp
        src/server/commands/CommandFactory.cpp
        src/server/commands/CommandInfo.cpp
        src/server/DirectoryManager.cpp
        src/server/commands/CommandMakeDirectory.cpp
        src/server/adapters/AdapterMakeDirectory.cpp
        src/server/ServerSettings.cpp
        src/server/adapters/AdapterDelete.cpp
        src/server/commands/CommandDelete.cpp
        src/server/adapters/AdapterRename.cpp src/server/commands/CommandRename.cpp)

target_include_directories(server PRIVATE src include)

target_link_libraries(server ws2_32)