#pragma once

#include <array>
#include <filesystem>
#include <string>

namespace flaxdefender {

class CryptoProvider {
public:
    static std::string sha256Hex(const std::string& input);
    static std::string secureHash(const std::string& input);
};

class KeyManager {
public:
    explicit KeyManager(std::filesystem::path storage_directory);
    std::string deriveKey(const std::string& label, const std::string& passphrase) const;

private:
    std::filesystem::path storage_directory_;
};

}  // namespace flaxdefender
