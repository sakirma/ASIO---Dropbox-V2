#pragma once


#include "Adapter.hpp"

namespace server::adapter {
    class ErrorAdapter : public Adapter {
    public:
        void Execute(asio::ip::tcp::iostream &ioStream, const std::string &params) const override;
    };
}