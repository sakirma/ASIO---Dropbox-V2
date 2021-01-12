#pragma once

#include <string>

class DirectoryManager {
public:
    static bool FolderOrFileExists(const std::string &folderPath);

    static bool GenerateDirectory(const std::string &folderPath, const std::string &folderName);

    static bool PathIsReadOnly(const std::string &path);


    static void
    SplitPath(const std::string &path, std::string &drive, std::string &dir, std::string &fname, std::string &ext);

    static bool RemoveDirectoryOrFile(const std::string &path);

    static bool RenameDirectory(const std::string &path, const std::string &newName);
};
