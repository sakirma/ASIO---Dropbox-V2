#include <client/adapters/AdapterRename.hpp>
#include <core/commands/CommandRename.hpp>
#include <client/ClientSettings.hpp>

using namespace client;
using namespace client::adapter;

void AdapterRename::Execute(asio::ip::tcp::iostream &ioStream, const std::string &params) const {
    std::vector<std::string> p{};
    if (splitParams(p, params) != 2) {
        ioStream << "invalid input for 'ren' expected 'ren' {path} {name}" << CRLF;
        return;
    }
    std::string path = ClientSettings::GetInstance()->RootFolder + "/" + p[0];


    core::CommandRename(path, p[1]).Execute(ioStream);
}
