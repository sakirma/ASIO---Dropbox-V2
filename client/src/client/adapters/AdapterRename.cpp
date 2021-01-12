#include <client/adapters/AdapterRename.hpp>
#include <core/commands/CommandRename.hpp>
#include <client/ClientSettings.hpp>
#include <iostream>

using namespace client;
using namespace client::adapter;

bool AdapterRename::Execute(asio::ip::tcp::iostream &ioStream, const std::string &params) const {
    std::vector<std::string> p{};
    if (splitParams(p, params) != 2) {
        std::cout << "invalid input for 'ren' expected 'ren' {path} {name}" << std::endl;
        return false;
    }
    std::string path = ClientSettings::GetInstance()->RootFolder + "/" + p[0];

    std::string result{};
    if (core::CommandRename(path, p[1]).Execute(ioStream, result)) {
        ioStream << "ren " << params << CRLF;
        return true;
    } else {
        std::cout << result << std::endl;
        return false;
    }
}
