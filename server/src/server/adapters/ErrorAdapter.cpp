#include "server/adapters/ErrorAdapter.hpp"

using namespace server;
using namespace server::adapter;


bool ErrorAdapter::Execute(asio::ip::tcp::iostream &ioStream,
                           const std::string &params) const {
    std::vector<std::string> p{};
    if (splitParams(p, params) != 1) {
        ioStream << "invalid input for Error" << CRLF;
        return false;
    }

    ioStream << "Not Implemented" << CRLF;
    return false;
}
