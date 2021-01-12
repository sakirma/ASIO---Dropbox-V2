//
// client.cpp
//
// Created by Bob Polis at 2020-12-02
//

#include <client/Client.hpp>
#include <client/adapters/AdapterMakeDirectory.hpp>
#include <client/adapters/AdapterRename.hpp>
#include <client/adapters/AdapterDelete.hpp>

#include <core/StringUtilities.hpp>

#include <iostream>
#include <cstdlib>
#include <string>
#include <stdexcept>
#include <asio.hpp>
#include <filesystem>
#include <core/DirectoryManager.hpp>
#include <client/ClientSettings.hpp>

using namespace client;

Client::Client() {
    commandFactory_ = std::make_unique<core::CommandFactory>();
    commandFactory_->AddAdapter<adapter::AdapterMakeDirectory>("mkdir")
            .AddAdapter<adapter::AdapterRename>("ren")
            .AddAdapter<adapter::AdapterDelete>("del");
}

void Client::HandleClientRequest(asio::ip::tcp::iostream &server) {
    FileSelection fileSelection{};
    const char *prompt{"avansync> "};

    bool requestHandled = false;
    while (!requestHandled) {
        std::string req;
        std::cout << prompt;
        if (getline(std::cin, req)) {
            auto firstWordEnd = req.find(' ');
            if (firstWordEnd < req.length()) {
                std::string c = req.substr(0, firstWordEnd);
                requestHandled = commandFactory_->ExecuteCommand(server,
                                                stringToLower(c),
                                                req.substr(firstWordEnd + 1));
            } else {
                requestHandled = commandFactory_->ExecuteCommand(server,
                                                stringToLower(req),
                                                {});
            }

//            if (fileSelection.Select(req)) {
//                if (getline(std::cin, req)) {
//                    fileSelection.Send(server, fileSelection);
//                    requestHandled = true;
//                } else {
//                    requestHandled = true;
//                }
//
//            } else {
//                server << req << CRLF;
//                requestHandled = true;
//            }
        }
    }
}

int main() {
    Client client{};
    auto currentPath = std::filesystem::current_path();
    if (!DirectoryManager::FolderOrFileExists(currentPath.string() + "/data")) {
        DirectoryManager::GenerateDirectory(currentPath.string(), "data");
    }
    ClientSettings::GetInstance()->RootFolder = currentPath.string() + "/" + "data";

    try {
        const char *server_address{"localhost"};
        const char *server_port{"12345"};

        asio::ip::tcp::iostream server{server_address, server_port};
        if (!server) throw std::runtime_error("could not connect to server");


        while (server) {
            std::string resp;
            if (getline(server, resp)) {
                resp.erase(resp.end() - 1); // remove '\r'
                std::cout << resp << LF;
                if (resp == "Bye.") break;

                client.HandleClientRequest(server);
            }
        }
    }
    catch (const std::exception &ex) {
        std::cerr << "client: " << ex.what() << '\n';
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}


