#pragma once

#include <chrono>
#include <cstddef>
#include <filesystem>
#include <string>
#include <vector>

namespace flaxdefender {

struct ScanResult {
    std::size_t files_scanned{0};
    std::size_t suspicious{0};
    std::chrono::microseconds elapsed{0};
};

class AntivirusScanner {
public:
    explicit AntivirusScanner(std::filesystem::path root = "/");

    ScanResult scanDirectory(const std::filesystem::path& target);

private:
    std::filesystem::path root_;
};

}  // namespace flaxdefender
