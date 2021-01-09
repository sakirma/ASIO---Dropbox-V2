#pragma once

#include <string>
#include <mutex>

namespace server {
    class ServerSettings {
    private:
        static ServerSettings *instance_;
        static std::mutex mutex_;

    protected:
        ServerSettings() = default;

        ~ServerSettings() = default;

    public:
        std::string RootFolder{};

        ServerSettings(ServerSettings &other) = delete;

        void operator=(const ServerSettings &) = delete;


        static ServerSettings *GetInstance();
    };
}