#pragma once

#include <asio/basic_socket_iostream.hpp>
#include <core/commands/CommandFactory.hpp>
#include <client/FileSelection.hpp>

#include <memory>

namespace client {
    class Client {
    private:
        std::unique_ptr<core::CommandFactory> commandFactory_ = nullptr;

    public:
        Client();

        void HandleClientRequest(asio::ip::tcp::iostream &server);
    };
}