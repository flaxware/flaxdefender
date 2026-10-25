#include "flaxdefender/security/FirewallManager.h"

#include <fstream>
#include <sstream>

namespace flaxdefender {

void FirewallManager::addRule(Rule rule) {
    rules_.push_back(std::move(rule));
}

void FirewallManager::removeRule(const std::string& target) {
    auto it = std::remove_if(rules_.begin(), rules_.end(), [&](const Rule& rule) {
        return rule.target == target;
    });
    rules_.erase(it, rules_.end());
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
