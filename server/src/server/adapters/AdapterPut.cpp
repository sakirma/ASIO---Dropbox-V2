#include <server/adapters/AdapterPut.hpp>
#include <iostream>
#include <core/DirectoryManager.hpp>
#include <server/ServerSettings.hpp>

using namespace server;
using namespace server::adapter;

bool AdapterPut::Execute(asio::ip::tcp::iostream &ioStream, const std::string &params) const {
    std::vector<std::string> p{};
    if (splitParams(p, params) != 1) {
        std::cout << "invalid input for 'put' expected 'put' {path}" << std::endl;
        return false;
    }

    std::string path = p[0];

    if(!DirectoryManager::FolderOrFileExists(path)) {
        ioStream << BREAK << CRLF;
        return false;
    }

    std::string rootFolder = ServerSettings::GetInstance()->RootFolder;
    DirectoryManager::FileHasSameParentName(rootFolder, path);

    return false;
}
