#include <core/DirectoryManager.hpp>
#include <core/commands/CommandDelete.hpp>

using namespace core;

CommandDelete::CommandDelete(const std::string &path) {
    this->delete_path_ = path;
}

void CommandDelete::Execute(asio::ip::tcp::iostream &ioStream) const {
    if (!DirectoryManager::FolderOrFileExists(delete_path_)) {
        ioStream << "Given folder does not exists!" << CRLF;
        return;
    }

    if (DirectoryManager::PathIsReadOnly(delete_path_)) {
        ioStream << "No Permission" << CRLF;
        return;
    }

    DirectoryManager::RemoveDirectoryOrFile(delete_path_);
    ioStream << OK << CRLF;
}
