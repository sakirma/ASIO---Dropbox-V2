#pragma once

#include "Command.hpp"

namespace core {
    class CommandMakeDirectory : public Command {
    public:
        bool Execute(asio::ip::tcp::iostream &ioStream, std::string &message) override;

    private:
        std::string path_{};
        std::string newName_{};

    public:
        CommandMakeDirectory(const std::string &path, const std::string &newName) {
            path_ = path;
            newName_ = newName;
        }
    };
}


