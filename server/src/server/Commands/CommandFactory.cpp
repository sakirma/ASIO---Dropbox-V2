#include "server/Commands/CommandFactory.hpp"

#include "server/Commands/InfoCommand.hpp"
#include "server/Adapters/AdapterMakeDirectory.hpp"


using namespace server;

CommandFactory::CommandFactory() {
    factory["info"] = std::make_unique<InfoCommand>();
    factory["mkdir"] = std::make_unique<adapter::AdapterMakeDirectory>();
}

void CommandFactory::ExecuteCommand(asio::ip::tcp::iostream &ioStream,
                                    const std::string &commandName,
                                    const std::string &params) {
    auto it = factory.find(commandName);
    if (it == factory.end()) {
        ioStream << "command name: '" + commandName + "' does not exists" << CRLF;
        return;
    }

    auto &command = it->second;

    command->Execute(ioStream, params);
}
