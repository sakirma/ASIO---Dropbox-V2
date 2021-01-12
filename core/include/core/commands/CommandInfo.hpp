#pragma once

#include "Command.hpp"
#include "core/Adapter.hpp"

namespace core {
    class CommandInfo : public Command, public adapter::Adapter {
    public:
        bool Execute(asio::ip::tcp::iostream &ioStream, std::string &message) const override;

        bool Execute(asio::ip::tcp::iostream &ioStream, const std::string &params) const override;
    };
}