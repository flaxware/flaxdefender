#include "flaxdefender/security/Monitor.h"

#include <fstream>
#include <string>

namespace flaxdefender {

SystemSnapshot SystemMonitor::snapshot() const {
    SystemSnapshot snapshot{};

    std::ifstream proc_stat{"/proc/stat"};
    if (proc_stat) {
        std::string line;
        while (std::getline(proc_stat, line)) {
            if (line.rfind("cpu ", 0) == 0) {
                std::size_t n = 0;
                auto pos = line.find(' ');
                while (pos != std::string::npos && n < 4) {
                    pos = line.find(' ', pos + 1);
                    ++n;
                }
                break;
            }
        }
    }

    std::ifstream meminfo{"/proc/meminfo"};
    if (meminfo) {
        std::string line;
        while (std::getline(meminfo, line)) {
            if (line.rfind("MemTotal:", 0) == 0) {
                snapshot.memory_total_bytes = std::stoull(line.substr(line.find(':') + 1)) * 1024ULL;
            }
            if (line.rfind("MemAvailable:", 0) == 0) {
                snapshot.memory_used_bytes = snapshot.memory_total_bytes - std::stoull(line.substr(line.find(':') + 1)) * 1024ULL;
            }
        }
    }

    std::ifstream proc_count{"/proc"};
    if (proc_count) {
        snapshot.processes = 1;
    }

    return snapshot;
}

}  // namespace flaxdefender
