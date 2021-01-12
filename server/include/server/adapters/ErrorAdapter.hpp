#pragma once


#include "core/Adapter.hpp"

namespace server::adapter {
    class ErrorAdapter : public core::adapter::Adapter {
    public:
        void Execute(asio::ip::tcp::iostream &ioStream, const std::string &params) const override;
    };
}