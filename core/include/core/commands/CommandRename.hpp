#pragma once

#include "Command.hpp"

namespace core {
    class CommandRename : public Command {
    public:
        explicit CommandRename(const std::string &path, const std::string &newName);

        bool Execute(asio::ip::tcp::iostream &ioStream, std::string &message) override;

    private:
        const std::string path_;
        const std::string newName_;
    };
}