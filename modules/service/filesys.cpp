#include "filesys.h"
#include <iostream>
#include <string>
#include <vector>
#include "../includes/colors.h"

bool filesystemready = false;
managefilesystem::managefilesystem() {
    clearConsole();
    if (filesystemready) return;
    char c;
    std::string root;
    std::string project;
    do {
        std::cout
            << Color::brightGreen << "=============================================" << Color::reset << std::endl
            << Color::brightBlue << "      $ECHO: " << Color::brightGreen << "ECHOMAIL SYSTEM FILE CHECK      " << std::endl
            << Color::brightGreen << "=============================================" << Color::reset << std::endl
            << Color::brightRed << "[1] " << Color::brightGreen << "DESKTOP\n"
            << Color::brightRed << "[2] " << Color::brightGreen << "DOWNLOADS\n"
            << Color::brightRed << "[3] " << Color::brightGreen << "DOCUMENTS\n"
            << Color::brightGreen << "CHOOSE PARENT DIRECTORY [0 EXIT]: " << Color::reset;
        std::cin >> c;
        switch (c) {
        case '0':
            clearConsole();
            std::cout
                << Color::brightGreen
                << "[INF] TERMINATING PROGRAM IN 2 SECONDS...\n"
                << Color::reset;
            delay(2);
            clearConsole();
            exit(0);
            break;
        case '1':
            root = "Desktop";
            break;
        case '2':
            root = "Downloads";
            break;
        case '3':
            root = "Documents";
            break;
        default:
            std::cout << "\033[91m[WAR] INVALID INPUT! PLEASE TRY AGAIN.\033[0m" << std::endl;
            delay(2);
            clearConsole();
            continue;
        }
        std::cout << "\033[92m\033[1mSET OR GET FILE PROJECT BY NAME: \033[0m";
        std::cin >> project;
        if (project.empty()) {
            std::cout << "\033[91m[WAR] CANNOT BE EMPTY! PLEASE TRY AGAIN.\033[0m" << std::endl;
            delay(2);
            clearConsole();
            continue;
        }
    } while (c != '1' && c != '2' && c != '3' && c != '0');
    clearConsole();
    if (!makeRootDirectory(root, project)) {
        delay(3);
        exit(0);
    }
    homedir = fs::path(root).string();
    filesystemready = true;
    delay(2);
    clearConsole();
}
managefilesystem::~managefilesystem() {}
bool managefilesystem::prepareEmailFiles() {
    int flag = 0;
    std::string constantpath = fs::path(homedir) / "EMAIL SENDER" / "constant";
    std::string variablepath = fs::path(homedir) / "EMAIL SENDER" / "variable";
    makeDirectory(const_cast<std::string&>(constantpath), "live");
    makeDirectory(const_cast<std::string&>(variablepath), "live");
    makeDirectory(const_cast<std::string&>(constantpath), "junk");
    makeDirectory(const_cast<std::string&>(variablepath), "junk");

    std::vector<std::string> f1 = { "letter.txt", "leads.txt", "smtp.txt", "sendername.txt", "subject.txt", "sentleads.txt", "failedleads.txt", "deadsmtp.txt" };
    for (const auto f : f1) {
        if (f != "deadsmtp.txt" && f != "failedleads.txt") {
            if ((createTextFile(variablepath + "/live", f)) && (createTextFile(constantpath + "/live", f))) flag++;
        }
        else {
            if ((createTextFile(variablepath + "/junk", f)) && (createTextFile(constantpath + "/junk", f))) flag++;
        }
    }
    return flag == 2;
}
bool managefilesystem::prepareSMTPTesterFiles() {
    makeDirectory(const_cast<std::string&>(homedir), "SMTP TESTER");
    std::string SMTPTESTERDIRECTORY = fs::path(homedir) / "SMTP TESTER";
    std::vector<std::string> f1 = { "raw.txt", "live.txt", "dead.txt" };
    for (const auto f : f1) {
        if (!createTextFile(SMTPTESTERDIRECTORY, f)) return false;
    }
    return true;
}
bool managefilesystem::prepareExtractorFiles() {
    makeDirectory(const_cast<std::string&>(homedir), "EXTRACTOR");
    std::string EXTRACTORDIRECTORY = fs::path(homedir) / "EXTRACTOR";
    std::vector<std::string> f1 = { "raw.txt", "extracted.txt" };
    for (const auto f : f1) {
        if (!createTextFile(EXTRACTORDIRECTORY, f)) return false;
    }
    return true;
}
bool managefilesystem::prepareSorterFiles() {
    makeDirectory(const_cast<std::string&>(homedir), "SORTER");
    std::string SORTERDIRECTORY = fs::path(homedir) / "SORTER";
    std::vector<std::string> f1 = { "raw.txt", "sorted.txt" };
    for (const auto f : f1) {
        if (!createTextFile(SORTERDIRECTORY, f)) return false;
    }
    return true;
}