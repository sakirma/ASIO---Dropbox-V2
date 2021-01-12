#pragma once

#include "core/Adapter.hpp"


namespace client::adapter {
    class AdapterMakeDirectory : public core::adapter::Adapter {
    public:
        void Execute(asio::ip::tcp::iostream &ioStream, const std::string &params) const override;
    };
}