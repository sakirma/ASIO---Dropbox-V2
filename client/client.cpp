//
// client.cpp
//
// Created by Bob Polis at 2020-12-02
//

#include <iostream>
#include <cstdlib>
#include <string>
#include <stdexcept>
#include <asio.hpp>
#include <filesystem>
#include <fstream>

#include "./DirectoryManager.hpp"

#define CRLF "\r\n"
#define LF "\r"


class FileSelection {
public:
    std::vector<char> buffer{};

    bool Select(const std::string &request) {
        if (request.empty()) {
            return false;
        }

        std::stringstream ss(request);
        std::istream_iterator<std::string> begin(ss);
        std::istream_iterator<std::string> end;
        std::vector<std::string> p(begin, end);

        std::transform(p[0].begin(), p[0].end(), p[0].begin(), ::tolower);

        if (p.size() != 2 || p[0] != "select") {
            return false;
        }

        if (!std::filesystem::exists(p[1])) {
            std::cout << "Given local path does not exist!" << std::endl;
            return false;
        }

        std::string drive{};
        std::string dir{};
        std::string fname{};
        std::string ext{};
        DirectoryManager::SplitPath(p[1], drive, dir, fname, ext);
        std::string fileName = fname + ext;


        std::ifstream file(p[1], std::ios::binary | std::ios::ate);
        if (file.fail()) {
            throw std::invalid_argument("Cannot open file");
        }
        std::streamsize size = file.tellg();
        file.seekg(0, std::ios::beg);

        buffer.clear();
        buffer.resize(size);
        file.read(buffer.data(), size);

        return true;
    }

    void Send(asio::ip::tcp::iostream &server, const FileSelection &fileSelection) {
        server.write(buffer.data(), 14);
        server << CRLF;
    }
};

void HandleClientRequest(asio::ip::tcp::iostream &server,
                         FileSelection &fileSelection) {
    bool requestHandled = false;
    while (!requestHandled) {
        std::string req;
        std::cout << "avansync> ";
        if (getline(std::cin, req)) {

            if (fileSelection.Select(req)) {

                if (getline(std::cin, req)) {

                    fileSelection.Send(server, fileSelection);
                    requestHandled = true;
                } else {
                    requestHandled = true;
                }

            } else {
                server << req << CRLF;
                requestHandled = true;
            }
        }
    }
}

int main() {
    try {
        const char *server_address{"localhost"};
        const char *server_port{"12345"};
        const char *prompt{"avansync> "};

        asio::ip::tcp::iostream server{server_address, server_port};
        if (!server) throw std::runtime_error("could not connect to server");

        FileSelection fileSelection{};

        while (server) {
            std::string resp;
            if (getline(server, resp)) {
                resp.erase(resp.end() - 1); // remove '\r'
                std::cout << resp << LF;
                if (resp == "Bye.") break;

                HandleClientRequest(server, fileSelection);
            }
        }
    }
    catch (const std::exception &ex) {
        std::cerr << "client: " << ex.what() << '\n';
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}


