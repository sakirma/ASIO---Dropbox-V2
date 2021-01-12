//
// server.cpp
//
// Created by Bob Polis at 2020-12-02
//



#include <core/commands/CommandFactory.hpp>
#include <core/DirectoryManager.hpp>
#include <server/StringUtilities.hpp>
#include <server/ServerSettings.hpp>

#include <algorithm>
#include <memory>
#include <iostream>
#include <cstdlib>
#include <string>
#include <asio.hpp>
#include <filesystem>

#include <server/adapters/AdapterMakeDirectory.hpp>
#include <server/adapters/AdapterDelete.hpp>
#include <server/adapters/AdapterRename.hpp>
#include <core/commands/CommandInfo.hpp>


using namespace server;
using namespace server::adapter;

int main() {
    try {
        const int server_port{12345};

        asio::io_context io_context;
        asio::ip::tcp::acceptor server{io_context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), server_port)};


        auto commandFactory = std::make_unique<core::CommandFactory>();
        commandFactory->AddAdapter<core::CommandInfo>("info")
//                        .AddAdapter<core::CommandError>()
                        .AddAdapter<AdapterMakeDirectory>("mkdir")
                        .AddAdapter<AdapterDelete>("del")
                        .AddAdapter<AdapterRename>("ren");

        auto currentPath = std::filesystem::current_path();
        if (!DirectoryManager::FolderOrFileExists(currentPath.string() + "/data")) {
            DirectoryManager::GenerateDirectory(currentPath.string(), "data");
        }
        server::ServerSettings::GetInstance()->RootFolder = currentPath.string() + "/" + "data";

        for (;;) {
            std::cerr << "waiting for client to connect\n";
            asio::ip::tcp::iostream client;
            server.accept(client.socket());
            std::cerr << "client connected from " << client.socket().local_endpoint() << LF;
            client << "Welcome to AvanSync server 1.0" << CRLF;
            for (;;) {
                std::string request;
                getline(client, request);
                request.erase(request.end() - 1); // remove '\r'
                std::cerr << "client says: " << request << LF;

                if (request == "quit") {
                    client << "Bye." << CRLF;
                    std::cerr << "will disconnect from client " << client.socket().local_endpoint() << LF;
                    break;
                } else {
                    auto firstWordEnd = request.find(' ');
                    if (firstWordEnd < request.length()) {
                        std::string c = request.substr(0, firstWordEnd);
                        commandFactory->ExecuteCommand(client,
                                                       stringToLower(c),
                                                       request.substr(firstWordEnd + 1));
                    } else {
                        commandFactory->ExecuteCommand(client,
                                                       stringToLower(request),
                                                       {});
                    }
                }
            }
        }

    }
    catch (const std::exception &ex) {
        std::cerr << "server: " << ex.what() << '\n';
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}