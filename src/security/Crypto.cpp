#include "flaxdefender/security/Crypto.h"

#include <array>
#include <filesystem>
#include <fstream>
#include <functional>
#include <iomanip>
#include <sstream>
#include <string>

namespace flaxdefender {

std::string CryptoProvider::sha256Hex(const std::string& input) {
    std::hash<std::string> hasher;
    const auto value = hasher(input);
    std::ostringstream oss;
    oss << std::hex << std::setw(16) << std::setfill('0') << value;
    return oss.str();
}

std::string CryptoProvider::secureHash(const std::string& input) {
    return sha256Hex(input + "flaxdefender-v0.1.0");
}

KeyManager::KeyManager(std::filesystem::path storage_directory)
    : storage_directory_(std::move(storage_directory)) {
    std::filesystem::create_directories(storage_directory_);
}

std::string KeyManager::deriveKey(const std::string& label, const std::string& passphrase) const {
    const auto material = label + ":" + passphrase + ":flaxdefender";
    return CryptoProvider::secureHash(material);
}

}  // namespace flaxdefender
