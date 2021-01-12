#pragma once

#include <core/commands/Command.hpp>

namespace core {
    class CommandPut : public Command {
    public:
        bool Execute(asio::ip::tcp::iostream &ioStream, std::string &message) override;

        explicit CommandPut(const std::string &path)
                : path_(std::string(path)) {

        }

        std::vector<char> buffer{};

    private:
        std::string path_{};
    };
}