#include <server/commands/CommandRename.hpp>
#include <server/ServerSettings.hpp>
#include <server/DirectoryManager.hpp>

using namespace server;

CommandRename::CommandRename(const std::string &path, const std::string &newName) : path_(std::string(path)),
                                                                                    newName_(std::string(newName)) {

}

void CommandRename::Execute(asio::ip::tcp::iostream &ioStream) const {
    std::string rootPath = ServerSettings::GetInstance()->RootFolder;
    std::string renamePath = rootPath + "/" + path_;

    if (!DirectoryManager::FolderOrFileExists(renamePath)) {
        ioStream << "Given folder or file does not exists!" << CRLF;
        return;
    }

    if (DirectoryManager::PathIsReadOnly(renamePath)) {
        ioStream << "No Permission" << CRLF;
        return;
    }

    if(DirectoryManager::RenameDirectory(renamePath, newName_)) {
        ioStream << OK << CRLF;
    }
    else {
        ioStream << "Something went wrong" << CRLF;
    }
}
