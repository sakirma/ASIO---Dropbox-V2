#include "server/DirectoryManager.hpp"

#include <filesystem>


using namespace server;

bool DirectoryManager::FolderExists(const std::string &folderPath) {
    return std::filesystem::exists(folderPath);
}

bool DirectoryManager::GenerateDirectory(const std::string &folderPath, const std::string &folderName) {
    return std::filesystem::create_directory(folderPath + "/" + folderName);
}

bool DirectoryManager::PathIsReadOnly(const std::string &path) {
    auto perms = std::filesystem::status(path).permissions();
    bool read = (perms & std::filesystem::perms::owner_read) != std::filesystem::perms::none;
    bool write = (perms & std::filesystem::perms::owner_write) != std::filesystem::perms::none;
    return read && !write;
}

bool DirectoryManager::RemoveDirectoryOrFile(const std::string &path) {
     return std::filesystem::remove_all(path) >= 0;
}
