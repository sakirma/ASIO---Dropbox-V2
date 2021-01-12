#pragma once

#include "Command.hpp"

namespace core {
    class CommandError : public Command {
    public:
        bool Execute(asio::ip::tcp::iostream &ioStream, std::string &message) override;
    };
}