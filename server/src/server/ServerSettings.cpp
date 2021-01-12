#include <server/ServerSettings.hpp>

using namespace server;

ServerSettings *ServerSettings::instance_{nullptr};
std::mutex ServerSettings::mutex_;

ServerSettings *ServerSettings::GetInstance() {
    std::lock_guard<std::mutex> lock(mutex_);
    if (instance_ == nullptr) {
        instance_ = new ServerSettings();
    }
    return instance_;
}