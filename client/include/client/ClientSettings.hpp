#pragma once

#include <string>
#include <mutex>

namespace client {
    class ClientSettings {
    private:
        static ClientSettings *instance_;
        static std::mutex mutex_;

    protected:
        ClientSettings() = default;

        ~ClientSettings() = default;

    public:
        std::string RootFolder{};

        ClientSettings(ClientSettings &other) = delete;

        void operator=(const ClientSettings &) = delete;


        static ClientSettings *GetInstance();
    };
}