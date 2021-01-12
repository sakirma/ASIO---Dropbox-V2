#include <core/DirectoryManager.hpp>
#include <core/commands/CommandDelete.hpp>

using namespace core;

CommandDelete::CommandDelete(const std::string &path) {
    this->delete_path_ = path;
}

bool CommandDelete::Execute(asio::ip::tcp::iostream &ioStream, std::string &message) const {
    if (!DirectoryManager::FolderOrFileExists(delete_path_)) {
        message = "Given folder does not exists!";
        return false;
    }

    if (DirectoryManager::PathIsReadOnly(delete_path_)) {
        message = "No Permission";
        return false;
    }

    DirectoryManager::RemoveDirectoryOrFile(delete_path_);
    return true;
}
