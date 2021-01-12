#include <core/adapters/AdapterMakeDirectory.hpp>
#include <core/commands/CommandMakeDirectory.hpp>

#include <memory>

using namespace core;
using namespace core::adapter;

void AdapterMakeDirectory::Execute(asio::ip::tcp::iostream &ioStream, const std::string &params) const {
    std::vector<std::string> p{};
    if (splitParams(p, params) != 2) {
        ioStream << "invalid input for 'mkdir' expected 'mkdir' {parent dir} {folder name}" << CRLF;
        return;
    }

    core::CommandMakeDirectory(p[0], p[1]).Execute(ioStream);
}
