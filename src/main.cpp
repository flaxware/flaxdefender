#include <filesystem>
#include <iostream>
#include <string>

#include "flaxdefender/core/Version.h"
#include "flaxdefender/security/Cleaner.h"
#include "flaxdefender/security/FirewallManager.h"
#include "flaxdefender/security/KeyManager.h"
#include "flaxdefender/security/Monitor.h"
#include "flaxdefender/security/Scanner.h"

int main() {
    std::cout << "FlaxDefender v" << flaxdefender::version_string() << "\n";
    std::cout << "Security center initialized.\n";

    flaxdefender::FirewallManager firewall;
    firewall.addRule({"INPUT", "drop", "tcp 22", "Lock down SSH by default"});

    flaxdefender::AntivirusScanner scanner{
        std::filesystem::path{"/usr/share"}
    };
    auto scan = scanner.scanDirectory(std::filesystem::path{"/usr/share"});
    std::cout << "Files inspected: " << scan.files_scanned << "\n";
    std::cout << "Suspicious findings: " << scan.suspicious << "\n";

    flaxdefender::MetadataCleaner cleaner;
    auto cleanup = cleaner.cleanTemporaryArtifacts(std::filesystem::path{"/tmp"});
    std::cout << "Cleanup entries: " << cleanup.entries_removed << "\n";

    flaxdefender::SystemMonitor monitor;
    auto snapshot = monitor.snapshot();
    std::cout << "CPU load: " << snapshot.cpu_load << "%\n";

    flaxdefender::KeyManager km{std::filesystem::path{"/var/lib/flaxdefender/keys"}};
    auto key = km.deriveKey("default", "example-passphrase");
    std::cout << "Derived key length: " << key.size() << " bytes\n";

    return 0;
}
