#include <server/adapters/AdapterPut.hpp>
#include <iostream>
#include <core/DirectoryManager.hpp>
#include <server/ServerSettings.hpp>

using namespace server;
using namespace server::adapter;

bool AdapterPut::Execute(asio::ip::tcp::iostream &ioStream, const std::string &params) const {
    std::vector<std::string> p{};
    if (splitParams(p, params) != 2) {
        std::cout << "invalid input for 'put' expected 'put' {path} {bytes}" << std::endl;
        return false;
    }

    std::string path = p[0];
    int bufferSize = stoi(p[1]);

    if(!DirectoryManager::FolderOrFileExists(path)) {
        ioStream << BREAK << CRLF;
        return false;
    }

    std::string rootFolder = ServerSettings::GetInstance()->RootFolder;
    if(!DirectoryManager::FileHasSameParentName(rootFolder, path)) {
        ioStream << BREAK << CRLF;
        return false;
    }

    ioStream << CRLF;

    // Ready to receive
    char buffer[bufferSize];
    ioStream.read(buffer, bufferSize);

    std::string melisaILoveYou(buffer);

    return false;
}
