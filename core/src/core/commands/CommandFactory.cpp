#include <core/commands/CommandFactory.hpp>
#include <core/commands/CommandInfo.hpp>
#include <core/adapters/AdapterMakeDirectory.hpp>
#include <core/adapters/AdapterDelete.hpp>
#include <core/adapters/AdapterRename.hpp>


using namespace core;

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
