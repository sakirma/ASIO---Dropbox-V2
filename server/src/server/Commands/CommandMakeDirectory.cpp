#include "server/Commands/CommandMakeDirectory.hpp"

#include "server/DirectoryManager.hpp"

using namespace server;

void CommandMakeDirectory::Execute(asio::ip::tcp::iostream &ioStream) const {
    if(!DirectoryManager::FolderExists(parentDir_)) {
        ioStream << "Given Parent folder does not exists!" << CRLF;
        return;
    }

    if(DirectoryManager::FolderExists(parentDir_ + "/" + dirName_)) {
        ioStream << "Folder '" + dirName_ + "' already exists in the given parent directory" << CRLF;
        return;
    }

    DirectoryManager::GenerateDirectory(parentDir_, dirName_);
}
