#include "server/Commands/CommandMakeDirectory.hpp"

#include "server/DirectoryManager.hpp"


using namespace server;

void CommandMakeDirectory::Execute(asio::ip::tcp::iostream &ioStream) const {
    std::string rootPath = ServerSettings::GetInstance()->RootFolder;
    if (!DirectoryManager::FolderExists(rootPath + "/" + parentDir_)) {
        ioStream << "Given Parent folder does not exists!" << CRLF;
        return;
    }

    if (DirectoryManager::FolderExists(rootPath + "/" + parentDir_ + "/" + dirName_)) {
        ioStream << "Folder '" + dirName_ + "' already exists in the given parent directory" << CRLF;
        return;
    }

    if (DirectoryManager::PathIsReadOnly(rootPath + "/" + parentDir_)) {
        ioStream << "No Permission" << CRLF;
        return;
    }

    DirectoryManager::GenerateDirectory(rootPath + "/" + parentDir_, dirName_);

    ioStream << OK << CRLF;
}
