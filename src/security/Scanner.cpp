#include "flaxdefender/security/Scanner.h"

#include <algorithm>
#include <chrono>
#include <filesystem>
#include <fstream>

namespace flaxdefender {

AntivirusScanner::AntivirusScanner(std::filesystem::path root)
    : root_(std::move(root)) {}

ScanResult AntivirusScanner::scanDirectory(const std::filesystem::path& target) {
    const auto start = std::chrono::steady_clock::now();
    ScanResult result{};
    std::filesystem::path base = target.empty() ? root_ : target;

    if (!std::filesystem::exists(base)) {
        return result;
    }

    std::filesystem::recursive_directory_iterator it(base), end;
    for (; it != end; ++it) {
        if (std::filesystem::is_regular_file(it->path())) {
            ++result.files_scanned;
            std::ifstream input(it->path(), std::ios::binary);
            if (!input) {
                ++result.suspicious;
                continue;
            }
            std::string buffer((std::istreambuf_iterator<char>(input)), {});
            auto suspicious = std::ranges::count(buffer, '0');
            if (suspicious > 0 && buffer.size() > 1024) {
                ++result.suspicious;
            }
        }
    }

    const auto stop = std::chrono::steady_clock::now();
    result.elapsed = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    return result;
}

}  // namespace flaxdefender
