#include <server/ServerSettings.hpp>
#include <server/DirectoryManager.hpp>
#include "server/commands/CommandDelete.hpp"

using namespace server;

CommandDelete::CommandDelete(const std::string &path) {
    this->delete_path_ = path;
}

void CommandDelete::Execute(asio::ip::tcp::iostream &ioStream) const {
    std::string rootPath = ServerSettings::GetInstance()->RootFolder;
    std::string deletePath = rootPath + "/" + delete_path_;
    if (!DirectoryManager::FolderOrFileExists(deletePath)) {
        ioStream << "Given folder does not exists!" << CRLF;
        return;
    }

    if (DirectoryManager::PathIsReadOnly(deletePath)) {
        ioStream << "No Permission" << CRLF;
        return;
    }

    DirectoryManager::RemoveDirectoryOrFile(deletePath);
    ioStream << OK << CRLF;
}
