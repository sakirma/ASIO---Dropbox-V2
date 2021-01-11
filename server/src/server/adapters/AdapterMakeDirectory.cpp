#include "server/adapters/AdapterMakeDirectory.hpp"
#include <server/commands/CommandMakeDirectory.hpp>
#include <memory>

using namespace server;
using namespace server::adapter;

void AdapterMakeDirectory::Execute(asio::ip::tcp::iostream &ioStream, const std::string &params) const {
    std::vector<std::string> p{};
    if (splitParams(p, params) != 2) {
        ioStream << "invalid input for 'mkdir' expected 'mkdir' {parent dir} {folder name}" << CRLF;
        return;
    }

    CommandMakeDirectory(p[0], p[1]).Execute(ioStream);
}
