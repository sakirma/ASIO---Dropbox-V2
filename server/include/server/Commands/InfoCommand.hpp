#pragma once

#include "Command.hpp"


namespace server {
    class InfoCommand : public Command {
    public:
        void Execute(asio::ip::tcp::iostream &ioStream) const override;
    };
}