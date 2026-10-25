#include "flaxdefender/core/Version.h"

#include <string>

namespace flaxdefender {

std::string version_string() {
    return std::string{kVersion};
}

}  // namespace flaxdefender
