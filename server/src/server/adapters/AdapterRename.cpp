#include <server/adapters/AdapterRename.hpp>
#include <server/commands/CommandRename.hpp>

using namespace server;
using namespace server::adapter;

void AdapterRename::Execute(asio::ip::tcp::iostream &ioStream, const std::string &params) const {
    std::vector<std::string> p{};
    if (splitParams(p, params) != 2) {
        ioStream << "invalid input for 'ren' expected 'ren' {path} {name}" << CRLF;
        return;
    }

    CommandRename(p[0], p[1]).Execute(ioStream);
}
