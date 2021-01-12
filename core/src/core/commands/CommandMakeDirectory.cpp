#include <core/commands/CommandMakeDirectory.hpp>

#include <core/DirectoryManager.hpp>


using namespace core;

bool CommandMakeDirectory::Execute(asio::ip::tcp::iostream &ioStream, std::string &message)  {
    if (!DirectoryManager::FolderOrFileExists( path_)) {
        message = "Given Parent folder does not exists!";
        return false;
    }

    if (DirectoryManager::FolderOrFileExists( path_ + "/" + newName_)) {
        message = "Folder '" + newName_ + "' already exists in the given parent directory";
        return false;
    }

    if (DirectoryManager::PathIsReadOnly(path_)) {
        message = "No Permission";
        return false;
    }

    DirectoryManager::GenerateDirectory( path_, newName_);
    return true;
}
