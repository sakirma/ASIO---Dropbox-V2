#pragma once

#include "Command.hpp"

#include <map>
#include <memory>
#include <string>
#include <vector>

namespace server {
    class CommandFactory {
    private:
        std::map<std::string, std::unique_ptr<Command>> factory{};

    public:
        void ExecuteCommand(asio::ip::tcp::iostream &ioStream,
                            const std::string &commandName,
                            const std::vector<std::string> &params);

    public:
        CommandFactory();

        ~CommandFactory() = default;

        CommandFactory(const CommandFactory &other) = delete;

        CommandFactory(CommandFactory &&other) noexcept {} // move constructor

        CommandFactory &operator=(const CommandFactory &other) = delete;

        CommandFactory &operator=(CommandFactory &&other) noexcept { // move assignment
            return *this;
        }
    };
}