#include "server/Adapters/AdapterMakeDirectory.hpp"
#include <server/Commands/CommandMakeDirectory.hpp>
#include <memory>

using namespace server;
using namespace server::adapter;

void AdapterMakeDirectory::Execute(asio::ip::tcp::iostream &ioStream, const std::string &params) const {
    std::stringstream ss(params);
    std::istream_iterator<std::string> begin(ss);
    std::istream_iterator<std::string> end;
    std::vector<std::string> p(begin, end);

    if (p.size() != 2) {
        ioStream << "invalid input for 'mkdir' expected 'mkdir' {parent dir} {folder name}" << CRLF;
        return;
    }

    auto cmd = CommandMakeDirectory(p[0], p[1]);
    cmd.Execute(ioStream);
}
