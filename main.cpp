#include "modules/service/filesys.h"
#include "modules/utility/utils.h"
#include "modules/mail/mail.h"
#include "modules/includes/colors.h"



GeneralUtility utility;
mailsystem app;
int main();

int homedisplay() {
    utility.clearConsole();
    int x;
    std::cout
        << Color::brightGreen << "====================================\n"
        << Color::brightBlue << "  $ECHO: "
        << Color::brightRed << "ECHOMAIL V2 HOMEPAGE      \n"
        << Color::brightGreen << "====================================\n"
        << Color::reset
        << Color::brightGreen << "[1]" << Color::brightRed << " EMAIL SENDER\n"
        << Color::brightGreen << "[2]" << Color::brightRed << " SMTP TESTER\n"
        << Color::brightGreen << "[3]" << Color::brightRed << " EXTRACTOR\n"
        << Color::brightGreen << "[4]" << Color::brightRed << " SORTER\n"
        // << Color::brightGreen << "[5]" << Color::brightRed << " CONFIG\n"
        << Color::brightGreen << "[0]" << Color::brightRed << " EXIT\n"
        << Color::brightGreen << "CHOOSE YOUR SERVICE: \033[0m";
    std::cin >> x;
    return x;
}


int main() {


    switch (homedisplay())
    {
    case 0:
        utility.clearConsole();
        std::cout << "\033[93m[INF] TERMINATING ECHOMAIL PROGRAM IN 3 SECS... GOODBYE!\033[0m" << std::endl;
        utility.delay(3);
        utility.clearConsole();
        exit(0);
        break;
    case 1:

        std::cout << "\033[92m[INF] EMAIL SENDER FILES PREPARED SUCCESSFULLY.\033[0m" << std::endl;

        break;
    case 2:

        std::cout << "\033[92m[INF] SMTP TESTER FILES PREPARED SUCCESSFULLY.\033[0m" << std::endl;

        break;
    case 3:
        if (!app.extractor()) std::cout << "[WAR] EXTRACTOR PROGRAM FAILED, CONTACT HELP." << std::endl;
        utility.delay(4);
        break;
    case 4:
        (app.sorter()) ?
            std::cout << "PROGRAM ENDS GRACEFULLY..\n" :
            std::cout << "PROGRAM FAILED TRY AGAIN...\n";
        break;
    default:
        std::cout << "\033[91m[WAR] INVALID INPUT! PLEASE TRY AGAIN.\033[0m" << std::endl;
        utility.delay(2);
        utility.clearConsole();
        break;
    }
    main();

}