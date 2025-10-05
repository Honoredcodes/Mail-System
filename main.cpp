#include <iostream>
#include <string>
#include "modules/service/filesys.h"
#include "modules/utility/utils.h"

bool programRunning = false;
std::string root, parentfilename;
GeneralUtility util;
int main();
void showBanner() {
    util.clearConsole();
    std::cout << "====================================" << std::endl;
    std::cout << "  $ECHO:  Welcome to Mail System    " << std::endl;
    std::cout << "====================================" << std::endl;
}

void promptRootDirectory(std::string& root, std::string& parentfilename) {
    if (programRunning) return;
    std::string choice;
    do {
        std::cout
            << "\033[94m[1] \033[93mDESKTOP\n"
            << "\033[94m[2] \033[93mDOWNLOADS\n"
            << "\033[94m[3] \033[93mDOCUMENTS\n"
            << "\033[92m\033[1mCHOOSE ROOT DIRECTORY [0 EXIT]: ";
        std::getline(std::cin, choice);
        util.clearConsole();
        if (choice == "0") {
            std::cout << "\033[92m\033[1mTERMINATING PROGRAM...\n";
            util.delay(2);
            util.clearConsole();
            exit(0);
        }
        if (choice == "1") root = "Desktop";
        else if (choice == "2") root = "Downloads";
        else if (choice == "3") root = "Documents";
        else {
            std::cout << "\033[91m[WAR] INVALID INPUT! PLEASE TRY AGAIN.\033[0m" << std::endl;
            util.delay(2);
            util.clearConsole();
            continue;
        }
        std::cout << "\033[92m\033[1mSet project name: \033[0m";
        std::getline(std::cin, parentfilename);
        if (parentfilename.empty()) {
            std::cout << "\033[91m[WAR] CANNOT BE EMPTY! PLEASE TRY AGAIN.\033[0m" << std::endl;
            util.delay(2);
            util.clearConsole();
            continue;
        }
        programRunning = true;
    } while (choice != "1" && choice != "2" && choice != "3" && choice != "0");
}
int homedisplay() {
    int x;
    std::cout << "====================================" << std::endl;
    std::cout << "  $ECHO:  ECHOMAIL V2 HOMEPAGE      " << std::endl;
    std::cout << "====================================" << std::endl;
    std::cout << "\033[92m\033[1m"
        << "[1] EMAIL SENDER\n"
        << "[2] SMTP TESTER\n"
        << "[3] EXTRACTOR\n"
        << "[4] SORTER\n"
        << "[0] EXIT\n"
        << "CHOOSE YOUR SERVICE: \033[0m";
    std::cin >> x;
    return x;
}

int main() {
    showBanner();
    promptRootDirectory(root, parentfilename);
    managefilesystem fsmanager(root, parentfilename);
    std::string parent = fs::path(root) / parentfilename;
    int choice = homedisplay();

    switch (choice)
    {
    case 0:
        util.clearConsole();
        std::cout << "\033[93m[INF] THANK YOU FOR USING $ECHO MAIL SYSTEM. GOODBYE!\033[0m" << std::endl;
        util.delay(2);
        exit(0);
        break;
    case 1:
        if (fsmanager.prepareEmailFiles(parent)) {
            std::cout << "\033[92m[INF] EMAIL SENDER FILES PREPARED SUCCESSFULLY.\033[0m" << std::endl;
        }
        break;
    case 2:
        if (fsmanager.prepareSMTPTesterFiles(parent)) {
            std::cout << "\033[92m[INF] SMTP TESTER FILES PREPARED SUCCESSFULLY.\033[0m" << std::endl;
        }
        break;
    case 3:
        if (fsmanager.prepareExtractorFiles(parent)) {
            std::cout << "\033[92m[INF] EXTRACTOR FILES PREPARED SUCCESSFULLY.\033[0m" << std::endl;
        }
        break;
    case 4:
        if (fsmanager.prepareSorterFiles(parent)) {
            std::cout << "\033[92m[INF] SORTER FILES PREPARED SUCCESSFULLY.\033[0m" << std::endl;
        }
        break;
    default:
        std::cout << "\033[91m[WAR] INVALID INPUT! PLEASE TRY AGAIN.\033[0m" << std::endl;
        util.delay(2);
        util.clearConsole();
        main();
        break;
    }
}