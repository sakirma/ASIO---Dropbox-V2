#include "core/commands/CommandInfo.hpp"

using namespace core;

void CommandInfo::Execute(asio::ip::tcp::iostream &ioStream) const {

}

void CommandInfo::Execute(asio::ip::tcp::iostream &ioStream, const std::string &params) const {
    ioStream << "AvansSync server 1.0, copyright (c) 2021 Huseyin Caliskan." << CRLF;
}