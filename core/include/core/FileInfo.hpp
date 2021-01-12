#pragma once

#include <string>

namespace core {
    struct FileInfo {
    public:
        FileInfo(std::string name, std::string time, std::string fileType, std::string fileSize)
                : name(std::move(name)),
                  time(std::move(time)),
                  fileType(std::move(fileType)),
                  fileSize(std::move(fileSize)){}

        std::string fileType{};
        std::string name{};
        std::string time{};
        std::string fileSize{};
    };
}