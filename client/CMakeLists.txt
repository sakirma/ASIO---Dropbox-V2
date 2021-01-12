cmake_minimum_required(VERSION 3.17)
project(CPP2)

set(CMAKE_CXX_STANDARD 20)

add_compile_definitions(_WIN32_WINNT=0x0601)

add_executable(client
        src/client/Client.cpp
        src/client/ClientSettings.cpp
        src/client/adapters/AdapterMakeDirectory.cpp
        src/client/adapters/AdapterDelete.cpp
        src/client/adapters/AdapterRename.cpp
        src/client/adapters/ErrorAdapter.cpp src/client/adapters/AdapterDirectory.cpp src/client/adapters/AdapterPut.cpp)

target_include_directories(client PRIVATE src include)

target_link_libraries(client ws2_32 core)