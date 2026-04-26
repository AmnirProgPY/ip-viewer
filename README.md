# 🌐 IP-VIEWER

A Windows-based C++ utility that retrieves and displays detailed network adapter and IP configuration information using the Windows API (`iphlpapi`).

---

## 📖 Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Project Structure](#project-structure)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Methods](#methods)
- [Sample Output](#sample-output)
- [Technologies Used](#technologies-used)
- [Limitations](#limitations)
- [License](#license)

---

## 📌 Overview

This project provides two approaches to fetch and display IP configuration details from a Windows machine using C++:

1. **Method 1 — `system()` Call**: A simple wrapper around the `ipconfig` Windows command.
2. **Method 2 — Windows API**: A professional implementation using `GetAdaptersInfo()` from the `iphlpapi` library for full programmatic control over network data.

---

## ✨ Features

- Displays all active network adapters
- Shows IP Address, Subnet Mask, and Default Gateway
- Retrieves MAC (Physical) Address
- Identifies adapter type (Ethernet, Wi-Fi, Loopback, etc.)
- Shows DHCP status and DHCP server address
- Supports multiple IP addresses per adapter
- Clean, formatted console output

---

## 📁 Project Structure

```
ip-viewer/
│
├── method1_simple/
│   └── ip-viewer1.cpp       # Uses system("ipconfig") call
│
├── method2_winapi/
│   └── ip-viewer1.cpp       # Uses Windows GetAdaptersInfo API
├── method3_batch/
│   └── ip-viewer.bat       # batch file
│
└── README.md                     # Project documentation
```

---

## ⚙️ Requirements

| Requirement        | Details                        |
|--------------------|--------------------------------|
| Operating System   | Windows 7 / 10 / 11            |
| Compiler           | g++ (MinGW) or MSVC            |
| C++ Standard       | C++11 or later                 |
| Libraries          | `iphlpapi.lib`, `ws2_32.lib`   |

---

## 🚀 Installation

### 1. Clone the Repository

```bash
git clone https://github.com/AmnirProgPY/ip-viewer.git
cd ip-config-cpp
```

### 2. Compile

**Using g++ (MinGW):**
```bash
g++ method2_winapi/ipconfig_winapi.cpp -o ipconfig_tool -liphlpapi -lws2_32
```

**Using MSVC (Developer Command Prompt):**
```bash
cl method2_winapi/ipconfig_winapi.cpp /link iphlpapi.lib ws2_32.lib
```

---

## 🖥️ Usage

Run the compiled executable:

```bash
./ipconfig_tool.exe
```

Or double-click the `.exe` file in File Explorer.

> **Tip:** Run as Administrator for full network adapter details.

---

## 🔬 Methods

### Method 1 — `system()` Call

| Property     | Details                          |
|--------------|----------------------------------|
| Complexity   | Low                              |
| Control      | Limited (raw console output)     |
| Parsing      | Not possible                     |
| Best for     | Quick debugging / scripts        |

```cpp
system("ipconfig /all");
```

---

### Method 2 — Windows API (`GetAdaptersInfo`)

| Property     | Details                          |
|--------------|----------------------------------|
| Complexity   | Medium–High                      |
| Control      | Full programmatic access         |
| Parsing      | Fully supported                  |
| Best for     | Production tools / applications  |

Key API used:
```cpp
GetAdaptersInfo(adapterInfo, &bufferSize);
```

Linked libraries:
```cpp
#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib, "ws2_32.lib")
```

---

## 📋 Sample Output

```
========================================
      IP CONFIGURATION (C++ WinAPI)
========================================

========================================
 Adapter #1
========================================
  Name          : {A1B2C3D4-XXXX-XXXX-XXXX-XXXXXXXXXXXX}
  Description   : Intel(R) Wi-Fi 6 AX201 160MHz
  Type          : Wi-Fi
  MAC Address   : A4-C3-F0-12-34-56
  IP Address    : 192.168.1.105
  Subnet Mask   : 255.255.255.0
  Gateway       : 192.168.1.1
  DHCP Enabled  : Yes
  DHCP Server   : 192.168.1.1

========================================
 Adapter #2
========================================
  Name          : {B3C4D5E6-XXXX-XXXX-XXXX-XXXXXXXXXXXX}
  Description   : Realtek PCIe GbE Family Controller
  Type          : Ethernet
  MAC Address   : D4-E5-F6-78-90-AB
  IP Address    : 0.0.0.0
  Subnet Mask   : 0.0.0.0
  Gateway       : 0.0.0.0
  DHCP Enabled  : Yes
  DHCP Server   : 0.0.0.0
```

---

## 🛠️ Technologies Used

- **Language**: C++ (C++11)
- **Platform**: Windows
- **Libraries**:
  - `<winsock2.h>` — Windows Sockets API
  - `<iphlpapi.h>` — IP Helper API
  - `<ws2tcpip.h>` — TCP/IP definitions
  - `<iostream>` — Console I/O

---

## ⚠️ Limitations

- **Windows only** — This tool is not cross-platform.
  - For Linux, use `getifaddrs()` from `<ifaddrs.h>`
  - For macOS, use `getifaddrs()` or `SCNetworkReachability`
- IPv6 support requires `GetAdaptersAddresses()` instead of `GetAdaptersInfo()`
- Some adapters may show `0.0.0.0` if they are inactive or disconnected

---

## 📄 License

This project is licensed under the [MIT License](LICENSE).

---

## 🤝 Contributing

Pull requests are welcome! For major changes, please open an issue first to discuss what you would like to change.

---

## 📬 Contact

For questions or feedback, open an issue on the repository or reach out via GitHub.
