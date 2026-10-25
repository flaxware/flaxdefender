#pragma once

#include <filesystem>
#include <string>
#include <vector>

namespace flaxdefender {

class FirewallManager {
public:
    struct Rule {
        std::string chain;
        std::string action;
        std::string target;
        std::string description;
    };

    void addRule(Rule rule);
    void removeRule(const std::string& target);
    std::vector<Rule> rules() const;
    bool saveToFile(const std::filesystem::path& path) const;

private:
    std::vector<Rule> rules_;
};

}  // namespace flaxdefender
