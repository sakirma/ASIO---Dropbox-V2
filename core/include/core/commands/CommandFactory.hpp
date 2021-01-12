#pragma once

#include <core/Adapter.hpp>

#include <map>
#include <memory>
#include <string>
#include <vector>

namespace core {
    class CommandFactory {
    private:
        std::map<std::string, std::unique_ptr<adapter::Adapter>> factory{};

    public:
        bool ExecuteCommand(asio::ip::tcp::iostream &ioStream,
                            const std::string &commandName,
                            const std::string &params);

        template<class T, typename... Args>
        CommandFactory &AddAdapter(const std::string &nameCommand, Args &&... constructor_arguments) {
            static_assert(std::is_convertible<T*, adapter::Adapter*>::value,
                          "This function can only construct"
                          " concrete subclasses of Adapter");
            static_assert(std::is_constructible<T, Args...>::value,
                    "The requested type cannot be constructed from"
                    "the arguments provided");

            factory[nameCommand] = std::make_unique<T>(std::forward<Args>(constructor_arguments)...);
            return *this;
        }
    };
}