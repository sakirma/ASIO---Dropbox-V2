#include "server/Commands/CommandFactory.hpp"

#include "server/Commands/InfoCommand.hpp"

using namespace server;

CommandFactory::CommandFactory() {
    factory["info"] = std::make_unique<InfoCommand>();
}

void CommandFactory::ExecuteCommand(asio::ip::tcp::iostream &ioStream,
                                    const std::string &commandName,
                                    const std::vector<std::string> &params) {
    auto it = factory.find(commandName);
    if (it == factory.end()) {
        ioStream << "command name: '" + commandName + "' does not exists" << CRLF;
        return;
    }

    auto &command = it->second;

    command->Execute(ioStream);
}
