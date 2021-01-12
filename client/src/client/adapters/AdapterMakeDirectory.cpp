#include <client/adapters/AdapterMakeDirectory.hpp>
#include <core/commands/CommandMakeDirectory.hpp>
#include <client/ClientSettings.hpp>

#include <memory>
#include <iostream>

using namespace client;
using namespace client::adapter;

bool AdapterMakeDirectory::Execute(asio::ip::tcp::iostream &ioStream, const std::string &params) const {
    std::vector<std::string> p{};
    if (splitParams(p, params) != 2) {
        std::cout << "invalid input for 'mkdir' expected 'mkdir' {parent dir} {folder name}" << std::endl;
        return false;
    }
    std::string path = ClientSettings::GetInstance()->RootFolder + "/" + p[0];


    std::string result;
    if (core::CommandMakeDirectory(path, p[1]).Execute(ioStream, result)) {
        ioStream << "mkdir " + params << CRLF;
        return true;
    } else {
        std::cout << result << std::endl;
        return false;
    }
}
