#pragma once

#include <cstddef>
#include <filesystem>
#include <string>

namespace flaxdefender {

struct CleanupResult {
    std::size_t entries_removed{0};
    std::size_t bytes_freed{0};
};

class MetadataCleaner {
public:
    CleanupResult cleanTemporaryArtifacts(const std::filesystem::path& root) const;
    CleanupResult cleanBrowserCache(const std::filesystem::path& root) const;
};

}  // namespace flaxdefender
