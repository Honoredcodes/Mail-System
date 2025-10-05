#include "filesys.h"
#include <iostream>
#include <vector>
#include <filesystem>
#include "../utility/utils.h"
namespace fs = std::filesystem;

managefilesystem::managefilesystem(std::string& root, std::string directorychoice) {
    GeneralUtility util;
    util.makeRootDirectory(root, directorychoice);
}

managefilesystem::~managefilesystem() {}

bool managefilesystem::prepareEmailFiles(const std::string parent) {
    GeneralUtility util;
    int flag = 0;
    util.makeDirectory(const_cast<std::string&>(parent), "constant");
    util.makeDirectory(const_cast<std::string&>(parent), "variable");
    std::string constantpath = fs::path(parent) / "EMAIL SENDER" / "constant";
    std::string variablepath = fs::path(parent) / "EMAIL SENDER" / "variable";
    util.makeDirectory(const_cast<std::string&>(constantpath), "live");
    util.makeDirectory(const_cast<std::string&>(variablepath), "live");
    util.makeDirectory(const_cast<std::string&>(constantpath), "junk");
    util.makeDirectory(const_cast<std::string&>(variablepath), "junk");

    std::vector<std::string> f1 = { "letter.txt", "leads.txt", "smtp.txt", "sendername.txt", "subject.txt", "sentleads.txt", "failedleads.txt", "deadsmtp.txt" };
    for (const auto f : f1) {
        if (f != "deadsmtp.txt" && f != "failedleads.txt") {
            if ((util.createTextFile(variablepath + "/live", f)) && (util.createTextFile(constantpath + "/live", f))) flag++;
        }
        else {
            if ((util.createTextFile(variablepath + "/junk", f)) && (util.createTextFile(constantpath + "/junk", f))) flag++;
        }
    }
    return flag == 2;
}

bool managefilesystem::prepareSMTPTesterFiles(const std::string parent) {
    GeneralUtility util;
    util.makeDirectory(const_cast<std::string&>(parent), "SMTP TESTER");
    std::string SMTPTESTERDIRECTORY = fs::path(parent) / "SMTP TESTER";
    std::vector<std::string> f1 = { "raw.txt", "live.txt", "dead.txt" };
    for (const auto f : f1) {
        if (!util.createTextFile(SMTPTESTERDIRECTORY, f)) return false;
    }
    return true;
}

bool managefilesystem::prepareExtractorFiles(const std::string parent) {
    GeneralUtility util;
    util.makeDirectory(const_cast<std::string&>(parent), "EXTRACTOR");
    std::string EXTRACTORDIRECTORY = fs::path(parent) / "EXTRACTOR";
    std::vector<std::string> f1 = { "raw.txt", "extracted.txt" };
    for (const auto f : f1) {
        if (!util.createTextFile(EXTRACTORDIRECTORY, f)) return false;
    }
    return true;
}

bool managefilesystem::prepareSorterFiles(const std::string parent) {
    GeneralUtility util;
    util.makeDirectory(const_cast<std::string&>(parent), "SORTER");
    std::string SORTERDIRECTORY = fs::path(parent) / "SORTER";
    std::vector<std::string> f1 = { "raw.txt", "sorted.txt" };
    for (const auto f : f1) {
        if (!util.createTextFile(SORTERDIRECTORY, f)) return false;
    }
    return true;
}