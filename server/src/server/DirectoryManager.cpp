#include "server/DirectoryManager.hpp"

#include <filesystem>
#include <iostream>


using namespace server;

bool DirectoryManager::FolderOrFileExists(const std::string &folderPath) {
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

bool DirectoryManager::RenameDirectory(const std::string &path, const std::string &newName) {
    char drive_buf[_MAX_DRIVE];
    char dir_buf[_MAX_DIR];
    char fname_buf[_MAX_FNAME];
    char ext_buf[_MAX_EXT];

    _splitpath(path.c_str(), drive_buf, dir_buf, fname_buf, ext_buf);
    std::string s_drive(drive_buf);
    std::string s_dir(dir_buf);
    std::string s_fname(fname_buf);
    std::string s_ext(ext_buf);

    try {
        std::filesystem::rename(s_drive + s_dir + s_fname + s_ext,
                                s_drive + s_dir + newName);
        return true;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return false;
    }
}
