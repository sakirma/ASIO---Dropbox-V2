#include "core/adapters/ErrorAdapter.hpp"

using namespace core;
using namespace core::adapter;


void ErrorAdapter::Execute(asio::ip::tcp::iostream &ioStream,
                           const std::string &params) const {
    std::vector<std::string> p{};
    if (splitParams(p, params) != 1) {
        ioStream << "invalid input for Error" << CRLF;
        return;
    }


}
