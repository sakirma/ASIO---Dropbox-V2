#include "./DirectoryManager.hpp"

#include <filesystem>
#include <iostream>


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

void DirectoryManager::SplitPath(const std::string &path, std::string &drive, std::string &dir, std::string &fname, std::string &ext) {
    char drive_buf[_MAX_DRIVE];
    char dir_buf[_MAX_DIR];
    char fname_buf[_MAX_FNAME];
    char ext_buf[_MAX_EXT];

    _splitpath(path.c_str(), drive_buf, dir_buf, fname_buf, ext_buf);

    drive.assign(drive_buf);
    dir.assign(dir_buf);
    fname.assign(fname_buf);
    ext.assign(ext_buf);
}

bool DirectoryManager::RenameDirectory(const std::string &path, const std::string &newName) {
    std::string drive{};
    std::string dir{};
    std::string fname{};
    std::string ext{};
    SplitPath(path, drive, dir, fname, ext);

    try {
        std::filesystem::rename(drive + dir + fname + ext,
                                drive + dir + newName);
        return true;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return false;
    }
}
