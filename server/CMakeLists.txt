cmake_minimum_required(VERSION 3.17)
project(server)

set(CMAKE_CXX_STANDARD 20)
add_compile_definitions(_WIN32_WINNT=0x0601)


add_executable(server server.cpp
        src/server/ServerSettings.cpp
        src/server/adapters/AdapterMakeDirectory.cpp
        src/server/adapters/AdapterDelete.cpp
        src/server/adapters/AdapterRename.cpp
        src/server/adapters/ErrorAdapter.cpp src/server/adapters/AdapterDirectory.cpp)

target_include_directories(server PRIVATE src include)

target_link_libraries(server ws2_32 core)