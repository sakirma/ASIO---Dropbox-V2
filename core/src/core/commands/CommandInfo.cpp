#include "core/commands/CommandInfo.hpp"

using namespace core;

bool CommandInfo::Execute(asio::ip::tcp::iostream &ioStream, std::string &message)  {
    message = "this function should not be used";
    return false;
}

bool CommandInfo::Execute(asio::ip::tcp::iostream &ioStream, const std::string &params) const {
    ioStream << "AvansSync server 1.0, copyright (c) 2021 Huseyin Caliskan." << CRLF;
    return true;
}