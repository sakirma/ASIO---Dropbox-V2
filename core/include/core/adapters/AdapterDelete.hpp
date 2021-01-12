#pragma once

#include <core/adapters/Adapter.hpp>


namespace core::adapter {
class AdapterDelete : public Adapter {
    public:
        void Execute(asio::ip::tcp::iostream &ioStream, const std::string &params) const override;
    };
}