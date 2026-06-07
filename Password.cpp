#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <windows.h>

bool checkForUppercase(const std::string& password) {
    for (char ch : password) {
        if (std::isupper(static_cast<unsigned char>(ch))) {
            return true;
        }
    }
    return false;
}

bool checkForSpecialChar(const std::string& password) {
    for (char ch : password) {
        if (std::ispunct(static_cast<unsigned char>(ch))) {
            return true;
        }
    }
    return false;
}

bool checkForDigit(const std::string& password) {
    for (char ch : password) {
        if (std::isdigit(static_cast<unsigned char>(ch))) {
            return true;
        }
    }
    return false;
}

int main() {
    std::string password;
    std::cout << "Enter Your Password: ";
    std::cin >> password;
    if (password.empty()) {
        std::cout << "Password cannot be empty.\n";
        return 0;
    }
    if (password.length() < 8) {
        std::cout << "Password must be at least 8 characters long.\n";
        return 0;
    }
    if (!checkForUppercase(password)) {
        std::cout << "Password must contain at least one uppercase letter.\n";
        return 0;
    }
    if (!checkForSpecialChar(password)) {
        std::cout << "Password must contain at least one special character.\n";
        return 0;
    }
    if (!checkForDigit(password)) {
        std::cout << "Password must contain at least one digit.\n";
        return 0;
    }
    std::cout << "\nPassword is valid.\n";
    std::cout << "\n=====\n";
    std::cout << "\nSaving Password...\n";
    Sleep(2000);
    std::ofstream outFile("Password.txt");
    if (outFile.is_open()) {
        outFile << password;
        outFile.close();
        std::cout << "Password saved successfully.\n";
    } else {
        std::cout << "Error occurred while saving the password!\n";
    }
    return 0;
}