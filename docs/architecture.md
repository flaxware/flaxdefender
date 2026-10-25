# FlaxDefender design

## 1. Product scope

FlaxDefender is a compact Linux security control center with a strong default posture:

- Full-disk encryption and encrypted home directories as default policy.
- Centralized security center for firewall, Tor route policy, metadata cleanup, system monitor, and antivirus.
- Small desktop footprint for XFCE4 without heavy GUI dependencies.
- Integration into live-build and Debian/Ubuntu-based systems.

## 2. Architecture

FlaxDefender should be layered so that each subsystem exposes a narrow, well-defined interface.

### Core policy layer

- version management
- configuration and policy registry
- event logging with sanitization
- secure defaults and privilege checks

### Security primitives

- cryptography service
- key management service
- permissions and escalation controls

### Security subsystems

- firewall manager
- Tor routing manager
- metadata cleaner
- process and resource monitor
- antivirus scanner
- encryption policy checker

### Desktop integration

- D-Bus service exposed to XFCE panel or tray items
- configuration files consumed by desktop menu shortcuts or launcher scripts
- no GTK-heavy runtime dependency

## 3. Recommended C++ structure

```text
include/
  flaxdefender/
    core/
    crypto/
    security/
    xfce/
src/
  core/
  security/
  xfce/
  main.cpp
tests/
```

## 4. Operational model

- FlaxDefender runs as a system service plus a lightweight client.
- The service owns privileged actions (iptables/nftables, key storage, file integrity tasks).
- The client only surfaces policy and status information to the desktop.
- All user-run tasks must validate permissions before invoking privileged operations.

## 5. Cryptographic defaults

Use modern standards and system-backed primitives:

- AES-256-GCM for symmetric encryption.
- Argon2id or scrypt for password-based key derivation.
- Ed25519 or X25519 for modern asymmetric interfaces where needed.
- HKDF for key separation and derived subkeys.
- Full-disk encryption via LUKS2 + TPM-backed unlock or passphrase policy.

## 6. Security defaults

- Encrypted home directory enabled by default.
- Secure storage of keys under a protected root or TPM-backed store.
- Secrets never logged in plaintext.
- Rule changes require explicit policy approval and validation.

## 7. Live-build integration

- Provide a package set and systemd unit files.
- Ship a default configuration under /etc/flaxdefender.
- Add post-install hooks to enable required services and generate default keys.
- Ensure the application can be installed in a minimal live image without GUI bloat.

## 8. Future roadmap

1. Build the service interfaces.
2. Implement secure configuration management.
3. Add firewall and cleanup policy enforcement.
4. Add scan engine abstraction and event handling.
5. Add XFCE tray integration and D-Bus status APIs.
6. Harden packaging for distro and live-build adoption.
