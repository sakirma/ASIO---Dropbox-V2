#pragma once

#include <string>

struct SplitPathValues {
public:
    std::string drive{};
    std::string dir{};
    std::string fname{};
    std::string ext{};
};

class DirectoryManager {
public:
    static bool FolderOrFileExists(const std::string &folderPath);

    static bool GenerateDirectory(const std::string &folderPath, const std::string &folderName);

    static bool PathIsReadOnly(const std::string &path);


    static void
    SplitPath(const std::string &path, std::string &drive, std::string &dir, std::string &fname, std::string &ext);

    static void SplitPath(const std::string &path, SplitPathValues &splitPathValues);

    static bool RemoveDirectoryOrFile(const std::string &path);

    static bool RenameDirectory(const std::string &path, const std::string &newName);

    static bool IsDirectory(const std::string &path);

    static bool HasPermission(const std::string &path);

    static bool FileHasSameParentName(const std::string &within, const std::string &file);
};
