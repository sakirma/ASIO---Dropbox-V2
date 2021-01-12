#include <client/FileSelection.hpp>
#include <filesystem>
#include <iostream>
#include <core/DirectoryManager.hpp>
#include <fstream>

using namespace client;

bool FileSelection::Select(const std::string &request) {
    if (request.empty()) {
        return false;
    }

    std::stringstream ss(request);
    std::istream_iterator<std::string> begin(ss);
    std::istream_iterator<std::string> end;
    std::vector<std::string> p(begin, end);

    std::transform(p[0].begin(), p[0].end(), p[0].begin(), ::tolower);

    if (p.size() != 2 || p[0] != "select") {
        return false;
    }

    if (!std::filesystem::exists(p[1])) {
        std::cout << "Given local path does not exist!" << std::endl;
        return false;
    }

    std::string drive{};
    std::string dir{};
    std::string fname{};
    std::string ext{};
    DirectoryManager::SplitPath(p[1], drive, dir, fname, ext);
    std::string fileName = fname + ext;


    std::ifstream file(p[1], std::ios::binary | std::ios::ate);
    if (file.fail()) {
        throw std::invalid_argument("Cannot open file");
    }
    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);

    buffer.clear();
    buffer.resize(size);
    file.read(buffer.data(), size);

    return true;
}
