#ifndef FILESYS_H
#define FILESYS_H
#include <string>
#include <vector>
#include "../utility/utils.h"

class managefilesystem : public GeneralUtility {
public:
    std::string homedir;
    managefilesystem();
    ~managefilesystem();

    bool prepareEmailFiles();
    bool prepareSMTPTesterFiles();
    bool prepareExtractorFiles();
    bool prepareSorterFiles();
};

#endif