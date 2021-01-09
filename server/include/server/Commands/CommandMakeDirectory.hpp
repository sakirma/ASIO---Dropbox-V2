#pragma once

#include "server/Commands/Command.hpp"

namespace server {
    class CommandMakeDirectory : public Command {
    public:
        void Execute(asio::ip::tcp::iostream &ioStream) const override;

    private:
        std::string parentDir_{};
        std::string dirName_{};

    public:
        CommandMakeDirectory(const std::string &parentDir, const std::string &dirName) {
            parentDir_ = parentDir;
            dirName_ = dirName;
        }

        ~CommandMakeDirectory() override = default;

        CommandMakeDirectory(const CommandMakeDirectory &other) = delete;

        CommandMakeDirectory(CommandMakeDirectory &&other) noexcept {} // move constructor

        CommandMakeDirectory &operator=(const CommandMakeDirectory &other) = delete;

        CommandMakeDirectory &operator=(CommandMakeDirectory &&other) noexcept { // move assignment
            return *this;
        }
    };
}


