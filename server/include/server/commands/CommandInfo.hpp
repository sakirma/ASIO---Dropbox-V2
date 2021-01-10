#pragma once

#include "Command.hpp"
#include "server/adapters/Adapter.hpp"

namespace server {
    class CommandInfo : public Command, public adapter::Adapter {
    public:
        void Execute(asio::ip::tcp::iostream &ioStream) const override;

        void Execute(asio::ip::tcp::iostream &ioStream, const std::string &params) const override;
    };
}