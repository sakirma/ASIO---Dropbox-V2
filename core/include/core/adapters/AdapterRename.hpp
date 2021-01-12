#pragma once


#include "Adapter.hpp"

namespace core::adapter {
    class AdapterRename : public Adapter {
    public:
        void Execute(asio::ip::tcp::iostream &ioStream, const std::string &params) const override;
    };
}