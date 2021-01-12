#pragma once

#include "core/Adapter.hpp"


namespace client::adapter {
class AdapterDelete : public core::adapter::Adapter {
    public:
        void Execute(asio::ip::tcp::iostream &ioStream, const std::string &params) const override;
    };
}