#include <core/commands/CommandError.hpp>

using namespace core;


bool CommandError::Execute(asio::ip::tcp::iostream &ioStream, std::string &message) const {
    message = "this function is not implemented yet";
    return false;
}
