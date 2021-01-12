#pragma once

#include <string>

namespace core {
    struct FileInfo {
    public:
        FileInfo(std::string name, std::string time)
                : name(std::move(name)), time(std::move(time)) {}

        std::string name{};
        std::string time{};
    };
}