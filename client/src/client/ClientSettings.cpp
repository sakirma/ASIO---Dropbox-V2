#include <client/ClientSettings.hpp>

using namespace client;

ClientSettings *ClientSettings::instance_{nullptr};
std::mutex ClientSettings::mutex_;

ClientSettings *ClientSettings::GetInstance() {
    std::lock_guard<std::mutex> lock(mutex_);
    if (instance_ == nullptr) {
        instance_ = new ClientSettings();
    }
    return instance_;
}