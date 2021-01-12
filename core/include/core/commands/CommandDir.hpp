#pragma once

#include "Command.hpp"
#include <core/FileInfo.hpp>

#include <filesystem>
#include <vector>

namespace core {

    class CommandDir : public Command {
    public:
        explicit CommandDir(const std::string &path);

        bool Execute(asio::ip::tcp::iostream &ioStream, std::string &message) override;

        std::vector<FileInfo> files {};
    private:
        const std::string path_ {};
    };
}