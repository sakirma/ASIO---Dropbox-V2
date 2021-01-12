#pragma once

#include <core/commands/Command.hpp>


namespace client {
    class FileSelection {
    public:
        std::vector<char> buffer{};

        bool Select(const std::string &request);

        void Send(asio::ip::tcp::iostream &server, const FileSelection &fileSelection) {
            server.write(buffer.data(), 14);
            server << CRLF;
        }
    };
}