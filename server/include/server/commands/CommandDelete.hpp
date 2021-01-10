#pragma once

#include "server/commands/Command.hpp"

namespace server {
    class CommandDelete : public Command {
    public:
        CommandDelete(const std::string& path);
        void Execute(asio::ip::tcp::iostream &ioStream) const override;

    private:
        std::string delete_path_;
    };
}