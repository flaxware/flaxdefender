# FlaxDefender

FlaxDefender is a Linux security center designed for lightweight, portable, and modular protection. It is intentionally structured as a clean C++ foundation for a system security suite that can be integrated into a live-build environment, embedded into XFCE4, and used as a central security control plane.

This project is not a shortcut wrapper around other tools. It is a complete, from-scratch security architecture designed to be modular, secure, and distro-friendly. The early version is a C++ foundation and a product blueprint for the full system that follows the Flax philosophy: general, efficient, ready, flexible, portable, and safe.

## Product intent

FlaxDefender aims to combine the best ideas from:

- BitDefender: centralized security dashboard with a premium, polished experience
- Stacer: system monitoring and quick administration
- BleachBit: metadata and temporary artifact cleanup
- ClamTk: malware scanning and security checks

But in a Flax way:

- no heavy GTK dependency stack
- no shortcut-only wrappers around external tools
- no fragile shell-script-only architecture
- no secret logging or unsafe credential handling
- no dead-weight design for desktops that want simplicity and speed

## Flax UI direction

The UI should feel premium but not bloated. Think of a clean, glassy, dark security center for XFCE4 with crisp cards, minimal animations, and strong system status semantics.

Example concept:

```text
┌──────────────────────────────────────────────────────────────────────┐
│ FlaxDefender                         [System Secure] [Apply]      │
├──────────────────────────────────────────────────────────────────────┤
│ Overview      Firewall      Tor     Cleanup    Antivirus   Monitor   │
├──────────────────────────────────────────────��───────────────────────┤
│ Security Status                                                     │
│ ┌─────────────┐ ┌─────────────┐ ┌─────────────┐                     │
│ │ Disk Encrypt│ │ Firewall    │ │ Tor Policy  │                     │
│ │ Enabled      │ │ Hardened    │ │ Active      │                     │
│ └─────────────┘ └─────────────┘ └─────────────┘                     │
│ Active tasks: 3 | Last scan: 02:14 | Keyring: valid                │
│                                                                     │
│ Quick actions: [Scan] [Clean] [Firewall] [Tor] [Encrypt] [Logs]   │
└──────────────────────────────────────────────────────────────────────┘
```

This is a visual direction, not a final widget layout. It should be implemented with a lightweight interface layer over D-Bus, a tray backend, and a fast C++ core, not with heavy GUI frameworks.

## Core principles

- General and hierarchical architecture
- Lightweight resource usage and minimal system footprint
- Safe by default
- Fully configurable via plain text and policy files
- Portable and modular enough for live-build, Debian, Ubuntu, and Arch-style systems
- Secure credential and key management by default

## Goals

- Desktop security center for XFCE4 and Linux systems
- Lightweight design with low dependency footprint
- Full-disk encryption and encrypted user-data defaults as a policy layer
- Modular security services: firewall, monitoring, metadata cleaning, Tor routing controls, and malware scanning
- Strong crypto defaults using modern standards and careful key management
- Easy live-build integration via systemd units, configuration files, and package-level installation

## Architecture

The project is organized in layers:

- Core: versioning, build metadata, and policy configuration
- Security services: firewall management, malware scanning abstraction, metadata cleaning, system monitor
- Cryptography layer: hashing, key derivation, secure storage helpers, credential policy checks
- XFCE integration: D-Bus and desktop integration hooks without forcing heavy GTK dependencies
- Daemon and CLI surfaces: service and admin operations

## Build

```bash
cmake -S . -B build -DBUILD_TESTING=ON
cmake --build build
ctest --test-dir build --output-on-failure
```

## Planned modules

- FirewallManager: nftables/iptables policy administration via controlled API
- AntivirusScanner: path-based malware scan interface with future signature or heuristic engine
- MetadataCleaner: browser, shell, editor, and application cache cleanup hooks
- SystemMonitor: process, CPU, RAM, and disk activity metrics
- TorManager: Tor routing policy and transparent proxy controls with strict validation
- KeyManager: protected key storage and policy enforcement
- Xfce integration: tray/service hooks and desktop automation without heavy widget frameworks
- Live-build packaging: installation, post-install hooks, default service generation

## Security defaults

- Encrypted storage and encrypted user data by default
- LUKS2 and encrypted home policy by default when supported
- Secure key store and minimal logging of secrets
- Explicit privilege approval before firewall, Tor, or cleanup changes
- Prefer standard system interfaces over bespoke logic

## Supported design directions

The project is intentionally designed around standards and portability:

- modern C++20 code
- clean interfaces and modular subsystems
- Linux-native system integration
- D-Bus service and configuration-driven desktop behavior
- no unnecessary external runtime dependency chain

## Repo status

The current repository contains the first stable foundation for the FlaxDefender architecture. It is intentionally small, portable, and safe to extend without introducing large dependency chains or brittle code.

## Important note

This project is an engineering foundation. It is not yet a full endpoint antivirus replacement, and it should not be marketed as one until the scanning engine, encrypted storage policy, runtime privilege model, and package integration are fully implemented and validated.
