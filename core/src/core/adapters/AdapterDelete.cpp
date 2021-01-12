#include <core/adapters/AdapterDelete.hpp>
#include <core/commands/CommandDelete.hpp>

using namespace core;
using namespace core::adapter;

void AdapterDelete::Execute(asio::ip::tcp::iostream &ioStream, const std::string &params) const {
    std::vector<std::string> p{};
    if (splitParams(p, params) != 1) {
        ioStream << "invalid input for 'del' expected 'del' {path}" << CRLF;
        return;
    }

    core::CommandDelete(p[0]).Execute(ioStream);
}
