#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime>
#include <thread>
#include <filesystem>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include "utils.h"
namespace fs = std::filesystem;


void GeneralUtility::toUppercase(std::string& str) {
    for (char& c : str) {
        c = toupper(c);
    }
}

bool GeneralUtility::makeRootDirectory(std::string& root, std::string directorychoice) {
    root = fs::path(getenv("HOME")) / directorychoice;
    if (!fs::exists(root)) {
        try {
            fs::create_directories(root);
            std::cout << "[INF] PARENT DIRECTORY EXIST: TRUE" << std::endl;
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

bool GeneralUtility::makeDirectory(std::string& root, std::string directory) {
    fs::path tempdirectory = fs::path(root) / directory;
    if (!fs::exists(tempdirectory)) {
        try {
            fs::create_directories(tempdirectory);
            return true;
        }
        catch (const fs::filesystem_error& e) {
            return false;
        }
    }
}

bool GeneralUtility::createTextFile(const std::string parent, const std::string filename) {
    fs::path filepath = fs::path(parent) / filename;
    if (!fs::exists(filepath)) {
        std::ofstream file(filepath);
        if (file) {
            file.close();
            return true;
        }
        else {
            return false;
        }
    }
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