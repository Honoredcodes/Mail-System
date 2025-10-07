#include <iostream>
#include <fstream>
#include <filesystem>
#include <unordered_set>
#include <set>
#include "mail.h"
namespace fs = std::filesystem;

bool mailsystem::mailconstant() {}
bool mailsystem::mailvariable() {}
bool mailsystem::smtptester() {}
bool mailsystem::extractor() {
    
}
bool mailsystem::sorter() {
    if (!prepareSorterFiles()) return false;
    fs::path filepath = fs::path(homedir) / "SORTER";
    std::ifstream read(filepath / "raw.txt");
    std::ofstream write(filepath / "sorted.txt");
    if (!read || !write) return false;

    char choice;
    clearConsole();
    std::cout << "[INF] PLEASE MAKE SURE RAW FILE ISN'T EMPTY...\n";
    std::cout << "Sort alphabetically? (y/n): ";
    std::cin >> choice;

    bool alphabetical = (choice == 'y' || choice == 'Y');
    std::size_t total = 0, unique = 0;

    if (alphabetical) {
        std::set<std::string> lines;
        std::string line;
        while (std::getline(read, line)) {
            if (line.empty()) continue;
            ++total;
            lines.insert(line);
        }
        unique = lines.size();

        for (const auto& l : lines)
            write << l << '\n';
    }
    else if (choice == 'n' || choice == 'N') {
        std::unordered_set<std::string> lines;
        std::string line;
        while (std::getline(read, line)) {
            if (line.empty()) continue;
            ++total;
            lines.insert(line);
        }
        unique = lines.size();

        for (const auto& l : lines)
            write << l << '\n';
    }
    else {
        clearConsole();
        std::cout << "[ERR] INVALID CHOICE, PLEASE TRY AGAIN.\n";
        delay(2);
        return false;
    }
    clearConsole();
    std::cout << (total - unique) << "TOTAL DUPLICATES MERGED." << "\n";
    delay(4);
    return true;
}

