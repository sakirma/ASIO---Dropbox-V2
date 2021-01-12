#include <server/adapters/AdapterMakeDirectory.hpp>
#include <core/commands/CommandMakeDirectory.hpp>

#include <memory>
#include <server/ServerSettings.hpp>

using namespace server;
using namespace server::adapter;

void AdapterMakeDirectory::Execute(asio::ip::tcp::iostream &ioStream, const std::string &params) const {
    std::vector<std::string> p{};
    if (splitParams(p, params) != 2) {
        ioStream << "invalid input for 'mkdir' expected 'mkdir' {parent dir} {folder name}" << CRLF;
        return;
    }
    std::string path = ServerSettings::GetInstance()->RootFolder + "/" + p[0];

    core::CommandMakeDirectory(path, p[1]).Execute(ioStream);
}
