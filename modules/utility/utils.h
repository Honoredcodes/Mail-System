#ifndef GENERAL_UTILITY_H
#define GENERAL_UTILITY_H
#include <ctime>
#include <mutex>
#include <string>
#include <chrono>
#include <thread>
#include <regex>
#include <sstream>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <unordered_set>

namespace fs = std::filesystem;
class GeneralUtility {
protected:
    std::mutex mtx;
public:

    bool makeRootDirectory(std::string& root, std::string directorychoice);
    bool makeDirectory(const std::string root, std::string directory);
    bool createTextFile(const std::string parent, const std::string filename);
    void extract(const std::string text, std::unordered_set<std::string>& results);
    void toUppercase(std::string& str);
    void clearConsole();
    void delay(int x);
};
#endif