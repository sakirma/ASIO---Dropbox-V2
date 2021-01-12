#include <core/commands/CommandMakeDirectory.hpp>

#include <core/DirectoryManager.hpp>


using namespace core;

void CommandMakeDirectory::Execute(asio::ip::tcp::iostream &ioStream) const {
    if (!DirectoryManager::FolderOrFileExists( path_)) {
        ioStream << "Given Parent folder does not exists!" << CRLF;
        return;
    }

    if (DirectoryManager::FolderOrFileExists( path_ + "/" + newName_)) {
        ioStream << "Folder '" + newName_ + "' already exists in the given parent directory" << CRLF;
        return;
    }

    if (DirectoryManager::PathIsReadOnly(path_)) {
        ioStream << "No Permission" << CRLF;
        return;
    }

    DirectoryManager::GenerateDirectory( path_, newName_);

    ioStream << OK << CRLF;
}
