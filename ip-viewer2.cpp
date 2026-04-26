#include <iostream>
#include <winsock2.h>
#include <iphlpapi.h>
#include <ws2tcpip.h>
#include <string>

#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib, "ws2_32.lib")

//Windows API (Professional)

// Convert adapter type to readable string
std::string getAdapterType(DWORD type) {
    switch (type) {
        case MIB_IF_TYPE_ETHERNET:  return "Ethernet";
        case MIB_IF_TYPE_LOOPBACK:  return "Loopback";
        case MIB_IF_TYPE_PPP:       return "PPP";
        case MIB_IF_TYPE_SLIP:      return "SLIP";
        case IF_TYPE_IEEE80211:     return "Wi-Fi";
        default:                    return "Unknown";
    }
}

void printIPConfig() {
    ULONG bufferSize = 15000;
    PIP_ADAPTER_INFO adapterInfo = (IP_ADAPTER_INFO*)malloc(bufferSize);

    if (adapterInfo == nullptr) {
        std::cerr << "Memory allocation failed!" << std::endl;
        return;
    }

    // Get adapter information
    DWORD result = GetAdaptersInfo(adapterInfo, &bufferSize);

    // Buffer too small? Resize and retry
    if (result == ERROR_BUFFER_OVERFLOW) {
        free(adapterInfo);
        adapterInfo = (IP_ADAPTER_INFO*)malloc(bufferSize);
        if (adapterInfo == nullptr) {
            std::cerr << "Memory reallocation failed!" << std::endl;
            return;
        }
        result = GetAdaptersInfo(adapterInfo, &bufferSize);
    }

    if (result != NO_ERROR) {
        std::cerr << "GetAdaptersInfo failed: " << result << std::endl;
        free(adapterInfo);
        return;
    }

    PIP_ADAPTER_INFO adapter = adapterInfo;
    int adapterCount = 1;

    while (adapter) {
        std::cout << "========================================\n";
        std::cout << " Adapter #" << adapterCount++ << "\n";
        std::cout << "========================================\n";

        // Adapter details
        std::cout << "  Name          : " << adapter->AdapterName << "\n";
        std::cout << "  Description   : " << adapter->Description << "\n";
        std::cout << "  Type          : " << getAdapterType(adapter->Type) << "\n";

        // MAC Address
        std::cout << "  MAC Address   : ";
        for (UINT i = 0; i < adapter->AddressLength; i++) {
            printf("%02X", adapter->Address[i]);
            if (i < adapter->AddressLength - 1) printf("-");
        }
        std::cout << "\n";

        // IP Addresses (can have multiple)
        IP_ADDR_STRING* ipAddr = &adapter->IpAddressList;
        while (ipAddr) {
            std::cout << "  IP Address    : " << ipAddr->IpAddress.String << "\n";
            std::cout << "  Subnet Mask   : " << ipAddr->IpMask.String << "\n";
            ipAddr = ipAddr->Next;
        }

        // Gateway
        std::cout << "  Gateway       : " << adapter->GatewayList.IpAddress.String << "\n";

        // DHCP
        std::cout << "  DHCP Enabled  : " << (adapter->DhcpEnabled ? "Yes" : "No") << "\n";
        if (adapter->DhcpEnabled)
            std::cout << "  DHCP Server   : " << adapter->DhcpServer.IpAddress.String << "\n";

        std::cout << "\n";
        adapter = adapter->Next;
    }

    free(adapterInfo);
}

int main() {
    std::cout << "========================================\n";
    std::cout << "      IP CONFIGURATION (C++ WinAPI)     \n";
    std::cout << "========================================\n\n";

    printIPConfig();

    std::cout << "Press Enter to exit...";
    std::cin.get();
    return 0;
}
