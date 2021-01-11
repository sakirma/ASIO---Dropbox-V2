#pragma once

#include "Command.hpp"

namespace server {
    class CommandError : public Command {
    public:
        void Execute(asio::ip::tcp::iostream &ioStream) const override;
    };
}