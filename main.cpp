#include "modules/service/filesys.h"
#include "modules/utility/utils.h"
#include "modules/mail/mail.h"


GeneralUtility utility;
mailsystem app;
int main();

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


    switch (homedisplay())
    {
    case 0:
        utility.clearConsole();
        std::cout << "\033[93m[INF] THANK YOU FOR USING $ECHO MAIL SYSTEM. GOODBYE!\033[0m" << std::endl;
        utility.delay(3);
        exit(0);
        break;
    case 1:

        std::cout << "\033[92m[INF] EMAIL SENDER FILES PREPARED SUCCESSFULLY.\033[0m" << std::endl;

        break;
    case 2:

        std::cout << "\033[92m[INF] SMTP TESTER FILES PREPARED SUCCESSFULLY.\033[0m" << std::endl;

        break;
    case 3:
        (app.extractor()) ?
            std::cout << "\033[92m[INF] EXTRACTOR FILES PREPARED SUCCESSFULLY.\033[0m" << std::endl :
            std::cout << "\033[92m[INF] EXTRACTOR FILES PREPARED SUCCESSFULLY.\033[0m" << std::endl;
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