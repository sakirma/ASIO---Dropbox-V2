#include <core/commands/CommandRename.hpp>
#include <core/DirectoryManager.hpp>

using namespace core;

CommandRename::CommandRename(const std::string &path, const std::string &newName) : path_(std::string(path)),
                                                                                    newName_(std::string(newName)) {

}

bool CommandRename::Execute(asio::ip::tcp::iostream &ioStream, std::string &message)  {
    if (!DirectoryManager::FolderOrFileExists(path_)) {
        message = "Given folder or file does not exists!";
        return false;
    }

    if (DirectoryManager::PathIsReadOnly(path_)) {
        message = "No Permission";
        return false;
    }

    try {
        DirectoryManager::RenameDirectory(path_, newName_);
        return true;
    }
    catch (std::exception &e) {
        ioStream << e.what() << CRLF;
        return false;
    }
}
