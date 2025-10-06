#ifndef FILESYS_H
#define FILESYS_H
#include <string>
#include <vector>

class managefilesystem {
public:
    std::string echo;
    managefilesystem(std::string& root, std::string directorychoice);
    ~managefilesystem();

    bool prepareEmailFiles(const std::string parent);
    bool prepareSMTPTesterFiles(const std::string parent);
    bool prepareExtractorFiles(const std::string parent);
    bool prepareSorterFiles(const std::string parent);
};

#endif