#pragma once

#include <core/commands/Command.hpp>

#include <string>
#include <asio/ip/tcp.hpp>

namespace core::adapter {
    class Adapter {
    public:
        virtual ~Adapter() = default;

        virtual bool Execute(asio::ip::tcp::iostream &ioStream, const std::string &params) const = 0;

        static int splitParams(std::vector<std::string> &out, const std::string &params) {
            std::stringstream ss(params);
            std::istream_iterator<std::string> begin(ss);
            std::istream_iterator<std::string> end;
            std::vector<std::string> p(begin, end);

            std::copy(p.begin(),
                      p.end(),
                      std::back_inserter(out));

            return out.size();
        }
    };
}