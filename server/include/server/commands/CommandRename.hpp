#pragma once

#include <server/commands/Command.hpp>

namespace server {
    class CommandRename : public Command {
    public:
        explicit CommandRename(const std::string &path, const std::string &newName);

        void Execute(asio::ip::tcp::iostream &ioStream) const override;

    private:
        const std::string path_;
        const std::string newName_;
    };
}