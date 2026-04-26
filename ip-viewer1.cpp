#include <iostream>
#include <cstdlib>

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "       IP CONFIGURATION DETAILS         " << std::endl;
    std::cout << "========================================" << std::endl;

    std::cout << "\n[1] Basic IP Config:\n";
    std::cout << "----------------------------------------\n";
    system("ipconfig");

    std::cout << "\n[2] Detailed IP Config:\n";
    std::cout << "----------------------------------------\n";
    system("ipconfig /all");

    std::cout << "\n========================================\n";
    std::cout << "Press Enter to exit...";
    std::cin.get();
    return 0;
}
