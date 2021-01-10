#pragma once

#include "server/adapters/Adapter.hpp"


namespace server::adapter {
    class AdapterDelete : public Adapter {
    public:
        void Execute(asio::ip::tcp::iostream &ioStream, const std::string &params) const override;
    };
}