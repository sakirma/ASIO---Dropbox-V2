#pragma once

#include "Command.hpp"

namespace core {
    class CommandError : public Command {
    public:
        void Execute(asio::ip::tcp::iostream &ioStream) const override;
    };
}