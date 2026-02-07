#pragma once

#include <string>
#include <windows.h>

// ============================================================================
// Registry Helper - Safe Windows Registry Operations
// ============================================================================

class RegistryHelper {
public:
    // Set a DWORD value in the registry
    static bool SetDWordValue(
        HKEY hKeyRoot,
        const std::string& subKey,
        const std::string& valueName,
        unsigned long value
    );

    // Read a DWORD value from the registry
    static bool GetDWordValue(
        HKEY hKeyRoot,
        const std::string& subKey,
        const std::string& valueName,
        unsigned long& outValue
    );

    // Check if a registry key exists
    static bool KeyExists(
        HKEY hKeyRoot,
        const std::string& subKey
    );
};
