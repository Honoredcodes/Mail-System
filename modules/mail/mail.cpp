#include <iostream>
#include <fstream>
#include <filesystem>
#include <unordered_set>
#include <set>
#include "mail.h"
#include "../utility/utils.h"
#include "../service/filesys.h"
namespace fs = std::filesystem;
GeneralUtility util;
managefilesystem filesys;

bool mailsystem::sorter() {
    fs::path filepath = fs::path(filesys.echo) / "SORTER";
    std::ifstream read(filepath / "raw.txt");
    std::ofstream write(filepath / "results.txt");
    if (!read || !write) return false;

    char choice;
    util.clearConsole();
    std::cout << "[INF] PLEASE MAKE SURE RAW FILE ISN'T EMPTY...";
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
        util.clearConsole();
        std::cout << "[ERR] INVALID CHOICE, PLEASE TRY AGAIN.\n";
        util.delay(2);
        return false;
    }
    util.clearConsole();
    std::cout << "TOTAL DUPLICATES MERGED" << (total - unique) << "\n";
    return true;
}