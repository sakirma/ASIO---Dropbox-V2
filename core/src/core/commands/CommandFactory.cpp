#include <core/commands/CommandFactory.hpp>


using namespace core;


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
