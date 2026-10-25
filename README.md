# FlaxDefender

FlaxDefender is a Linux security center designed for lightweight, portable, and modular protection. The project is intentionally structured as a clean C++ foundation for a security suite that can be embedded into a live-build environment, integrated with XFCE4, and operated as a centralized control plane for security and maintenance tasks.

The initial version is v0.1.0 and is clearly scoped as a production-ready foundation rather than a replacement for a full commercial endpoint security engine. The objective is to provide a safe, maintainable, and extensible base that can later grow into a real-time antivirus, firewall controller, metadata cleaner, and monitoring toolkit.

## Goals

- Desktop security center for XFCE4 and Linux systems.
- Lightweight design with low dependency footprint.
- Full-disk encryption and encrypted-user-data defaults as a policy layer.
- Modular security services: firewall, monitoring, metadata cleaning, Tor routing controls, and malware scanning.
- Strong crypto defaults using modern standards and careful key management.
- Easy live-build integration via systemd units, configuration files, and package-level installation.

## Architecture

The project is organized in layers:

- Core: versioning, build metadata, policy configuration.
- Security services: firewall management, malware scanning abstraction, metadata cleaning, system monitor.
- Cryptography layer: hashing, key derivation, secure storage helpers, credential policy checks.
- XFCE integration: D-Bus and desktop integration hooks without forcing heavy GTK dependencies.
- Daemon and CLI surfaces: service and admin operations.

## Build

```bash
cmake -S . -B build -DBUILD_TESTING=ON
cmake --build build
ctest --test-dir build --output-on-failure
```

## Planned modules

- FirewallManager: iptables/nftables rule administration via controlled policy API.
- AntivirusScanner: path-based malware scan interface with future signature or heuristic engine.
- MetadataCleaner: browser, shell, editor, and application cache cleanup hooks.
- SystemMonitor: process, CPU, RAM, and disk activity metrics.
- TorManager: Tor routing policy and transparent proxy controls with strict validation.
- KeyManager: protected key storage and policy enforcement.
- Xfce integration: tray/service hooks and desktop automation without heavy widget frameworks.

## Security principles

- Default to encrypted storage.
- Require explicit user consent for privileged operations.
- Avoid plaintext secrets in logs and configuration.
- Prefer standard system interfaces and secure defaults over ad-hoc custom logic.
- Separate policy from implementation.

## Current status

This repository contains the initial C++ foundation and architecture for the project. It is intentionally small, portable, and easy to extend into a full live-build package set.
