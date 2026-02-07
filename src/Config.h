#pragma once

// ============================================================================
// Configuration & Constants
// ============================================================================

namespace Config {
    // Registry settings
    constexpr const char* REG_KEY_PATH = 
        R"(SOFTWARE\Microsoft\Windows NT\CurrentVersion\Image File Execution Options\VRChat.exe\PerfOptions)";
    constexpr const char* REG_VALUE_NAME = "CpuPriorityClass";

    // Application metadata
    constexpr const char* APP_TITLE = "VRChat Priority Setter";
    constexpr const char* APP_VERSION = "2.0";
    constexpr const char* AUTHOR = "Maggi";
    constexpr const char* GITHUB_REPO = "https://github.com/N0tMaggi/VRChat-Booster";

    // Priority levels (Windows API values)
    enum Priority : unsigned long {
        IDLE = 1,
        NORMAL = 2,
        HIGH = 3,
        REALTIME = 4,
        BELOW_NORMAL = 5,
        ABOVE_NORMAL = 6
    };
}

// ============================================================================
// ANSI Color Codes
// ============================================================================

namespace Color {
    constexpr const char* RESET   = "\033[0m";
    constexpr const char* BOLD    = "\033[1m";
    constexpr const char* CYAN    = "\033[36m";
    constexpr const char* YELLOW  = "\033[33m";
    constexpr const char* RED     = "\033[31m";
    constexpr const char* GREEN   = "\033[32m";
    constexpr const char* MAGENTA = "\033[35m";
    constexpr const char* BLUE    = "\033[34m";
    constexpr const char* WHITE   = "\033[37m";
    constexpr const char* GRAY    = "\033[90m";
}
