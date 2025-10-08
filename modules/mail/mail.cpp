#include "mail.h"
namespace fs = std::filesystem;
void tester() {

}
void mailsystem::extract(const std::string text, std::unordered_set<std::string>& results) {
    std::smatch match;
    const std::regex emailPattern(R"(([\w\.-]+)@([\w\.-]+)\.([a-zA-Z]{2,}))");
    auto start = text.cbegin();
    std::unordered_set<std::string>localset;
    while (std::regex_search(start, text.cend(), match, emailPattern)) {
        localset.insert(match[0]);
        start = match.suffix().first;
    }
    std::lock_guard<std::mutex> lock(mtx);
    results.insert(localset.begin(), localset.end());
}
bool mailsystem::mailconstant() {}
bool mailsystem::mailvariable() {}
bool mailsystem::smtptester() {
    if (!prepareSMTPTesterFiles()) return false;
    fs::path filepath = fs::path(homedir) / "SMTP TESTER";
    std::ifstream read(filepath / "raw.txt");
    if (!read) return false;
    std::string data;
    std::set<std::string> localset;
    while (std::getline(read, data)) {
        if (data.empty()) continue;
        localset.insert(data);
    }
    (localset.size() > 10) ?
        std::cout << "[INF] " << localset.size()
        << " SMTP ON FILE\nUSE MULTIPLE THREADS FOR SPEED\n" :
        std::cout << "[INF] " << localset.size() << " SMTP ON FILE\n";
    size_t maxThreads = std::thread::hardware_concurrency();
    delay(3);
    clearConsole();
    std::cout << "[INF] YOUR DEVICE HAS TOTAL NUMBER OF " << maxThreads << " THREADS\n";
    std::cout << "CHOOSE NUMBER OF THREADS TO USE (MIN 2, MAX)" << maxThreads - 1 << std::endl;
    size_t threads = 0;
    std::cin >> threads;
    threads = (threads < 2 || threads > maxThreads - 1) ? 2 : maxThreads / 2;
    size_t chunkSize = localset.size() / threads;
    std::unordered_set<std::string> results;
    std::mutex resultsMutex;

    return false;
}
bool mailsystem::extractor() {
    clearConsole();
    servicedisplay("EMAIL EXTRACTOR");
    if (!prepareExtractorFiles()) return false;
    fs::path filepath = fs::path(homedir) / "EXTRACTOR";
    std::ifstream read(filepath / "raw.txt", std::ios::binary);
    if (!read) return false;
    read.seekg(0, std::ios::end);
    size_t fileSize = static_cast<size_t>(read.tellg());
    read.seekg(0, std::ios::beg);
    std::string data(fileSize, '\0');
    read.read(&data[0], fileSize);
    read.close();
    size_t numThreads = 4;
    if (fileSize > 2 * 1024 * 1024) {
        size_t maxThreads = std::thread::hardware_concurrency();
        do {
            std::cout << "[INF] DATA SIZE FOUND IS ABOVE 2MB.\n[INF] MULTITHREADING IS RECOMMENDED.\n";
            std::cout << "[INF] YOUR CPU SUPPORTS UP TO " << maxThreads << " THREADS.\n";
            std::cout << "SPECIFY NUMBER OF THREADS (MIN 4, MAX " << maxThreads << "): ";
            std::cin >> numThreads;

            if (std::cin.fail() || numThreads < 4 || numThreads > maxThreads) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                clearConsole();
                std::cout << "INVALID INPUT. PLEASE ENTER BETWEEN 4 AND " << maxThreads << ".\n";
                delay(2);
                clearConsole();
                numThreads = 0;
            }

        } while (numThreads < 4 || numThreads > maxThreads);
    }
    servicedisplay("EMAIL EXTRACTOR");
    std::cout << "[INF] EMAIL EXTRACTOR RUNNING, USING " << numThreads << " THREADS...\n";
    size_t chunkSize = fileSize / numThreads;
    std::vector<std::thread> threads;
    std::unordered_set<std::string> results;
    std::mutex resultsMutex;
    for (size_t i = 0; i < numThreads; ++i) {
        size_t start = i * chunkSize;
        size_t end = (i == numThreads - 1) ? fileSize : (i + 1) * chunkSize;
        while (end < fileSize && data[end] != ' ' && data[end] != '\n') ++end;
        std::string chunk = data.substr(start, end - start);
        threads.emplace_back(&mailsystem::extract,
            this,
            chunk,
            std::ref(results));
    }
    for (auto& t : threads) t.join();
    std::ofstream write(filepath / "extracted.txt");
    if (!write) {
        std::cout << "[ERR] PROGRAM FAILED TO WRITE EXTRACTED RESULTS TO FILE.\n";
        delay(3);
        return false;
    }

    for (const auto& email : results) {
        write << email << "\n";
    }
    write.close();

    std::cout << "[INF] " << results.size() << " TOTAL EMAILS EXTRACTED SUCCESSFULLY.\n";
    delay(3);
    return true;
}
bool mailsystem::sorter() {
    if (!prepareSorterFiles()) return false;
    fs::path filepath = fs::path(homedir) / "SORTER";
    std::ifstream read(filepath / "raw.txt");
    std::ofstream write(filepath / "sorted.txt");
    if (!read || !write) return false;

    char choice;
    clearConsole();
    std::cout << "[INF] PLEASE MAKE SURE RAW FILE ISN'T EMPTY...\n";
    std::cout << "Sort alphabetically? (y/n): ";
    std::cin >> choice;

    bool alphabetical = (choice == 'y' || choice == 'Y');
    std::size_t total = 0, unique = 0;

    if (alphabetical) {
        std::set<std::string> lines;
        std::string line;
        while (std::getline(read, line)) {
            if (line.empty()) continue;
            ++total;
            lines.insert(line);
        }
        unique = lines.size();

        for (const auto& l : lines)
            write << l << '\n';
    }
    else if (choice == 'n' || choice == 'N') {
        std::unordered_set<std::string> lines;
        std::string line;
        while (std::getline(read, line)) {
            if (line.empty()) continue;
            ++total;
            lines.insert(line);
        }
        unique = lines.size();

        for (const auto& l : lines)
            write << l << '\n';
    }
    else {
        clearConsole();
        std::cout << "[ERR] INVALID CHOICE, PLEASE TRY AGAIN.\n";
        delay(2);
        return false;
    }
    clearConsole();
    std::cout << (total - unique) << "TOTAL DUPLICATES MERGED." << "\n";
    delay(4);
    return true;
}

