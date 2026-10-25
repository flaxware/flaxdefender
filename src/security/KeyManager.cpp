#include "flaxdefender/security/Crypto.h"

#include <filesystem>
#include <fstream>
#include <sstream>

namespace flaxdefender {

KeyManager::KeyManager(std::filesystem::path storage_directory)
    : storage_directory_(std::move(storage_directory)) {
    std::filesystem::create_directories(storage_directory_);
}

std::string KeyManager::deriveKey(const std::string& label, const std::string& passphrase) const {
    const auto material = label + ":" + passphrase + ":flaxdefender";
    return CryptoProvider::secureHash(material);
}

}  // namespace flaxdefender
