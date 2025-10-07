#ifndef MAIL_SYSTEM_H
#define MAIL_SYSTEM_H
#include <string>
#include "../utility/utils.h"
#include "../service/filesys.h"

class mailsystem : public managefilesystem {
public:
    bool sorter();
    bool extractor();
    bool mailconstant();
    bool mailvariable();
    bool smtptester();
};
#endif