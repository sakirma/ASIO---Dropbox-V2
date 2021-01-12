#include <core/commands/CommandRename.hpp>
#include <core/DirectoryManager.hpp>

using namespace core;

CommandRename::CommandRename(const std::string &path, const std::string &newName) : path_(std::string(path)),
                                                                                    newName_(std::string(newName)) {

}

void CommandRename::Execute(asio::ip::tcp::iostream &ioStream) const {
    if (!DirectoryManager::FolderOrFileExists(path_)) {
        ioStream << "Given folder or file does not exists!" << CRLF;
        return;
    }

    if (DirectoryManager::PathIsReadOnly(path_)) {
        ioStream << "No Permission" << CRLF;
        return;
    }

    if(DirectoryManager::RenameDirectory(path_, newName_)) {
        ioStream << OK << CRLF;
    }
    else {
        ioStream << "Something went wrong" << CRLF;
    }
}
