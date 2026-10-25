#pragma once

#include <string>

namespace flaxdefender {

class CryptoProvider {
public:
    static std::string sha256Hex(const std::string& input);
    static std::string secureHash(const std::string& input);
};

}  // namespace flaxdefender
