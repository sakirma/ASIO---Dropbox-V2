#include <core/commands/CommandPut.hpp>
#include <core/DirectoryManager.hpp>

#include <fstream>

using namespace core;

bool CommandPut::Execute(asio::ip::tcp::iostream &ioStream, std::string &message) {
    if (DirectoryManager::IsDirectory(path_)) {
        message = "Given path is a directory";
        return false;
    }

    if (!DirectoryManager::FolderOrFileExists(path_)) {
        message = "Given file does not exists!";
        return false;
    }

    if (!DirectoryManager::HasPermission(path_)) {
        message = "You have no permission to this file";
        return false;
    }

    std::string drive{};
    std::string dir{};
    std::string fname{};
    std::string ext{};
    DirectoryManager::SplitPath(path_, drive, dir, fname, ext);
    std::string fileName = fname + ext;


    std::ifstream file(path_, std::ios::binary | std::ios::ate);
    if (file.fail()) {
        throw std::invalid_argument("Cannot open file");
    }
    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);

    buffer.clear();
    buffer.resize(size);
    file.read(buffer.data(), size);

    return true;
}