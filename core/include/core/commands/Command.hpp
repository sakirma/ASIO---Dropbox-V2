#pragma once

#define CRLF "\r\n"
#define LF "\n"
#define OK "OK"
#define BREAK "[BREAK]"


#include <asio/ip/tcp.hpp>

namespace core {
    class Command {
    public:
        virtual ~Command() = default;

        virtual bool Execute(asio::ip::tcp::iostream &ioStream, std::string &message) = 0;
    };
}