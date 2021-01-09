#pragma once

#include "Command.hpp"
#include "server/Adapters/Adapter.hpp"

namespace server {
    class InfoCommand : public Command, public Adapter {
    public:
        void Execute(asio::ip::tcp::iostream &ioStream) const override;
        void Execute(asio::ip::tcp::iostream &ioStream, const std::string &params) const override;

    public:
        InfoCommand() = default;

        ~InfoCommand() override = default;

        InfoCommand(const InfoCommand &other) = delete;

        InfoCommand(InfoCommand &&other) noexcept {} // move constructor

        InfoCommand &operator=(const InfoCommand &other) = delete;

        InfoCommand &operator=(InfoCommand &&other) noexcept { // move assignment
            return *this;
        }
    };
}