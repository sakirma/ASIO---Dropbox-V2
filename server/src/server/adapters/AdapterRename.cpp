#include <server/adapters/AdapterRename.hpp>
#include <core/commands/CommandRename.hpp>
#include <server/ServerSettings.hpp>

using namespace server;
using namespace server::adapter;

bool AdapterRename::Execute(asio::ip::tcp::iostream &ioStream, const std::string &params) const {
    std::vector<std::string> p{};
    if (splitParams(p, params) != 2) {
        ioStream << "invalid input for 'ren' expected 'ren' {path} {name}" << CRLF;
        return false;
    }
    std::string path = ServerSettings::GetInstance()->RootFolder + "/" + p[0];

    std::string result;
    if (core::CommandRename(path, p[1]).Execute(ioStream, result)) {
        ioStream << OK << CRLF;
        return true;
    } else {
        ioStream << result << CRLF;
        return false;
    }
}
