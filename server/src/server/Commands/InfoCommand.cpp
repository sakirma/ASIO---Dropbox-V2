#include "server/Commands/InfoCommand.hpp"

using namespace server;

void InfoCommand::Execute(asio::ip::tcp::iostream &ioStream) const {

}

void InfoCommand::Execute(asio::ip::tcp::iostream &ioStream, const std::string &params) const {
    ioStream << "AvansSync server 1.0, copyright (c) 2021 Huseyin Caliskan." << CRLF;
}