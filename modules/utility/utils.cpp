#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime>
#include <thread>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include "utils.h"


void GeneralUtility::toUppercase(std::string& str) {
    for (char& c : str) {
        c = toupper(c);
    }
}

bool GeneralUtility::makeRootDirectory(std::string& root, std::string directorychoice) {
    std::string temp = root;
    root = fs::path(getenv("HOME")) / temp / directorychoice;
    clearConsole();
    if (!fs::exists(root)) {
        try {
            fs::create_directories(root);
            std::cout << "[INF] PARENT DIRECTORY CREATED: TRUE" << std::endl;
        }
        catch (const fs::filesystem_error& e) {
            std::cerr << "[WAR] PARENT DIRECTORY EXIST: FALSE" << std::endl;
            return false;
        }
    }
    else {
        std::cout << "[INF] PARENT DIRECTORY EXIST: TRUE" << std::endl;
    }
    return true;
}

bool GeneralUtility::makeDirectory(const std::string root, std::string directory) {
    try {
        fs::path createDirectory = fs::path(root) / directory;
        return fs::create_directories(createDirectory) || fs::exists(createDirectory);
    }
    catch (const fs::filesystem_error&) {
        return false;
    }
}


bool GeneralUtility::createTextFile(const std::string parent, const std::string filename) {
    fs::path filepath = fs::path(parent) / filename;
    if (fs::exists(filepath)) {
        return true;
    }
    std::ofstream file(filepath);
    if (!file) {
        return false;
    }
    file.close();
    return true;
}


void GeneralUtility::clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void GeneralUtility::delay(int s) {
    std::this_thread::sleep_for(std::chrono::seconds(s));
}