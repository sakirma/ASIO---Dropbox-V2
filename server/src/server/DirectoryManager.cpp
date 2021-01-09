#include "server/DirectoryManager.hpp"

#include <filesystem>


using namespace server;

bool DirectoryManager::FolderExists(const std::string &folderPath) {
    return std::filesystem::exists(folderPath);
}

bool DirectoryManager::GenerateDirectory(const std::string &folderPath, const std::string &folderName) {
    return std::filesystem::create_directory(folderPath + "/" + folderName);
}