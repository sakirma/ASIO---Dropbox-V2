#include <server/adapters/AdapterDirectory.hpp>
#include <server/ServerSettings.hpp>

#include <core/commands/CommandDir.hpp>

#include <iostream>

using namespace server;
using namespace server::adapter;

bool AdapterDirectory::Execute(asio::ip::tcp::iostream &ioStream, const std::string &params) const {
    std::vector<std::string> p{};
    if (splitParams(p, params) != 1) {
        std::cout << "invalid input for 'dir' expected 'dir' {path}" << std::endl;
        return false;
    }
    std::string path = ServerSettings::GetInstance()->RootFolder + "/" + p[0];

    std::string result{};
    auto dirCommand = core::CommandDir(path);
    if (dirCommand.Execute(ioStream, result)) {
        for (auto &f : dirCommand.files) {
            ioStream << f.fileType + "|" + f.name + "|" + f.time + "|" + f.fileSize << CRLF;

            std::string response{};
            for (;;) {
                if (std::getline(ioStream, response)) {
                    break;
                }
            }
        }


        ioStream << BREAK << CRLF;
        std::string response{};
        for (;;) {
            if (std::getline(ioStream, response)) {
                break;
            }
        }

        ioStream << CRLF;
        return true;
    } else {
        std::cout << result << std::endl;
        return false;
    }
}
