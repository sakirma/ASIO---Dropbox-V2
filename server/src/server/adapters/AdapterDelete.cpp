#include <server/adapters/AdapterDelete.hpp>
#include <core/commands/CommandDelete.hpp>
#include <server/ServerSettings.hpp>

using namespace server;
using namespace server::adapter;

bool AdapterDelete::Execute(asio::ip::tcp::iostream &ioStream, const std::string &params) const {
    std::vector<std::string> p{};
    if (splitParams(p, params) != 1) {
        ioStream << "invalid input for 'del' expected 'del' {path}" << CRLF;
        return false;
    }
    std::string path = ServerSettings::GetInstance()->RootFolder + "/" + p[0];

    std::string result;
    if (core::CommandDelete(path).Execute(ioStream, result)) {
        ioStream << OK << CRLF;
        return true;
    }
    else {
        ioStream << result << CRLF;
        return false;
    }
}
