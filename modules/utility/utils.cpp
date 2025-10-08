#include "utils.h"
#include "../includes/colors.h"


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
void GeneralUtility::servicedisplay(const std::string title) {
    std::cout
        << "====================================\n"
        << "   ECHOMAIL V2 " << title << std::endl
        << "====================================\n";
}
bool GeneralUtility::errormessage(size_t code) {
    switch (code) {
    case 324:
        std::cerr << "[ERR] PEOGRAM FAILED TO CREATE ROOT DIRECTORY.\n";
        break;
    case 325:
        std::cerr << "[ERR] PEOGRAM FAILED TO CREATE PROJECT DIRECTORY\n";
        break;
    case 326:
        std::cerr << "[ERR] PEOGRAM FAILED TO READ FROM FILE\n";
        break;
    case 327:
        std::cerr << "[ERR] PEOGRAM FAILED TO WRITE TO FILE\n";
        break;
    default:
        std::cerr << "[ERR] UNKNWON ERROR CODE...\n";
        break;
    }
    return false;
}