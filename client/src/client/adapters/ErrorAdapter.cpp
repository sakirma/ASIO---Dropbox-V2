#include <client/adapters/ErrorAdapter.hpp>

using namespace client;
using namespace client::adapter;


void ErrorAdapter::Execute(asio::ip::tcp::iostream &ioStream,
                           const std::string &params) const {
    std::vector<std::string> p{};
    if (splitParams(p, params) != 1) {
        ioStream << "invalid input for Error" << CRLF;
        return;
    }

    ioStream << "Not Implemented" << CRLF;
}
