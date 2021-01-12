#pragma once

#include <core/adapters/Adapter.hpp>


namespace core::adapter {
    class AdapterMakeDirectory : public Adapter {
    public:
        void Execute(asio::ip::tcp::iostream &ioStream, const std::string &params) const override;

    public:
        AdapterMakeDirectory() = default;

        ~AdapterMakeDirectory() override = default;

        AdapterMakeDirectory(const AdapterMakeDirectory &other) = delete;

        AdapterMakeDirectory(AdapterMakeDirectory &&other) noexcept {} // move constructor

        AdapterMakeDirectory &operator=(const AdapterMakeDirectory &other) = delete;

        AdapterMakeDirectory &operator=(AdapterMakeDirectory &&other) noexcept { // move assignment
            return *this;
        }
    };
}