#pragma once


#include "core/Adapter.hpp"

namespace server::adapter {
    class AdapterRename : public core::adapter::Adapter {
    public:
        bool Execute(asio::ip::tcp::iostream &ioStream,
                     const std::string &params) const override;
    };
}