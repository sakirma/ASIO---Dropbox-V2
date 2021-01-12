#include <client/adapters/ErrorAdapter.hpp>
#include <iostream>

using namespace client;
using namespace client::adapter;


bool ErrorAdapter::Execute(asio::ip::tcp::iostream &ioStream,
                           const std::string &params) const {
    std::vector<std::string> p{};
    if (splitParams(p, params) != 1) {
        std::cout << "invalid input for Error" << std::endl;
        return false;
    }

    ioStream << "Not Implemented" << CRLF;
    return false;
}
