#pragma once

#include <string>

namespace server {
    class DirectoryManager {
    public:
        static bool FolderExists(const std::string &folderPath);

        static bool GenerateDirectory(const std::string &folderPath, const std::string &folderName);

    public:
        DirectoryManager() = default;

        ~DirectoryManager() = default;

        DirectoryManager(const DirectoryManager &other) = delete;

        DirectoryManager(DirectoryManager &&other) noexcept {} // move constructor

        DirectoryManager &operator=(const DirectoryManager &other) = delete;

        DirectoryManager &operator=(DirectoryManager &&other) noexcept { // move assignment
            return *this;
        }
    };
}