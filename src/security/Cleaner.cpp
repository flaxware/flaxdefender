#include "flaxdefender/security/Cleaner.h"

#include <filesystem>
#include <system_error>

namespace flaxdefender {

CleanupResult MetadataCleaner::cleanTemporaryArtifacts(const std::filesystem::path& root) const {
    CleanupResult result{};
    if (!std::filesystem::exists(root)) {
        return result;
    }

    std::error_code ec;
    for (const auto& entry : std::filesystem::directory_iterator(root, ec)) {
        if (entry.is_regular_file(ec)) {
            const auto size = std::filesystem::file_size(entry.path(), ec);
            std::filesystem::remove(entry.path(), ec);
            if (!ec) {
                ++result.entries_removed;
                result.bytes_freed += static_cast<std::size_t>(size);
            }
        }
    }

    return result;
}

CleanupResult MetadataCleaner::cleanBrowserCache(const std::filesystem::path& root) const {
    return cleanTemporaryArtifacts(root);
}

}  // namespace flaxdefender
