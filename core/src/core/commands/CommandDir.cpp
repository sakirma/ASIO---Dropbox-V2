#include <core/commands/CommandDir.hpp>

#include <core/DirectoryManager.hpp>


using namespace core;

CommandDir::CommandDir(const std::string &path) : path_(std::string(path)) {

}

template<typename TP>
static std::time_t to_time_t(TP tp) {
    using namespace std::chrono;
    auto sctp = time_point_cast<system_clock::duration>(tp - TP::clock::now()
                                                        + system_clock::now());
    return system_clock::to_time_t(sctp);
}

bool CommandDir::Execute(asio::ip::tcp::iostream &ioStream, std::string &message) {
    if (!DirectoryManager::FolderOrFileExists(path_)) {
        message = "Given folder does not exists!";
        return false;
    }

    for (auto &i : std::filesystem::directory_iterator(path_)) {
        auto ftime = std::filesystem::last_write_time(i);
        std::time_t cftime = to_time_t(ftime);

        std::stringstream time;
        time << std::put_time(std::localtime(&cftime), "%Y-%m-%d %H:%M:%S");

        std::string fileType = i.is_directory() ? "D" : "F";

        std::string fileSize = i.is_regular_file() ? std::to_string(i.file_size()) : "0";

        files.emplace_back(
                i.path().filename().string(),
                time.str(),
                fileType,
                fileSize
        );
    }


    return true;
}
