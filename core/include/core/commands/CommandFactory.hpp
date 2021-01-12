#pragma once

#include "core/adapters/Adapter.hpp"

#include <map>
#include <memory>
#include <string>
#include <vector>

namespace core {
    class CommandFactory {
    private:
        std::map<std::string, std::unique_ptr<adapter::Adapter>> factory{};

    public:
        CommandFactory();

        void ExecuteCommand(asio::ip::tcp::iostream &ioStream,
                            const std::string &commandName,
                            const std::string &params);
    };
}