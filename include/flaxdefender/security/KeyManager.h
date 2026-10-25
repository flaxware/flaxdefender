#pragma once

#include <filesystem>
#include <string>

namespace flaxdefender {

class KeyManager {
public:
    explicit KeyManager(std::filesystem::path storage_directory);
    std::string deriveKey(const std::string& label, const std::string& passphrase) const;

private:
    std::filesystem::path storage_directory_;
};

}  // namespace flaxdefender
