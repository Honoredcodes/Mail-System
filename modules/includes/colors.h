#ifndef GLOBAL_COLORS_H
#define GLOBAL_COLORS_H
#include <string>
struct Color {
    // Regular Colors
    static inline const std::string reset = "\033[0m";
    static inline const std::string black = "\033[30m";
    static inline const std::string red = "\033[31m";
    static inline const std::string green = "\033[32m";
    static inline const std::string yellow = "\033[33m";
    static inline const std::string blue = "\033[34m";
    static inline const std::string magenta = "\033[35m";
    static inline const std::string cyan = "\033[36m";
    static inline const std::string white = "\033[37m";

    // Bright Colors
    static inline const std::string brightBlack = "\033[90m";
    static inline const std::string brightRed = "\033[91m";
    static inline const std::string brightGreen = "\033[92m";
    static inline const std::string brightYellow = "\033[93m";
    static inline const std::string brightBlue = "\033[94m";
    static inline const std::string brightMagenta = "\033[95m";
    static inline const std::string brightCyan = "\033[96m";
    static inline const std::string brightWhite = "\033[97m";

    // Styles
    static inline const std::string bold = "\033[1m";
    static inline const std::string underline = "\033[4m";
    static inline const std::string reversed = "\033[7m";
};
#endif