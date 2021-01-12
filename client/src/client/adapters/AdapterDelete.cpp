#include <client/adapters/AdapterDelete.hpp>
#include <core/commands/CommandDelete.hpp>
#include <client/ClientSettings.hpp>
#include <iostream>

using namespace client;
using namespace client::adapter;

bool AdapterDelete::Execute(asio::ip::tcp::iostream &ioStream, const std::string &params) const {
    std::vector<std::string> p{};
    if (splitParams(p, params) != 1) {
        std::cout << "invalid input for 'del' expected 'del' {path}" << std::endl;
        return false;
    }
    std::string path = ClientSettings::GetInstance()->RootFolder + "/" + p[0];

    std::string result{};
    if(core::CommandDelete(path).Execute(ioStream, result)) {
        ioStream << "del " + params << CRLF;
        return true;
    }
    else {
        std::cout << result << std::endl;
        return false;
    }
}
