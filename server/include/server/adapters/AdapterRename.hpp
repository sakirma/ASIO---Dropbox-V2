#pragma once


#include "Adapter.hpp"

namespace server::adapter {
    class AdapterRename : public Adapter {
    public:
        void Execute(asio::ip::tcp::iostream &ioStream, const std::string &params) const override;
    };
}