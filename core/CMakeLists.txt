cmake_minimum_required(VERSION 3.17)
project(core_project)

set(CMAKE_CXX_STANDARD 20)
add_compile_definitions(_WIN32_WINNT=0x0601)

add_library(core STATIC
        src/core/commands/CommandFactory.cpp
        src/core/commands/CommandInfo.cpp
        src/core/commands/CommandMakeDirectory.cpp
        src/core/commands/CommandDelete.cpp
        src/core/commands/CommandRename.cpp
        src/core/commands/CommandError.cpp
        src/core/commands/CommandDir.cpp
        src/core/commands/CommandPut.cpp

        src/core/DirectoryManager.cpp)

target_link_libraries(core ws2_32)

target_include_directories(core PUBLIC src include)