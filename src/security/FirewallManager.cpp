#include "flaxdefender/security/FirewallManager.h"

#include <algorithm>
#include <fstream>
#include <sstream>

namespace flaxdefender {

void FirewallManager::addRule(Rule rule) {
    rules_.push_back(std::move(rule));
}

void FirewallManager::removeRule(const std::string& target) {
    std::erase_if(rules_, [&](const Rule& rule) {
        return rule.target == target;
    });
}

std::vector<FirewallManager::Rule> FirewallManager::rules() const {
    return rules_;
}

bool FirewallManager::saveToFile(const std::filesystem::path& path) const {
    std::ofstream out(path, std::ios::out | std::ios::trunc);
    if (!out) {
        return false;
    }

    for (const auto& rule : rules_) {
        out << rule.chain << " " << rule.action << " " << rule.target;
        if (!rule.description.empty()) {
            out << " # " << rule.description;
        }
        out << '\n';
    }

    return out.good();
}

}  // namespace flaxdefender
