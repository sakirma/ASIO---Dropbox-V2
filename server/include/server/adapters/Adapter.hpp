#pragma once

#include <string>
#include <asio/ip/tcp.hpp>

#include <server/Commands/Command.hpp>

namespace server::adapter {
    class Adapter {
    public:
        virtual ~Adapter() = default;

        virtual void Execute(asio::ip::tcp::iostream &ioStream, const std::string &params) const = 0;
    };
}