#pragma once

#include "Command.hpp"

namespace core {
    class CommandDelete : public Command {
    public:
        CommandDelete(const std::string& path);
        bool Execute(asio::ip::tcp::iostream &ioStream, std::string &message) const override;

    private:
        std::string delete_path_;
    };
}