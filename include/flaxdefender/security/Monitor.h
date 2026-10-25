#pragma once

#include <cstddef>
#include <filesystem>
#include <string>

namespace flaxdefender {

struct SystemSnapshot {
    double cpu_load{0.0};
    std::size_t memory_used_bytes{0};
    std::size_t memory_total_bytes{0};
    std::size_t processes{0};
    std::size_t disk_used_bytes{0};
    std::size_t disk_total_bytes{0};
};

class SystemMonitor {
public:
    SystemSnapshot snapshot() const;
};

}  // namespace flaxdefender
