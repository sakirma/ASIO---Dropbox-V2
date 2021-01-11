#include "server/commands/CommandFactory.hpp"
#include "server/commands/CommandInfo.hpp"
#include "server/adapters/AdapterMakeDirectory.hpp"
#include "server/adapters/AdapterDelete.hpp"
#include "server/adapters/AdapterRename.hpp"


using namespace server;

CommandFactory::CommandFactory() {
    factory["info"] = std::make_unique<CommandInfo>();
    factory["error"] = std::make_unique<CommandInfo>();
    factory["mkdir"] = std::make_unique<adapter::AdapterMakeDirectory>();
    factory["del"] = std::make_unique<adapter::AdapterDelete>();
    factory["ren"] = std::make_unique<adapter::AdapterRename>();
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
