#include <server/adapters/AdapterDelete.hpp>
#include <server/commands/CommandDelete.hpp>

using namespace server;
using namespace server::adapter;

void AdapterDelete::Execute(asio::ip::tcp::iostream &ioStream, const std::string &params) const {
    std::stringstream ss(params);
    std::istream_iterator<std::string> begin(ss);
    std::istream_iterator<std::string> end;
    std::vector<std::string> p(begin, end);

    if (p.size() != 1) {
        ioStream << "invalid input for 'del' expected 'del' {path}" << CRLF;
        return;
    }

    CommandDelete(p[0]).Execute(ioStream);
}
