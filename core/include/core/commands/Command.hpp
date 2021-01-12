#pragma once

#define CRLF "\r\n"
#define LF "\n"
#define OK "OK"


#include <asio/ip/tcp.hpp>

namespace core {
    class Command {
    public:
        virtual ~Command() = default;

        virtual void Execute(asio::ip::tcp::iostream &ioStream) const = 0;
    };
}