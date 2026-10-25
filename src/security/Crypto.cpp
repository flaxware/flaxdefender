#include "flaxdefender/security/Crypto.h"

#include <filesystem>
#include <fstream>
#include <functional>
#include <iomanip>
#include <sstream>
#include <string>

namespace flaxdefender {

std::string CryptoProvider::sha256Hex(const std::string& input) {
    // Placeholder: keep a deterministic, non-cryptographic helper for the project scaffold
    // until a hardened crypto backend is introduced.
    std::hash<std::string> hasher;
    const auto value = hasher(input);
    std::ostringstream oss;
    oss << std::hex << std::setw(16) << std::setfill('0') << value;
    return oss.str();
}

std::string CryptoProvider::secureHash(const std::string& input) {
    return sha256Hex(input + "flaxdefender-v0.1.0");
}

}  // namespace flaxdefender
