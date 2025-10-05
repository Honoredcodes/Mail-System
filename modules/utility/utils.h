#ifndef GENERAL_UTILITY_H
#define GENERAL_UTILITY_H
#include <filesystem>

namespace fs = std::filesystem;
class GeneralUtility {
public:
    bool makeRootDirectory(std::string& root, std::string directorychoice);
    bool makeDirectory(const std::string root, std::string directory);
    bool createTextFile(const std::string parent, const std::string filename);
    void toUppercase(std::string& str);
    void clearConsole();
    void delay(int x);
};
#endif