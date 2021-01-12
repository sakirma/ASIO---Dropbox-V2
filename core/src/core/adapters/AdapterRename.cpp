#include <core/adapters/AdapterRename.hpp>
#include <core/commands/CommandRename.hpp>

using namespace core;
using namespace core::adapter;

void AdapterRename::Execute(asio::ip::tcp::iostream &ioStream, const std::string &params) const {
    std::vector<std::string> p{};
    if (splitParams(p, params) != 2) {
        ioStream << "invalid input for 'ren' expected 'ren' {path} {name}" << CRLF;
        return;
    }

    core::CommandRename(p[0], p[1]).Execute(ioStream);
}
