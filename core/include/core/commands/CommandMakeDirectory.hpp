#pragma once

#include "Command.hpp"

namespace core {
    class CommandMakeDirectory : public Command {
    public:
        void Execute(asio::ip::tcp::iostream &ioStream) const override;

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


