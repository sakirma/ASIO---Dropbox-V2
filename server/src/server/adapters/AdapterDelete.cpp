#include <server/adapters/AdapterDelete.hpp>
#include <core/commands/CommandDelete.hpp>
#include <server/ServerSettings.hpp>

using namespace server;
using namespace server::adapter;

void AdapterDelete::Execute(asio::ip::tcp::iostream &ioStream, const std::string &params) const {
    std::vector<std::string> p{};
    if (splitParams(p, params) != 1) {
        ioStream << "invalid input for 'del' expected 'del' {path}" << CRLF;
        return;
    }
    std::string path = ServerSettings::GetInstance()->RootFolder + "/" + p[0];

    core::CommandDelete(path).Execute(ioStream);
}
