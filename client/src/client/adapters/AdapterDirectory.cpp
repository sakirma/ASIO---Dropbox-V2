#include <client/adapters/AdapterDirectory.hpp>

#include <client/ClientSettings.hpp>
#include <core/commands/CommandDir.hpp>

#include <iostream>

using namespace client;
using namespace client::adapter;

bool AdapterDirectory::Execute(asio::ip::tcp::iostream &ioStream, const std::string &params) const {
    std::vector<std::string> p{};
    if (splitParams(p, params) != 1) {
        std::cout << "invalid input for 'dir' expected 'dir' {path}" << std::endl;
        return false;
    }
    std::string path = ClientSettings::GetInstance()->RootFolder + "/" + p[0];

    ioStream << "dir " + params << CRLF;

    std::string resp{};
    std::vector<std::string> list{};
    for (;;) {
        if (!getline(ioStream, resp))
            continue;
        resp.erase(resp.end() - 1); // remove '\r'
        if (resp == BREAK) {
            break;
        }

        list.push_back(resp);
        ioStream << CRLF;
    }
    ioStream << CRLF;

    for(const auto &s : list) {
        std::cout << s << std::endl;
    }

    return true;
}
