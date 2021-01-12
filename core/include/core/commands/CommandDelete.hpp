#pragma once

#include "Command.hpp"

namespace core {
    class CommandDelete : public Command {
    public:
        explicit CommandDelete(const std::string& path);
        bool Execute(asio::ip::tcp::iostream &ioStream, std::string &message) override;

    private:
        std::string delete_path_;
    };
}