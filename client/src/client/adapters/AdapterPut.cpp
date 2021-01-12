#include <client/adapters/AdapterPut.hpp>
#include <client/ClientSettings.hpp>

#include <core/commands/CommandPut.hpp>

#include <iostream>
#include <core/DirectoryManager.hpp>

using namespace client;
using namespace client::adapter;

bool AdapterPut::Execute(asio::ip::tcp::iostream &ioStream, const std::string &params) const {
    std::vector<std::string> p{};
    if (splitParams(p, params) != 1) {
        std::cout << "invalid input for 'put' expected 'put' {file path}" << std::endl;
        return false;
    }

    std::string path = ClientSettings::GetInstance()->RootFolder + "/" + p[0];

    core::CommandPut commandPut(path);
    std::string m{};
    if (commandPut.Execute(ioStream, m)) {
        ioStream << "put " + path + " " + std::to_string(commandPut.buffer.size()) << CRLF;
        std::string response{};

        while (true) {
            if (getline(ioStream, response)) {
                response.erase(response.end() - 1);
                if (response == BREAK) {
                    m = "Something went wrong in the server";
                    return false;
                }
                break;
            }
        }

        ioStream << commandPut.buffer.data() << CRLF;

        return true;
    }

    std::cout << m << std::endl;
    return false;
}
