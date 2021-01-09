#pragma once

#define CRLF "\r\n"
#define LF "\n"


#include <asio/ip/tcp.hpp>

namespace server {
    class Command {
    public:
        virtual ~Command() = default;

        virtual void Execute(asio::ip::tcp::iostream &ioStream) const = 0;
    };
}