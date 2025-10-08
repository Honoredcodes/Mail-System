#ifndef MAIL_SYSTEM_H
#define MAIL_SYSTEM_H
#include <set>
#include <string>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <unordered_set>
#include "../utility/utils.h"
#include "../service/filesys.h"

class mailsystem : public managefilesystem {
    std::mutex mtx;
public:
    bool sorter();
    bool extractor();
    bool mailconstant();
    bool mailvariable();
    bool smtptester();
    void tester();
    void extract(const std::string text, std::unordered_set<std::string>& results);

};
#endif