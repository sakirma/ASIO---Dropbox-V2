#pragma once

#include <string>
#include "ServerSettings.hpp"

namespace server {
    class DirectoryManager {
    public:
        static bool FolderExists(const std::string &folderPath);

        static bool GenerateDirectory(const std::string &folderPath, const std::string &folderName);
        static bool PathIsReadOnly(const std::string &path);

        static bool RemoveDirectoryOrFile(const std::string &path);

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